/* function_pointers.c */

#include <stdio.h>
#define F fflush(stdout); 

void addition(int *target, int a, int b) {
    *target = a + b; 
    return; 
}

void subtraction(int *target, int a, int b) {
    *target = a - b; 
    return; 
    
}

void division(int *target, int a, int b) {
    *target = a / b; 
    return; 
    
}

void multiplication(int *target, int a, int b) {
    *target = a * b; 
    return; 

}


int main() {

    int x, y, op, result; 
    void (*fp)(int*,int, int); // creating the function pointer

    printf("Press 1 for addition, 2 for subtraction, 3 for division, 4 for multiplication and 0 for quit: "); 
    scanf("%d", &op); 
    printf("Number 1: "); F; 
    scanf("%d", &x); 
    printf("Number 2: "); F; 
    scanf("%d", &y);

    switch (op) {
        case 1: /* this is for addition*/
            fp = addition; 
            break; 
        case 2: /* this is for subtraction*/
            fp = subtraction; 
            break; 
        case 3: /* this is for division*/
            fp = division; 
            break; 
        case 4: /* this is for multiplication*/
            fp = multiplication; 
            break; 
        default: 
            return 0; 
    }    

    (fp(&result, x, y)); // fp will be the pointer to whatever case is successful
    printf("The result is %d", result); 

    return 0; 
}

