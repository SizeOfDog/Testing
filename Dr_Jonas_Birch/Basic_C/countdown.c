/* countdown.c */
#include <stdio.h>
#include <unistd.h>

int main() {
    int number; 
    number = 5; 

    // run program till value is less than 1 
    while(1) {

        printf("%d\n", number); 
        sleep(1); 
        number--; 

        if (number < 1) break; 
    } 

    return 0;

}