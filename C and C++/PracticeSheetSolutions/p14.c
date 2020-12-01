#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;

    fp = fopen("generate.txt", "w");
    if (fp == NULL)
    {
        perror("Error");
    }

    char str_i[10];
    for (int i = 1; i <= 100; i++)
    {
        sprintf(str_i, "%d", i);
        strcat(str_i, " ");
        char sqr[6];
        sprintf(sqr, "%d", i * i);
        strcat(str_i, sqr);
        strcat(str_i, "\n");
        fwrite(str_i, 1, strlen(str_i), fp);
    }

    fclose(fp);

    return (0);
}