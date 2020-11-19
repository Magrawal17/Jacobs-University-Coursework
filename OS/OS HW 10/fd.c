#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <string.h>
#include <getopt.h>
#include <sys/stat.h>
#include <fnmatch.h>
#include <limits.h>
#include <stdio.h>


#define S_IFDIR 0040000 
#define S_IFREG 0100000


void path_and_pattern(char *path, char *pattern);
void path_and_pattern_flag(char *path, char *pattern, mode_t flag);


int main(int argc, char **argv)
{
    int e_flag = 0;
    int d_flag = 0;
    int f_flag = 0;
    int l_flag = 0;
    int s_flag = 0;
    int p_flag = 0;
    int x_flag = 0;
    int tflag = 0;
    char path[256];
    char pattern[256];
    char option;
    int counter = 0;
    int pathpatern=0;

    while ((option = getopt(argc, argv, "t:")) != -1)
    {
        tflag = 1;
        switch (optarg[0])
        {
        case 'f':
            printf("Regular file being searched for\n");
            f_flag = 1;
            break;
        case 'd':
            printf("Directory being searched for\n");
            d_flag = 1;
            break;
        case 'l':
            printf("Symbolic being searched for\n");
            l_flag = 1;
            break;
        case 'p':
            printf("Pipes being searched for\n");
            p_flag = 1;
            break;
        case 's':
            printf("Sockets being searched for\n");
            s_flag = 1;
            break;
        case 'e':
            printf("Empty files being searched for\n");
            e_flag = 1;
        case 'x':
            printf("Executables being searched for\n");
            x_flag = 1;
            break;
        default:
            fprintf(stderr, "Invalid Input");
            break;
        }
    }
    
    if (tflag == 1)
    {
        counter = 3;
    }
    else
    {
        counter = 1;
    }
    for (int i = counter; i < argc; ++i)
    {
        if (strcmp(argv[i], "-t") != 0 && strcmp(argv[i - 1], "-t") != 0)
        {
            strcpy(pattern, argv[i]); //Major asumption that if a path is given there will always have to be a pattern orelse it is impossible
            if (argc > i + 1)
            {
                strcpy(path, argv[i + 1]);
            }
            else
            {
                strcpy(path, ".");
            }
            break;
        }
        else
        {
            strcpy(pattern, "*");
        }
        pathpatern=1;
    }
    if (argc == 1 || pathpatern==0)
    {
        strcpy(path, ".");
        strcpy(pattern, "*");
    }
    printf("Pattern is:%s\n", pattern);
    printf("Path is: %s\n", path);
    if (e_flag == 0 && d_flag == 0 && f_flag == 0 && l_flag == 0 && s_flag == 0 && p_flag == 0 && x_flag == 0)
    {
        path_and_pattern(path, pattern);
    }
    else
    {
        if (d_flag == 1)
        {
            path_and_pattern_flag(path, pattern, S_IFDIR);
        }
        if (f_flag == 1)
        {
            path_and_pattern_flag(path, pattern, S_IFREG);
        }
    }
}

void path_and_pattern(char *path, char *pattern)
{
    DIR *directory;
    struct dirent *file;
    char fullpath[256];
    directory = opendir(path);
    if (directory)
        while ((file = readdir(directory)) != NULL)
        {
            if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0)
            {
                strcpy(fullpath, path);
                strcat(fullpath, "/");
                strcat(fullpath, file->d_name);
                if (fnmatch(pattern, file->d_name, 0) == 0)
                {
                    printf("%s\n", fullpath);
                }
                path_and_pattern(fullpath, pattern);
            }
        }
    return;
    closedir(directory);
}


void path_and_pattern_flag(char *path, char *pattern,mode_t flag)
{
    DIR *directory;
    struct dirent *file;
    struct stat t_type;
    char fullpath[256];
    directory = opendir(path);
    if (directory)
        while ((file = readdir(directory)) != NULL)
        {
            if (strcmp(file->d_name, ".") != 0 && strcmp(file->d_name, "..") != 0)
            {
                  
                strcpy(fullpath, path);
                strcat(fullpath, "/");
                strcat(fullpath, file->d_name);
                stat(fullpath,&t_type);
                if((t_type.st_mode&S_IFMT)==flag)
                {
                if (fnmatch(pattern, file->d_name, 0) == 0)
                {
                    printf("%s\n", fullpath);
                }
                }
                path_and_pattern_flag(fullpath, pattern,flag);
            }
        }
    return;
    closedir(directory);
}

