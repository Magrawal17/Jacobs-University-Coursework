
#include <time.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include <time.h>
#include <syslog.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <netdb.h>

#include "tcp.h"
#include <event2/event.h>

typedef struct info {
   // The char is of size 34 as the fortune return max of 32 chars
   char main_string[34];
   // This is the missing word from the sentence. 
   char blanked[34];
   int total_guess;
   int right_guess;
} client_deatils;

typedef struct node {
   // Current connection
   struct node *next;
   struct event *connection_event;
   int connection_fd;
   client_deatils *info;
   
} client;

int remove_client(client **front, int connection_fd);
client* add_new_client(client **front, int connection_fd);


static struct event_base *ebase;
static const char *progname = "word-game";
static client *my_connections = NULL;
char* seperator = " \r\n\t\v\f!~;_`.,-";
static void get_string(evutil_socket_t event_fd, short event_var, void *event_arg);
static void run_fortune(client* link);
static void send_to_client(client* link, int action);
static void read_from_client(evutil_socket_t event_fd, short event_var, void *event_arg);
static void connect_with_client(evutil_socket_t event_fd, short event_var, void *event_arg);

int main(int argc, char* argv[]){

   int fd;
   struct event *tev;
   // These are our hostnames by default if no host name is given NULL would work
   char* hostname[] = {"localhost", "::", NULL};
   if(argc != 2){
      fprintf(stderr, "Not enough arguments.\nUsuage : ./%s [port-number]\n", progname);
      exit(EXIT_FAILURE);
   }

   // Starting as a daemon service/process
   (void) daemon(0, 0);
   
   // We check this for zombie processes
   if(signal(SIGCHLD, SIG_IGN) == SIG_ERR){
      fprintf(stderr, "%s: signal() %s\n", progname, strerror(errno));
      exit(EXIT_FAILURE);
   }

   ebase = event_base_new();
   openlog(progname, LOG_PID, LOG_DAEMON);
   if(!ebase){
      syslog(LOG_ERR, "Error : Creation of base event failed\n");
      exit(EXIT_FAILURE);
   }

   for(int i = 0; hostname[i]; i++){
      fd = tcp_listen(hostname[i], argv[1]);
      if(fd < 0){
         fprintf(stderr, "error %s %s: Problem Listing to the connection \n", progname, strerror(errno));
      }
      tev = event_new(ebase, fd, EV_READ | EV_PERSIST, connect_with_client, NULL);
      event_add(tev, NULL);
   }
   // Event base loop
   if(event_base_loop(ebase, 0) == -1){
      syslog(LOG_ERR, " %s : Error in the event loop", progname);
      event_base_free(ebase);

      exit(EXIT_FAILURE);
   }

   closelog();
   event_base_free(ebase);

   return EXIT_SUCCESS;
}
// Function to make blanks lines replacing a word in a string/sentence.
static void make_blanks(client_deatils* current){
   char *pointer;
   char *token = NULL;
   int word_position, count;
   char temporary[64];

   pointer = current->main_string;

   // Counting the number of seperators
   while((pointer = strpbrk(pointer, seperator)) != NULL){
      pointer++;
      count++;
   }

   while(token == NULL){

      // Seeding the srand
      srand(time(0));
      word_position = rand()%count;
      count = 0;
      strcpy(temporary, current->main_string);
      token = strtok(temporary, seperator);
      while(token){

         if(count == word_position){
            pointer = strstr(current->main_string, token);
            if(!pointer){
               break;
            }
            // Setting the next word as ____
            memset(pointer, '_', strlen(token));
            strcpy(current->blanked, token);
            break;
         }
         count++;
         token = strtok(NULL, seperator);
      }
   }
}

// Function to get the contents out from the the fortune command
void get_string(evutil_socket_t event_fd, short event_var, void *event_arg){
   int fd = event_fd;
   int read_size, rc;
   client *current = (client*) event_arg;
   char buffer[64];

   // We read the size 32 because the run fortune is giving us 32 char string
   read_size = read(fd, buffer, 32);

   // If there is nothing in the file descriptor
   if(read_size < 0){
      fprintf(stderr, "%s: Read has failed %s\n", progname, strerror(errno));
      exit(EXIT_FAILURE);
   } else {
      // End the buffer with \0
      buffer[read_size] = '\0';

      strcpy(current->info->main_string, buffer);
   }

   make_blanks(current->info);
   send_to_client(current, 3);
}

void run_fortune(client* link){
   int fd[2];
   pid_t process_pid;
   struct event *fev;

   (void) pipe(fd);
   fev = event_new(ebase, fd[0], EV_READ, get_string, link);
   event_add(fev, NULL);

   process_pid = fork();
   if(process_pid == -1){
      /* Failed forking */
      syslog(LOG_ERR, "Forking process failed\n");
      link->info->main_string[0] = '\0';
   } else if(process_pid == 0){
      /* Child process */
      close(fd[0]);
      dup2(fd[1], STDOUT_FILENO);
      close(fd[1]);

      execlp("fortune", "fortune", "-n", "32", "-s", NULL);
      /* If it comes here then execution has failed */
      syslog(LOG_ERR, "Failed to execute the command Fortune\n");
      exit(EXIT_FAILURE);
   } else {
      /* We only need the read endpoint so we close the write */
      close(fd[1]);
   }
}

