/* functions.h */
#include <stdio.h>

int area_triangle(int b, int h) {
    int area; 

    area = (b * h) / 2 ; 

    return area; 
}

int main() {

    int b, h, a;  // List out variables at the top of the program , b is Base, h is height, a is area

    printf("Base: "); // using print f with a string without the new line character may not print out the string value at all ? 
    fflush(stdout);  // file descriptor stdout, pushes out whatever is in the buffer before clearning it ? 
    scanf("%d", &b); 

    printf("Height: "); 
    fflush(stdout); 
    scanf("%d", &h); 

    a = area_triangle(b, h); 
    printf("The area is %d\n", a); 

    return 0; 

}