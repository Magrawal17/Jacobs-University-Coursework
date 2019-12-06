/*
 CH-230-A
 a5_p5.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
#include <stdlib.h>

void product(double *v,double *w,int n);

void pos(double *v,int n)
{
    float max,max1;
    max= *v;
    max1= *v;
    int pos,posi;  
    for (int i=0; i < n;i++)
    {
        if (v[i] < max)
        {
            max= v[i];
            pos=i;
        }
    }
    printf("The smallest = %lf\n",max);
    printf("Position of smallest = %d\n",pos);
    for (int i=0; i < n;i++)
    {
        if (v[i] > max1)
        {
            max1= v[i];
            posi=i;
        }
    }
    printf("The largest = %lf\n",max1);
    printf("Position of largest = %d\n",posi);
}

int main()
{
    double *v;
    double *w;
    int n;
    scanf("%d",&n);
    v= (double*) malloc(sizeof(double)* n);
    w= (double*) malloc(sizeof(double)* n);
    for (int i=0;i < n; i++)
    {
        scanf("%lf",&v[i]);
    }
    for (int i=0;i < n; i++)
    {
        scanf("%lf",& w[i] );
    }
    product(v,w,n);
    pos(v,n);
    pos(w,n);
    return 0;
}

void product(double *v,double *w,int n)
{
    double prod;
    for (int i = 0; i < n; i++)
    {
    prod= prod + ( v[i] * w[i] );
    }
    printf("Scalar product=%lf\n",prod);
}