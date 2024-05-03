#include <stdio.h>
void main(){
    int i = 0, j = 0;
    for(;;){
        printf("<>");
    }

    /*
    
    for conditions (int i; i < 0; i++) 
    i++ increments after body is executed
    ex: 1 at start, 1 in loop, 2 after loop
    ++i increments at start of body
    ex: 1 at start, 2 in loop, 2 after loop
    
    */
    /*
    while (i <=4 && j <= 4)
    {
        i++;
        j++;
        printf("%d %d\n", i, j);
        
    }
    */
    /* 
    while (i+=2, i<=10){
        printf("%d ", i);
    }
    printf("%d\n", i);
    */
}