/* altermac.c */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>

typedef unsigned char int8; 
typedef unsigned short int int16; 
typedef unsigned int int32; 
typedef unsigned long int int64; 

struct s_mac {
    int64 addr:48; 
}
typedef struct s_mac Mac; 

Mac generatemac(void); 

int main(int, char**)

int main() {
    srand(getpid())
    
}