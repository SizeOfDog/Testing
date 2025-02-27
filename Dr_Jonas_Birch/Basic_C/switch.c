/* switch.c */
#include <stdio.h>
#include <string.h>

int main() {

    int x; 
    printf("Choose between 1. apples, 2. pears, 3. bananas\n"); 

    scanf("%d", &x); 

    // if ( x == 1)
    //     printf("Apples\n"); 
    // else if ( x == 2 )
    //     printf("Pears\n"); 
    // else if ( x == 3)
    //     printf("Bananas\n");
    // else
    //     printf("Something Else\n"); 

    switch (x) {
        case 1: 
          printf("Apples\n"); 
          break;
        case 2: 
          printf("Pears\n"); 
          break; 
        case 3: 
          printf("Bananas\n"); 
          break; 
        default: 
            printf("Something Else\n"); 
    }

    return 0;

}