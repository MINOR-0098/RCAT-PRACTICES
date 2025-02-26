#include<stdio.h>
#include<math.h>
int main(){
int x1=25,y1=15,x2=35,y2=10;
int temp = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
printf("Distance between the said points: %f",sqrt(temp));
return 0;
}