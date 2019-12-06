#include <stdio.h>
#include <stdlib.h>
int main()
{
    double a;
    float b;
    int c;
    double result;
    double *r_ptr;

    scanf("%lf", &a);
    scanf("%f", &b);
    scanf("%d", &c);
    result = a + b + c;
    r_ptr = &result;
    *r_ptr += 5;

    printf("%lf %lf", result, *r_ptr);
    return 0;
}