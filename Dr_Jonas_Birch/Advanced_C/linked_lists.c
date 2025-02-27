/* linked_lists.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// the idea is that you want to dynamically allocate space for dynamically used strcutures, 
// I suppose one is created or instantiated with the *next pointer is called ? 

struct s_book { // create a book struct 
    char title[64];  // the title will contain 64 bytes, up to 64 characters
    int pages;   
    struct s_book *next;  // this next pointer will point to the next book instance in memory 
}; 
typedef struct s_book Book;  // a nickname for the struct s_book

Book *first; 
int numBooks; 

void addbook(char *title, int pages) {
    
    Book *p, *new; // create 2 pointers for the struct book, one for a new book and the other for current book ? 


    if (!first) {  // if the first pointer has no value execute this if statement
        p = malloc(sizeof(Book));   //  mutable allocation ??  Create a dynamic memory allocation for the current pointer
        memset(p, 0, sizeof(Book)); // zero out data before assigning it, if the memory is dynamic you don't want any leftover data
        numBooks++;  // Increase the number of books by 1 
        strncpy(p -> title, title, 63); // 
        p->pages = pages; 
        p->next = 0; 
        first = p;

        return; 
    }

    for (p=first; p->next; p++); 

    new = malloc(sizeof(Book)); 
    memset(new, 0, sizeof(Book)); 
    numBooks++; 
    strncpy(p -> title, title, 63);
    new->pages = pages; 
    new->next = 0; 

    p->next = new; 

    return;

}

void listbooks(char *searchstr) {
    Book *p; 

    for (p=first; p->next; p=p->next) {
        if (!searchstr || !strcmp(searchstr, p->title)); 
        printf("Pages: %d\t Title: '%s'\n", 
            p->pages, p->title
        ); 

    }
}

int main() {

    first = 0;  // for an array index the first book would be 0
    numBooks = 0; 

    addbook("The Bible", 3500); 
    // printf("%s\n", first->title); 

    addbook("Hello", 299); 
    // printf("%s\n", first->next->title); 

    listbooks("The Bible"); 

    return 0; 

}