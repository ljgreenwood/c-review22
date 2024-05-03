#include <stdio.h>

/* pointers */
int main(){
    int x = 42; // initialize and declare integer
    int *ptr; //integer specific pointer (not directly assigned)
    ptr = &x; // assigns the address of x to the pointer "ptr"

    int *ptr2 = &x; //in one line

    printf("Value of x from x: %d -- Address of x from x: %p\n", x, &x);
    printf("Address of x from ptr: %p -- Value of x from ptr: %d\n", ptr, *ptr);

    return 0;
}
