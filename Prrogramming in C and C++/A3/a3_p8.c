/*
 CH-230-A
 a3_p8.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

#include <stdio.h>
float add(float val[],int i);
float aveg(float sum,int i);
int main(){
    float n,val[11],sum,avg;   // declared 11 as when you enter 10 numbers succesively for 2 programs there will be  an error
    int i;
    i=0;
    n=0.0;
    while (i <= 9){                  // condition to enter 10 numbers 
        printf("Enter a number ");
        scanf("%f",&n);
          if (n== -99.0){            //break loop if -99.0 is entered
            break;
        }
          val[i]=n;
          i=i+1;
    } 
    sum= add(val,i);
    avg= aveg(sum,i);
    printf("The sum is %f\n",sum);
    printf("The average is %f\n",avg);
    return 0;
}
float add(float val[],int i){              //function to add the value of the arrays
    int sum = 0;
    for (int j = 0; j <= i ; j++)
    {
        sum= sum + val[j];                  //add up the elements of the array one by one
    }
    return sum;
}
float aveg(float sum,int i){             //fucntion to calcualte the average of the array
    int avg = 0;
    avg=(sum/i);                         // calcualte the average
    return avg;
}
        