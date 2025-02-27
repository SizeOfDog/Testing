/* ncurses.c */

#include <ncurses.h> //alternative to the stdio library

int main() {

    char letter; 

    initscr(); // initialize window (or screen)
    printw("Press any key"); // print to window ? 
    refresh(); // changes to the screen won't take affect unless this is called

    letter = getch(); // capture the users input inside of the letter variable
    clear(); 

    printw("You pushed: '%c' ", letter); 
    refresh(); 

    getch(); 
    endwin(); // closes or destroys the window

    return 0; 

}

// ncurses are based off of windows, basically gives the ability to create windows ? For example a terminal

// install ncurses if not already installed (sudo pacman -S ncurses)

// compile the program with the linked libraries -ltinfo and -lncurses 
// you're linking the libraries to the program, telling the gcc to use these external libraries

// gcc ncurses.c -o ncurses  -ltinfo -lncurses
// ./ncurses