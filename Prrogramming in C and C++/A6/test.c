#include<stdio.h>
#include <stdio.h>
#include<stdlib.h>
void divby5(float arr[], int size);

int main()
{	
int n;
scanf("%d",&n);
float *ptr;
ptr=(float*) malloc(sizeof(float)*n);
if(ptr==NULL)
    {
	exit(1);
    }
else
    {
    for(int i=0;i<n;i++)
    {
    	scanf("%f",(ptr+i));
    }
    printf("before:\n");	
	for(int i=0;i<n;i++)
	{
        printf("%f ",*(ptr+i));
    }
	divby5(ptr,n);	
	free(ptr);
    }
return 0;				
}

void divby5(float arr[],int size)
{
	int i;
	printf("\nAfter:\n");
	for(i=0;i<size;i++)
    {
    	*(arr+i)=*(arr+i)/5.0;
	    printf("%f ",*(arr+i));
    }
}