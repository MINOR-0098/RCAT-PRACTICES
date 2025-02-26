#include<stdio.h>
int main()
{
    float w1,w2,n1,n2,avg;
    printf("Enter Weight of item1: ");
    scanf("%f",&w1);
    printf("Enter quantity of item1: ");
    scanf("%f",&n1);
    printf("Enter Weight of item2: ");
    scanf("%f",&w2);
    printf("Enter quantity of item2: ");
    scanf("%f",&n2);
    avg = ((w1*n1)+(w2*n2))/(n1+n2);
    printf("average valus = %f",avg);

    return 0;
}