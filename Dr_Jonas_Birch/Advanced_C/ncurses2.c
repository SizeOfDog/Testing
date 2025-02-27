/* ncurses.c */
#include <ncurses.h>

int main() {
    
    int x, y; 

    initscr(); 
    clear(); 

    getyx(stdscr, y, x ); // locates the position of the screen, the x and y coordinates
    printw("x = %d\n", x); 
    printw("y = %d,\n", y);

    refresh(); 

    y = 5; 
    x = 10; 

    refresh(); 
    move(y, x); // Move the output or the current cursor on the window (In this case the terminal to the) to the new plots of x and y 
    printw("Over here ? "); 
    refresh(); 

    getch();  // after user enters a character, the program with close
    endwin();

    return 0; 


}