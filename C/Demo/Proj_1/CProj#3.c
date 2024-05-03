/* 
C Project # 3
Declare all variables at the top of the program and use the correct placeholder for each variable.
*/

//Takes two names.
//Swaps the names.
//Prints the names before and after swapping.

#include <stdio.h>
#include <string.h>
int main ()
    {
    /*declare characters*/
    char name1[50];
    char name2[50];
    char temp[50];
    /*prompt for name 1 and scan it*/
    printf("\nEnter Name #1: "); 
    scanf("%s", name1);
    /*prompt for name 2 and scan it*/
    printf("\nEnter Name #2: "); 
    scanf("%s", name2);
    printf("\nName 1 before swapping is: %s, and Name 2 before swapping is %s.\n", name1, name2); //print name 1 and name 2 before swapping
    /*swap the names*/
    strcpy(temp, name1);
    strcpy(name1, name2);
    strcpy(name2, temp);
    printf("\nName 1 after swapping is: %s, and Name 2 after swapping is %s.\n\n", name1, name2); //print name 1 and name 2 after swapping
    return 0;
    }