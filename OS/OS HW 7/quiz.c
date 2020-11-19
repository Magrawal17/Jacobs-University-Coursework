#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <syslog.h>
#include <curl/curl.h>
#include <signal.h>

char *readall(int fd)
{
    char *buffer;
    buffer = (char *)malloc(4096 * sizeof(char)); //default size of directories so used it here
    if (buffer == NULL)
    {
        perror("couldn't allocate memory");
    }
    while (read(fd, buffer, 4096) != 0)
    {
    }
    return buffer;
}

char *fetch()
{
    char *buffer=NULL;
    int fd[2];
    if (pipe(fd) == -1)
    {
        perror("Error in making a pipe");
    }

    pid_t pid = fork();
    if (pid == -1)
    {
        perror("Error forking");
    }

    char **arglist;
    arglist = (char **)malloc(4 * sizeof(char *));
    arglist[0] = "curl";
    arglist[1] = "-s";

    arglist[2] = "http://numbersapi.com/random/math?min=1&max=100&fragment&json";
    arglist[3] = NULL;
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execvp(arglist[0], arglist);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        buffer = readall(fd[0]);
        close(fd[0]);
    }
    return buffer;
}

char *json_parser_question(char *json)
{
    char *ptr = json;
    char *question = malloc(1000);
    char *end = json;
    ptr = strstr(ptr, "\"text\":");
    ptr += 9;
    end = strstr(ptr, "\"number");
    end -= 4;
    memcpy(question, ptr, end - ptr);

    return question;
}

long json_parser_answer(char *json)
{
    char *ptr = json;
    long answer;
    ptr = strstr(ptr, "\"number\":");
    ptr += 10;
    answer = strtol(ptr, &ptr, 10);

    return answer;
}

unsigned play(unsigned n, unsigned score, char *text, long answer)
{
    printf("Q%u: What is %s?\n", n, text);

    unsigned startscore = 8;
    int
    try = 4;
    int choose;
    while (startscore != 0)
    {
        printf("%d pt> ", startscore);
        if (scanf("%d", &choose) == EOF)
        {
            printf("EOF");
            exit(1);
        };
        try--;
        if (choose < answer)
        {
            printf("Too low, try again\n");
            startscore = startscore / 2;
        }
        else if (choose > answer)
        {
            printf("Too high, try again\n");
            startscore = startscore / 2;
        }
        else
        {
            score = startscore + score;
            printf("Congratulations, your answer %d is correct.\n", choose);
            break;
        }
    }
    if (try==0){
        printf("The correct answer is %ld\n",answer);
    }
    printf("Your total score is %d/%d\n", score, n * 8);
    printf("\n");
    return score;
}

int main()
{
    int score = 0;
    int question_num = 1;
    char *json;
    char *question;
    long answer = 0;
    while (1)
    {
        json = fetch();
        printf("\n");
        question = json_parser_question(json);
      //  printf("%s\n", question);
        answer = json_parser_answer(json);
       // printf("%ld\n", answer);
        score = play(question_num, score, question, answer);
        question_num++;
    }
    return 0;
}