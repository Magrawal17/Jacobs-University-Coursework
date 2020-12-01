/*
 CH-230-A
 a3_p9.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */

 #include <stdio.h>
 double sum25(double v[], int n);
 int main(){
     int n;
     double result;
     scanf("%d",&n);
     
     double v[20];
     for (int  i = 0; i < 20; i++)                         //initlaising the array so that it easier later on
     {
         v[i]= -1;
         
     }
     for (int  i = 0; i < n; i++)                       //taking in n values
     {
         scanf("%lf",&v[i]);
     }
     result= sum25(v,n);
     if (result != -111){                                  //checks validity of the postion
     printf("sum=%lf\n",result);
     }
     else
     {
         printf("One or both positions are invalid\n");
     }
     
     return 0;
 }
 double sum25(double v[], int n){              //function to add the value of position of 2 and 5
         if ((v[2]==-1)|| (v[5]==-1)){
         return -111;                          
         }
         else
         {
             return (v[2]+v[5]);
         }
     }
     
 