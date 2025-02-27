// ifstatements.c 

#include <stdio.h>

int main() {
    int speed; 

    printf("How fast are you driving (km/h)? \n"); 

    scanf("%d", &speed);

    if (speed > 100) {
        printf("You're driving too fast\n"); 
    }
    else if (speed > 80 && speed < 100) {
        printf(" You're driving at a reasonable speed\n"); 
    }
    else {
        printf("You're driving too slow\n");
    }

    return 0; 
}