static void send_to_client(client* link, int action){
   char buffer[256];
   int read_size;
   
   switch (action) {
   case 0:
      strcpy(buffer,
      "Congratulation - Challenge passed!\n");
      break;
	case 1: 
      sprintf(buffer, 
      "Wrong guess - expected: %s\n", link->info->blanked);
      break;
	case 2: 
      sprintf(buffer, 
         "M: You mastered %d/%d challenges. Good bye!\n", 
         link->info->right_guess,
         link->info->total_guess);
      break;
	case 3:  
      sprintf(buffer, 
         "C: %s", 
         link->info->main_string); 
      break;
	default: 
   strcpy(buffer, 
      "Incorrect command or format\n"); 
   break;
}
   read_size = tcp_write(link->connection_fd, buffer, strlen(buffer));

   if(read_size < 0){
      fprintf(stderr, "%s: Write has failed %s\n", progname, strerror(errno));
      exit(EXIT_FAILURE);
   }
}

static void read_from_client(evutil_socket_t event_fd, short event_var, void *event_arg){
   int read_size;
   int rc;
   int fd = event_fd;
   client *current = (client*) event_arg;
   char buffer[264];
   char *guess;

   read_size = read(fd, buffer, sizeof(buffer));
   if(read_size < 0){
      fprintf(stderr, "%s: Read has failed: %s\n", progname, strerror(errno));
      exit(EXIT_FAILURE);
   }

   if(strstr(buffer, "Q:") == buffer){
      /* In case the user wants to quit */
      send_to_client(current, 2);
      event_free(current->connection_event);
      tcp_close(fd);
      remove_client(&my_connections, fd);
   } else {
      if(strstr(buffer, "R:") == buffer){
         /* Response from the user */
         current->info->total_guess++;
         memmove(buffer, buffer+2, strlen(buffer)-2);
         guess = strtok(buffer, seperator);
         if(guess == NULL || strcmp(guess, current->info->blanked) != 0){
            send_to_client(current, 1);
         } else {
            current->info->right_guess++;
            send_to_client(current, 0);
         }
         run_fortune(current);
      } else {
         /* Unrecognized command */
         send_to_client(current, 4);
      }
   }
}

static void connect_with_client(evutil_socket_t event_fd, short event_var, void *event_arg){
   size_t size;
   int fd;
   char display_text[256];
   client *new_conn;

   fd = tcp_accept((int)event_fd);
   if(fd < 0){
      fprintf(stderr, "%s: Could not connect with the client: %s\n", progname, strerror(errno));
      exit(EXIT_FAILURE);
   }
   strcpy(display_text, "M: Guess the missing ____!\n");
   strcat(display_text, "M: Send your guess in the form 'R: word\\r\\n'.\n");

   size = tcp_write(fd, display_text, strlen(display_text));
   if(size < 0){
      fprintf(stderr, "%s: %s Writing has failed\n", progname, display_text);
      tcp_close(fd);
      exit(EXIT_FAILURE);
   }

   new_conn = add_new_client(&my_connections, fd);
   new_conn->connection_event = event_new(ebase, fd, EV_READ | EV_PERSIST, read_from_client, new_conn);
   event_add(new_conn->connection_event, NULL);

   run_fortune(new_conn);
}

// To add the client to the list of client to the server 
client* add_new_client(client **front, int connection_fd){
   client *current_client = NULL;
   client_deatils *current_client_info = NULL;

   if(*front == NULL){
      *front = (client*) malloc(sizeof(client));
      if(*front == NULL){
         fprintf(stderr, "Error : Creating new connection client: %s", strerror(errno));
         exit(EXIT_FAILURE);
      }
      current_client = *front;
   } else {
      current_client = *front;
      while(current_client->next != NULL){
         current_client = current_client->next;
      }
      current_client->next = (client*) malloc(sizeof(client));
      current_client = current_client->next;
      current_client->next = NULL;
   }
   current_client->connection_fd = connection_fd;
   current_client->connection_event = NULL;
   current_client->info = (client_deatils*) malloc(sizeof(client_deatils));

   current_client_info = current_client->info;

   // Setting the intials variables for new connection
   current_client_info->total_guess = 0;
   current_client_info->right_guess = 0;
   current_client_info->main_string[0] = '\0';
   current_client_info->blanked[0] = '\0';

   return current_client;
}

// To remove the client from the list of client to the server 
int remove_client(client **front, int connection_fd){
   client *current_client = NULL;
   if(*front == NULL){
      fprintf(stderr, "Error : The client list is already empty.\n");
      return EXIT_FAILURE;
   }

   current_client = *front;
   if(current_client->connection_fd == connection_fd){
      *front = ((*front)->next) ? (*front)->next : NULL;
      event_free(current_client->connection_event);
      free(current_client);
      return EXIT_SUCCESS;
   }

   while(current_client->next != NULL){
      if(current_client->next->connection_fd == connection_fd){
         client* tmp = current_client->next;
         current_client->next = (current_client->next->next) ? current_client->next->next : NULL;
         event_free(tmp->connection_event);
         free(tmp);
         break;
      }
      current_client = current_client->next;
   }

   return EXIT_SUCCESS;
}
