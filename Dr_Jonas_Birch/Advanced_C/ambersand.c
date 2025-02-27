/* ambersand */
#include <stdio.h>

void addition(int *target, int a, int b) {
    

    *target = a + b; 

    return; 
}

int main() {

    int x, y, answer; 

    x = 5; 
    y = 15; 

    addition(&answer, x, y); 

    printf("%d\n", answer); 

    return 0; 

}

// when the addition function is called, the address of &answer is sent to the 1st argument(technically second since the function calls it's self or whatever)
// When a and b are added together the value is placed into *target, which is a reference to &answer
// no need to return the result since the program has already placed the result of a + b into answer