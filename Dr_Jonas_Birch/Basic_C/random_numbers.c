/* random_numbers.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int our_random_function(int max) {
    int x; 


    // random function built into the C library, allowing for random numbers to be generated
    x = rand() % max + 1; // if you don't add one to the max value you will get values from 0 - 9, this simulates numbers from 1 - 10 

    return x; 
}

int main() {
    int random; 

    srand(getpid());  // getpid gets the current process id and inputs it into the seed value for randomization

    random = our_random_function(10);
    printf("%d\n", random);

    return 0; 

}

// there are two different types of function, library functions and system calls

// if program fails to compile due to rand function not being referenced, ensure that the.. 
// correct library is imported for that function to be imported. 
// You can check the library needed for a function by running the "man rand" command in the terminal

// add a seed value to omit pseudo randomness 
// The value of the seed must be random everytime as well

// getpid will need another library to be utilized <unistd.h>
// if the man pages cannot find the getpid function, update or install the man pages again
// pacman -S man && pacman -S man-pages 