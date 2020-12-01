/*
 CH-230-A
 a3_p5.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
 
 #include <stdio.h>
 int main (){
     char ch;
     int n,i;
     double sum,temp[100],fahr,mean;
     printf("Enter a character\n");
     scanf("%c",&ch);
     getchar();
     printf("How many times do you want this to run\n");
     scanf("%d",&n);
     for (i = 0; i < n; i++)
        {
         printf("Enter value ");
         scanf("%lf",&temp[i]);
         sum=sum + temp[i];                        //calculate the sum right here makes it easu
         }   
    switch (ch)     
        {
        case 's':
            printf("The sum is %lf\n",sum);       //result of sum
            break;
        case 'p':
            for (i = 0; i < n; i++)
                {
                printf("The temperature in celcuis of position %d of array is %lf\n",i,temp[i]);  //array prints all sum of temp
                }
            break;
        case 't':
            for (i = 0; i < n; i++)
                {
                fahr = ((9.0/5.0)*temp[i]) + 32.0;       //calucaltes everything in fahr
                printf("The temperature in fahrenheit of position %d of array is %lf\n",i,fahr);  //
                } 
            break;
        default:
            mean= sum/n;
            printf("The average is %lf\n",mean);    //calculates the average
            break;
        }
return 0;
 }