#include <stdio.h>
#include <stdlib.h>
#include <math.h>

unsigned long long int factorial(int num);

int main(){
    int num;
    printf("****************************************\n");
    printf("* Welcome to the Factorial Calculator! *\n");
    printf("* Press <return> or <enter> to submit. *\n");
    printf("****************************************\n\n");
    printf("n! (factorial) |「n」を入力してください > ");
    scanf("%d", &num);
    
    if (num < 0) {
        printf("\nIncorrect input! Ensure that the number is an integer greater than or equal to zero.\n\n");
        return (0); }
    else {
        printf("The factorial of %d is %llu!\n", num, factorial(num));
        return(0); }

}

unsigned long long int
factorial(int num){
    /*  num as a counter for the amount of times it will execute:
        Pre: the entered number is an integer, and greater than zero
        Post: the program accounts for the factorial of 0 = 1;
    
    */
    int i = num;
    unsigned long long fact = 1; /*%llu is the longest integer type in C, 64 bits wide */

    while (i >= 1){
    /*
    uses decrement 5*4*3*2*1
    instead of 1*2*3*4*5
    */
    fact *= i;
    i--;
    }

    return(fact);
}