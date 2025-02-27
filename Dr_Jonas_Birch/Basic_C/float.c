// float.c
#include <stdio.h>

int main() {
    float pi, r, answer; 

    printf("What is the R in cm?\n "); 
    scanf("%f", &r); // %f represents a float variable when using printf to print output to the console

    pi = 3.14; 
    answer = r * r * pi; 

    printf("The area is %f\n", answer); 
    
    return 0; 
}