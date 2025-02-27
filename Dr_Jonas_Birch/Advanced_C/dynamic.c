/* dynamic.c*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    char *name;
    name = malloc(32); // memory allocation, specified as 32 bytes 
    // char name[32] // static memory allocation

    printf("What is your name ?\n"); 
    // scanf("%s", &name); when using pointers and dynamic memory allocation remove ambersand
    scanf("%s", name);
    printf("Hello %s\n", name); 

    free(name); // Free the memory, this will allow it to be allocated again
    // this is important when creating complex programs that utilize large amounts of memory. 

    return 0; 
}

