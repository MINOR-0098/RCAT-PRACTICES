#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c;
    scanf("%f %f %f",&a,&b,&c);
    printf("Root1= %f\n",((-b)+(sqrt(b*b-4*a*c)))/(2*a));
    printf("Root2= %f\n",((-b)-(sqrt(b*b-4*a*c)))/(2*a));
    return 0;
}