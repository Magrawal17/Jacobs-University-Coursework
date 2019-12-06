/*
 CH-230-A
 a7_p6.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct person
{
    char name[30];
    int age;
};


void printlist(struct person *arr,int n);
void swap(struct person* a, struct person* b);
void bsort(struct person *arr,int n,int (*func)(struct person *arr,int i));
int agecompare(struct person*arr,int i) ;
int namecompare(struct person*arr,int i) ;

int main()
{
    int n;
    scanf("%d",&n);
    struct person *arr;
    arr=(struct person*)malloc(sizeof(struct person)*n);
    if (arr == NULL)
    {
        exit(1);
    }
    for (int i=0;i < n; i++)
    {
        scanf("%s",arr[i].name);
        scanf("%d",&arr[i].age);
    }
    printf("Printing with respect to name\n");
    bsort(arr,n,namecompare);
    printlist(arr,n);
    printf("Printing with respect to age\n");
    bsort(arr,n,agecompare);
    printlist(arr,n);
    return 0;
}

int agecompare(struct person*arr,int i) 
{
    if (arr[i-1].age >arr[i].age) 
        {
        return 1;
        }
    else if (arr[i-1].age==arr[i].age)
    {
        return namecompare(arr,i);
    }
    else
    {
        return 0;
    }
    
}

int namecompare(struct person*arr,int i) 
{
   if (strcmp(arr[i-1].name,arr[i].name)==0)
    {
        return agecompare(arr,i);
    }
    else if (strcmp(arr[i-1].name,arr[i].name)>0) 
        {
        return 1;
        }
    else
    {
        return 0;
    }
    
}

void printlist(struct person *arr,int n)
{
 for(int i=0;i < n;i++)
    {
        printf("{%s,",arr[i].name);
        printf(" %d}; ",arr[i].age);
    }
    printf("\n");
}


void swap(struct person* a, struct person* b) 
{ 
    struct person temp = *a; 
    *a = *b; 
    *b = temp; 
} 

void bsort(struct person *arr,int n,int (*func)(struct person *arr,int i))
{
    int bool;
    do
    {
        bool=0;
        for (int i = 1; i < n; i++)
        {
            if (func(arr,i) == 1)
            {
                swap(&arr[i-1],&arr[i]);
            }
            bool=1;
        }
        
    } while (bool==0);
}

