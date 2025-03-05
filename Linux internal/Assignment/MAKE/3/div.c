#include<stdio.h>
int div(float a, float b) {
    if (b == 0) {
        printf("Error: Division by zero!\n");
        return 0; // Or handle the error appropriately
    }
    return a / b;
}
