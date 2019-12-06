
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   for (; argc > 0; argc--) 
   {
      pid_t pid;
      pid = fork();
      if (pid > 0)  //for parent process 
      { 
         printf("PID is %d\n",pid); 
         while(1)
         {
         sleep(10);
         }
      }
      else if (pid == 0) //for child process
      {
         exit(1);
      }
    }
 return 0;
}