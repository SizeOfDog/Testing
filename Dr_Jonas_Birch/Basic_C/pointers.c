/* pointers.c */
#include <stdio.h>
#include <string.h>

// used to point to another variable in memory
// similar to a shortcut in file explorer, you're referencing another location in your file directory

int main() {
    char str[32]; 
    char *p; // astrix infront of initialized pointers

    strncpy(str, "I like grapes", 31); 
    p = str; 

    //p = p + 1;  //start at the next char in memory 
    printf("%c \n", *p); // print out the first character of value referenced
    printf("%s \n", p); //print out the value of the variable referenced

    return 0; 
}

// pointers are useful for formatting strings