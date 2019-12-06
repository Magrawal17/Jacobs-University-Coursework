
 /*
 
 
CH-230-A
 
a1_p1.c
 
Mahiem Agrawal
 
m.agrawal@jacobs-university.de
 
 
*/
 
 
#include <stdio.h>
 
int main() {
 
    double result; /*The result of our calculation*/
 
    result= (3.0+1.0)/5.0;
 
printf("The value of 4/5 is %lf\n", result);
 
    return 0;
 
}
 
 /*The result is 0.0000 as the numbers here have been initially defined as integers without the decimal notation.
  This causes there to be a problem between integer and floating number addition.The computer fails to recognize 
   this however when you add the decimal point the problem is solved.*/;
