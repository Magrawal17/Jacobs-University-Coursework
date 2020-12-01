/*
 CH-230-A
 a3_p1.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
int main()
{
    float x;
    scanf("%f", &x);
    int i, n;
    do
    {
        scanf("%d", &n);
        if ((n <= 0))
        { // does the validation here
            printf("Input is invalid, reenter value\n");
        }
    } while (n <= 0);
    for (i = 1; i <= n; i++)
    {
        printf("%f\n", x); // prints it number of times required
    }
    return 0;
}
