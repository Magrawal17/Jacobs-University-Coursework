/*
* catloop.c --
*/
#define _POSIX_C_SOURCE 201112L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
    int fd;
    pid_t pid;
    if (argc != 2)
    {
        fprintf(stderr, "catloop: missing 'file' argument\n");
        return EXIT_FAILURE;
    }
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        perror("catloop: open");
        return EXIT_FAILURE;
    }
    while (1)
    {
        pid = fork();
        if (pid == -1)
        {
            perror("catloop: fork");
            (void)close(fd);
            return EXIT_FAILURE;
        }
        if (pid == 0)
        {
            char c;
            (void)lseek(fd, 0, SEEK_SET);
            while (read(fd, &c, 1) == 1)
            {
                write(STDOUT_FILENO, &c, 1);
            }
            (void)close(fd);
            return EXIT_SUCCESS;
        }
        (void)waitpid(pid, NULL, 0);
        sleep(1);
    }
    (void)close(fd);
    return EXIT_SUCCESS;
}