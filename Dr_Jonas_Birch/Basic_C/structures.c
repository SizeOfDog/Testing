/* structures.c */
#include <stdio.h>
#include <string.h>
// define structures outside of main 
// define variables inside of the structure

struct person {
    char title[8]; 
    char lastname[32];  
    int age; 
}; 

int main() {
    struct person hello; 

    strncpy(hello.title, "Sys", 3); 
    strncpy(hello.lastname, "Trelford", 8);
    hello.age = 28; 

    printf("%s  %s of the age %d\n", hello.title, hello.lastname, hello.age);  
}

//allocating blocks of memory of 8 (or 4 for older processes) is the reason why numbers like 8 or 32 are chosen over 10 or 30
