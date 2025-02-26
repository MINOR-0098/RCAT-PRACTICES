#include<stdio.h>
int main()
{
    int sec,min,h;
    printf("Enter time in seconds \n");
    scanf("%d",&sec);
    h= sec/3600;
    min = (sec-(h*3600))/60;
    sec = sec - (h*3600) -(min*60);
    printf("hour= %d\n",h);
    printf("min=%d\n",min);
    printf("sec=%d\n",sec);
    return 0;
}