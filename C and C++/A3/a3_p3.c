/*
 CH-230-A
 a2_p3.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
float convert(int cm);
int main()
{
    int cm;
    float km;
    scanf("%d", &cm);
    km = convert(cm);
    printf("Result of conversion: %lf\n", km);
    return 0;
}
float convert(int cm)
{
    return (cm / 100000.0);
}
