#include<stdio.h>
int main()
{
    int n1,n2,n3,n4,n5,n6,n7;
    printf("Enter ammount \n");
    scanf("%d",&n7);
    n1= n7/100;
    n2 = (n7-(n1*100))/50;
    n3 = (n7 - (n1*100) -(n2*50))/20;
    n4 = (n7 - (n1*100) -(n2*50)- (n3*20))/10;
    n5 = (n7 - (n1*100) -(n2*50)- (n3*20)-(n4*10))/5;
    n6 = (n7 - (n1*100) -(n2*50)- (n3*20)-(n4*10)-(n5*5))/2;
    n7 = (n7 - (n1*100) -(n2*50)- (n3*20)-(n4*10)-(n5*5)-(n6*2));

    printf("note of 100 = %d\n",n1);
    printf("note of 50 = %d\n",n2);
    printf("note of 20 = %d\n",n3);
    printf("note of 10 = %d\n",n4);
    printf("note of 5 = %d\n",n5);
    printf("note of 2 = %d\n",n6);
    printf("note of 1 = %d\n",n7);
    return 0;
}