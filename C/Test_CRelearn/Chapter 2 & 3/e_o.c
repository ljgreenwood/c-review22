#include <stdio.h>

/*
command line even or odd characters
add cases for when the input is invalid
*/
int main(int argc, char *argv[]){
    int enter = 0; 
        printf("\nEnter number > ");
        scanf("%d", &enter);
    if ((enter % 2) == 0)
        printf("\n%d is even.\n", enter);
    else
        printf("\n%d is odd.\n", enter);
    return (0);
}