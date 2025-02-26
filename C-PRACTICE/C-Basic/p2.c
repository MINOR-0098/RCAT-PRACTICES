#include<stdio.h>
int main()
{
    int days,week,year;
    printf("Enter number of days \n");
    scanf("%d",&days);
    year= days/365;
    week = (days-(year*365))/7;
    days = days - (year*365) -(week*7);
    printf("year= %d\n",year);
    printf("week=%d\n",week);
    printf("days=%d\n",days);
    return 0;
}