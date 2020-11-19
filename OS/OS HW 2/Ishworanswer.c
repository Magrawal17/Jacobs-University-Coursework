#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <getopt.h>

// igiri@jacobs-university.de


int status = EXIT_SUCCESS;

void work(char **args, int tflag)
{
    pid_t pid;
    pid = fork();

    if (pid < 0) 
    {
        fprintf(stderr, "forkfailed");
    }
    else if (pid == 0) //child
    {
        if (tflag == 1) //for printing actual code
        {
            for (int i = 0; args[i] != NULL; i++)
            {
                fprintf(stderr, "%s ", args[i]);
            }
            fprintf(stderr, "\n");
        }
        //execute command
        execvp(args[0], args);
        fprintf(stderr, "Unknown command\n");
        exit(EXIT_FAILURE);
    }
    else //parent
    {
        if (waitpid(pid, &status, 0) == -1)
        {
            fprintf(stderr, "wait pid failed");
        }
    }
}

int main(int argc, char *argv[])
{
    int nflag = 0;
    int tflag = 0;
    int nlines = 50; //default lines
    int option;
    while ((option = getopt(argc, argv, "n:t")) != -1)
    {
        switch (option)
        {
        case 'n':
            nflag = 1;
            if (atoi(optarg))
                nlines = atoi(optarg);
            break;
        case 't':
            tflag = 1;
            break;
        default:
            return -1;
        }
    }
    char *args[nlines + 2]; //args for execvp
    if (optind >= argc)     //if no command given
        args[0] = "/bin/echo";
    else //if option given
        args[0] = argv[optind];
    size_t len = 0; //for getline
    int n_read;     //for getline
    while (1)
    {
        int i;
        for (i = 1; i <= nlines; i++)
        {
            args[i] = NULL;
            if ((n_read = getline(&args[i], &len, stdin)) == -1)
            { //nothing more to read
                break; 
            } //removing new line
            args[i][strlen(args[i]) - 1] = '\0';
        }
        //remaining args to null
        for (int j = i; j <= nlines + 1; j++)
        {
            args[j] = NULL;
        }
        //calling actual function for fork and execvp
        work(args, tflag);

        if (n_read <= 0) 
        { //if nothing to read end
            break;
        }
    }
    return status;
}