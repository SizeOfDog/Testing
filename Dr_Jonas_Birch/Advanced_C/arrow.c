/* arrow.c */
#include <ncurses.h>

int main() {
    int key, x, y; 

    initscr(); 
    keypad(stdscr, TRUE); // Repersents the keypad to the right of the keyboard
    noecho(); // disables what is typed on the keyboard
    x = y = 5; 

    
    while (key != 'q') {

        clear(); 

        move(0, 0); 
        printw("Press left or right arrow - exit by pressing: q"); 

        move(y, x); 

        printw("O"); 

        refresh(); 

        key = getch();  // get which key user pressed


        if (key == KEY_LEFT) {
            x--;  // if the left cursor is pressed, the cursor moves to the left
            if (x < 0) x=0; 
        } //KEY_LEFT is a 
        else if (key == KEY_RIGHT) {
            x++; // if the right cursor is selected the cursor moves to the right, simple :)
            if (x > 50) x = 50; 
        }
        // else if (key == KEY_DOWN) {
        //     y--; 
        // }
        // else if (key == KEY_UP) {
        //     y++; 
        // }

    }
    

}