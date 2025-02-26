/*
Write a C program to compute the perimeter and area of a rectangle with a height
of 7 inches. and width of 5 inches.
*/

#include<stdio.h>
int main()
{
    int a=0 ;
    int b=0 ;
    printf("Enter Height of rectangle ");
    scanf("%d",&a);
    printf("Enter width of rectangle ");
    scanf("%d",&b);
    int p = 2*(a+b);
    int a1 = a*b;

    printf("\nPerimeter of the rectangle = %d inches",p);
    printf("\nArea of the rectangle = %d square inches",a1);
    return 0;
}