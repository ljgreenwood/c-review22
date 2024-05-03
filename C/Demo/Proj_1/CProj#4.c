/* 
C Project # 4
Declare all variables at the top of the program and use the correct placeholder for each variable.
*/

//Declares a variable and a pointer and assigns a value (between 1-99) to the variable .
//Assigns the address of the variable to the pointer.
//Prints the address of the pointer and the value stored.
//Changes the value of the variable.
//Prints the address and the value of the pointer.

#include <stdio.h>
#include <string.h>
    int main ()
    {
    int *pointer = 0, variable = 10; //Declares a variable and a pointer and assigns a value (between 1-99) to the variable .
    pointer = &variable; //Assigns the address of the variable to the pointer
    printf("The variable's address is: %p and the value stored is: %d\n\nEnter new variable: ", (void*)&pointer, *pointer); //Prints the address of the variable and the value stored
    scanf("%d", &variable); // Changes the value of the variable
    printf("The variable's address is: %p and the value stored is: %d\n\n", (void*)&pointer, *pointer); //Prints the address and the value of the variable
    return 0;
    }