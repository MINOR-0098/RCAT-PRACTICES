#include<stdio.h>
int main()
{
int a = 125,b=12345;
long ax = 1234567890;
short s = 4043;
float x = 2.13459;
double dx = 1.1415927;
char c = 'W';
unsigned long ux = 2541567890;
 printf("a+c=%d",a+c);
 printf("\nx+c=%f",x+c );
 printf("\ndx+x=%f",dx+x);
 printf("\ndx+ ax=%ld",((int)dx)+ax);
printf("\na+x=%f",a+x);
printf("\ns+b=%d",s+b);
printf("\nax+b=%d",ax+b);
printf("\ns+c=%hd",s+c);
printf("\nax+c=%ld",ax+c);
printf("\nax+ux=%lu",ax+ux);
}