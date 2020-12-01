/*
 CH-230-A
 a4_p10.c
 Mahiem Agrawal
 m.agrawal@jacobs-university.de
 */
 #include <stdio.h>
 #include <math.h>

void proddivpowinv(float a, float b, float *prod, float *div,
    float *pwr, float *invb){
    *prod=a*b;
    *div=a/b;
    *pwr= powf(a,b);
    *invb=1.0/b;
}

int main(){
    float a,b,product,division,power,inverse; 
    float *prod,*div,*pwr,*invb;
    printf("Input a number ");
    scanf("%f",&a);
    printf("Input a number ");
    scanf("%f",&b);
    prod=&product;
    div=&division;
    pwr=&power;
    invb=&inverse;
    proddivpowinv(a,b,prod,div,pwr,invb);
    printf("The product is %f\n",product);
    printf("The divison is %f\n",division);
    printf("The power of a to b is %f\n",power);
    printf("The inverse of  b is %f\n",inverse);
    return 0;
}
