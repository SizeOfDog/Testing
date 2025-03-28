/* dice1.c */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int my_random(int max) {
    int x; 

    x = rand() %  max + 1; 

    return x; 
}

int main() {

    int balance, bet, guess, dice; 
    balance = 1000; 


    while (bet != 0) {

        srand(getpid());  // srand is used to increase the randomness of the number generated by the my_random function

        printf("Please make a bet: \n");  // User enters the amount of money they want to bet with
        scanf("$%d", &bet); 

        printf("Make your guess (1-6 and 0 means quit):\n"); // User can make a guess from 1 - 6, if the value is zero the user exits the program
        scanf("%d", &guess); 

        if (guess == 0) return 0;  // Exit the game if the guess is zerp

        sleep(2);  // Freeze the program for 2 seconds 
        dice = my_random(6);  // the max value the dice can be

        printf("%d\n", dice);  

        if (guess != dice) { // if the users guess is not the same as the randomly generated value, subtract the value bet from the balance
            balance -= bet; 
            printf("You lost, your new balance is $%d\n ", balance); 
        }
        else { // if the user guesses correctly multiply the bet by 3 and add it to their current balance
            bet *= 3; 
            balance += bet; 
            printf("You've made  $%d , your new balance is $%d \n", bet, balance); 
        }

        if (balance <= 0) {
            printf("GAME OVER\n ");
            break; 
        }

    }

    return 0; 

}