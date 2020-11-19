#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
    int n, call = -1;
    while ((n = getopt(argc, argv, "lsp")) != -1)
    {
        if (n == 's')
        {
            call = 1;
        }
        else if (n == 'p')
        {
            call = 2;
        }
        else
        {
            call = 3;
        }
    }
    if (call == -1)
    {
        exit(1);
    }
    char ch;
    if (call == 1)
    {
        //System call
        ssize_t sc;
        int inputfile;
        int outputfile;
        inputfile = open("Hello.txt", O_RDONLY);
        outputfile = open("/dev/null", O_WRONLY);
        while ((sc = read(inputfile, &ch, 1)) > 0)
        {
            sc = write(outputfile, &ch, 1);
            if (sc < 0)
            {
                exit(1);
            }
        }
    }
    else if (call == 2)
    {
        //Linux call
        ssize_t lc;
        int inputfile;
        int outputfile;
        int storage = 1048576;
        inputfile = open("Hello.txt", O_RDONLY);
        outputfile = open("/dev/null", O_WRONLY);
        while ((lc = sendfile(outputfile, inputfile, 0, storage)) > 0)
        {
            if (lc < 0)
            {
                exit(1);
            }
        }
    }
    else
    {
        //Library Call
        FILE *inputfile;
        FILE *outputfile;
        inputfile = fopen("Hello.txt", "r");
        outputfile = fopen("/dev/null", "w");
        while ((ch = getc(inputfile)) != EOF)
        {
            if (putc(ch, outputfile) == EOF)
            {
                exit(1);
            }
        }   
    }
    return 0;
}