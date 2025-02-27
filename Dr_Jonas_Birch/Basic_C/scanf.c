/* scanf.c */

#include <stdio.h>
int main() {

    char name[32]; 
    int currentYear, yearBorn, age; 

    printf("What's your name ? \n");  // %s represents a string value when printing to the consol 
    scanf("%s", name); // take input from a user from the command line

    //printf("How old are you ? \n "); 
    //scanf("%d", &age);  // %d represents an integer when using printf to output information to the console
    printf("What is the current year?"); 
    scanf("%d", &currentYear); 

    printf("What year were you born ? "); 
    scanf("%d", &yearBorn); 

    age = currentYear - yearBorn; 

    printf("Hello %s, you're %d years old\n ", name, age);

    return 0; 
}