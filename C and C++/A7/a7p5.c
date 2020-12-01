/*
 CH-230-A
 a7_p5.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdlib.h>
#include <stdio.h>

int assc(const void *va ,const void * vb) 
{
    const int * a = (const int *) va ;
    const int * b = (const int *) vb ;
    if (* a < *b ) return -1;
    else if (* a > * b) return 1;
    else return 0;
}

int dessc(const void *va ,const void * vb) 
{
    const int * a = (const int *) va ;
    const int * b = (const int *) vb ;
    if (* a < *b ) return 1;
    else if (* a > * b) return -1;
    else return 0;
}

int main()
{
    int n=0;
    int *arr=NULL;
    char c;
    scanf("%d",&n);
    arr=(int*)malloc(sizeof(int)*n);
    if (arr == NULL)
    {
        exit(1);
    }
    for (int i=0;i < n; i++)
    {
        scanf("%d",&arr[i]);
    }
    getchar();
    do
    {
        scanf("%c",&c);
        getchar();
        switch (c)
        {
        case 'a':
            qsort (arr, n, sizeof(arr[0]),assc);
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
        case 'd':
            qsort (arr, n, sizeof(arr[0]),dessc);
            for(int i=0;i<n;i++)
            {
                printf("%d ",arr[i]);
            }
            printf("\n");
            break;
        default:
            c='e';
            break;
        }
    } while (c!='e');
    return 0;
}