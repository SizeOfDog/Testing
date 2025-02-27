/* fork.c */

#include <stdio.h>
#include <unistd.h>

int main() {

    int x; 
    FILE *fd; // Create a pointer in memory for the file first

    x = fork();  

    while (1) {

    fd = fopen("test.txt", "a");  // the fd variable contains the function to open a file called test.txt and the ability to append text to it
    fprintf(fd, "%d\n", x); // fprintf allows data to be written to file. I supposed the f in the front of the fucntion stand for file ??? 
    // fprintf(FILE pointer, value to write) ?

    fclose(fd); // close file, not sure if this has any significance comapres to python file.close()
    sleep(1); 
    }

    return 0; 
    
}

// forking is the concept of creating a second or multiple processes to run the same function. 
// The fork function only applies to the code after it. 
// Questions I have, why only 2 processes ? Did I miss that ? Can more be created ?
// The number that is used and displayed in the terminal is the process ID 