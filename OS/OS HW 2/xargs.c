#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <sys/wait.h>
#include <errno.h>

void print_helper(int argc, char **argv, char *command, int tcase, int count); //for the n- specified print

int main(int argc, char *argv[])
{
    char *line;
    char command[64];
    size_t line_size = 0;
    ssize_t read;
    int opt;
    int ncase = 0;
    int tcase = 0;
    int jcase = 0;
    int basecase = 0;

    while ((opt = getopt(argc, argv, "ntj")) != -1)
    {
        switch (opt)
        {
        case 'n':
            ncase = 1;
            break;
        case 't':
            tcase = 1;
            break;
        case 'j':
            jcase = 1;
            break;
            //too hard could not solve it all however would love the solution
        }
    }

    int n;
    int extra = 0;
    int argvpos = 1; //this needs to be one to start argv[1] from 1

    for (; optind < argc; optind++) //takes in all extra arguemnts other than -t or -n
    {                               //for example the 1 and printf in (seq 1 4 | xargs -t -n 1 printf "foo-%02d\n")
        extra++;
        if (ncase == 1 && extra == 1)
        {
            char *temp;
            temp = argv[optind]; //extracting the 3 from (seq 0 10 | xargs -n 3)
            n = atoi(temp);
        }
        else if ((extra == 2 && ncase == 1) || (ncase == 0 && extra == 1)) //xargs -t -n 1 printf "foo-%02d\n"
        {                                                                  //extracring the printf and storing it in argv[1]
            basecase = 1;
            argv[argvpos] = strdup(argv[optind]);
            argvpos++;
        }
        else
        {
            argv[argvpos] = strdup(argv[optind]);
            argvpos++;
        }
    }

    int len;
    int count = argvpos;
    int req_argc = argvpos;

    while ((read = getline(&line, &line_size, stdin) != -1))
    {
        len = strlen(line);
        if (line[len - 1] == '\n')
        {
            line[len - 1] = '\0';
        }
        argv[count] = strdup(line); //stdup doesnt cpy the address
        count++;
    }
    argv[count] = NULL;

    if (basecase == 0)
    {
        strcpy(command, "/bin/echo"); // (seq 0 10 | xargs)
    }
    else
    {
        strcpy(command, argv[1]); //seq 1 4 | xargs -t -n 1 printf "foo-%02d\n"
    }

    if (ncase == 0) //for cases such as (seq 0 10 | xargs -t) or (echo "hello world" | xargs)
    {
        print_helper(argc, argv, command, tcase, count);
    }
    else
    {
        int l;
        if (basecase == 1)
        {
            char **b = (char **)malloc(count); //making a 2d array for the case such as -n one
            for (int i = 0; i < count; i++)
            {
                b[i] = (char *)malloc(sizeof(char) * 10);
            }
            for (int i = req_argc; i < count; i = i + n)
            {
                b[0] = strdup(command);
                b[1] = strdup(argv[2]);
                for (l = 0; l < n && argv[l + i] != NULL; l++)
                {
                    b[l + 2] = strdup(argv[l + i]);
                }
                if (l != n)
                {
                    b[l + 1] = NULL;
                }
                b[n + req_argc - 1] = NULL;
                print_helper(argc, b, command, tcase, count);
            }
        }
        else
        {
            char **b = (char **)malloc(n + 2);
            for (int i = 0; i < n + 2; i++)
            {
                b[i] = (char *)malloc(sizeof(char) * 10);
            }
            for (int i = req_argc; i < count; i = i + n)
            {
                b[0] = strdup(command);
                for (l = 0; l < n && argv[l + i] != NULL; l++)
                {
                    b[l + 1] = strdup(argv[l + i]);
                }
                if (l != n)
                {
                    b[l + 1] = NULL;
                }
                b[n + 1] = NULL;
                print_helper(argc, b, command,tcase,count);
            }
        }
    }
    return 0;
}

void print_helper(int argc, char **argv, char *command, int tcase,int count)
{
    pid_t pid;
    int status;
    if (tcase == 1)
    {
        fprintf(stderr, "%s ", command); //to print out /bin/echo 0 1 2 3 4 5 6 7 8 9 10
        for (int i = 1; i < count; i++)
        {
            fprintf(stderr, "%s ", argv[i]);
        }
        printf("\n");
    }

    pid = fork(); //referenced from lecture notes see there properly later
    if (pid == -1)
    {
        fprintf(stderr, "%s: for: %s\n", argv[0], strerror(errno));
        //continue;
    }

    if (pid == 0)
    {
        if (strcmp(command, argv[1]) == 0)
        {
            execvp(command, &argv[1]); //main execution takes place here
            fprintf(stderr, "%s :execvp: %s\n", argv[0], strerror(errno));
            _exit(EXIT_FAILURE);
        }
        else
        {
            execvp(command, &argv[0]);
            fprintf(stderr, "%s :execvp: %s\n", argv[0], strerror(errno));
            _exit(EXIT_FAILURE);
        }
    }
    else
    {
        if (waitpid(pid, &status, 0) == -1) //too make sure the parent waits till the child finishes it proccess.
        {
            fprintf(stderr, "%s:waitpid: %s\n", argv[0], strerror(errno));
        }
    }
}