/*
 CH-230-A
 a3_p6.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
float to_pounds(int kg,int g);                       // Function initilaization
int main(){
int kg;
scanf("%d",&kg);                                       //Enter weight in kg
int g;
scanf("%d",&g);                                      //Enter weight in g
float pound;
pound = to_pounds(kg,g);                             // Function called and value stored in pound
printf("Result of conversion: %lf\n",pound);            
return 0;
}
float to_pounds(int kg,int g)                        //Code of the function supplying value g and kg and returning conversion
{    
    float result;
    result= ((kg+ (g/1000.0)) *2.2);
    return result;
}
