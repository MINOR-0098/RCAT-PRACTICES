#include<stdio.h>
int main()
{
    int a,b,c,large;
    printf("enter 3 numbers \n");
    scanf("%d %d %d",&a,&b,&c);
    if(a>b&&a>c)
    {
        printf("Maximum is %d",a);
    }
     if(b>a&&b>c)
    {
        printf("Maximum is %d",b);
    }
     if(c>b&&c>a)
    {
        printf("Maximum is %d",c);
    }

    return 0;


}