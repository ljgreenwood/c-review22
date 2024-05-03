#include <stdio.h>

/* pointers */
int main(){
    int x = 42; // initialize and declare integer
    int *ptr2 = &x; //in one line

    printf("Value of x from x: %d -- Address of x from x: %p\n", x, &x); // read in ptr using %p and &
    printf("Address of x from ptr: %p -- Value of x from ptr: %d\n", ptr2, *ptr2); // read in integer with %d using *

    return 0;
}