#include<stdio.h>
int main()
{
    int day,month,year;
    printf("Enter days \n");
    scanf("%d",&day);
    year= day/365;
    month = (day-(year*365))/30;
    day = day - (year*365) -(month*30);
    printf("year= %d\n",year);
    printf("month=%d\n",month);
    printf("days=%d\n",day);
    return 0;
}