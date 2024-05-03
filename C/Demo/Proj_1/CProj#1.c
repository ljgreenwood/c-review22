/* 
C Project # 1
Declare all variables at the top of the program and use the correct placeholder for each variable.
*/

// Prompts the user for: name, age, and salary of three employees.
// Scans/reads: name, age, and salary.
// Prints information (name, age, salary) of each employee in a separate line.
// note: age, and salary have different data types.

#include <stdio.h>
#include <string.h>
int main () 
    {
    int age[3], i = 0, j = 0;
    char name[3][50];
    double salary[3];
    for(i = 0; i < 3; i++)
        {
            printf("\n---------------------------------------\nEnter the name of employee %d: ", i+1); //prompt the to enter name
            scanf("%s", name[i]); //scan user’s input
            printf("\nEnter age of employee %d: ", i+1); //prompt the to enter age
            scanf("%d", &age[i]); //scan user’s input
            printf("\nEnter employee %d salary (numerical, without commas): $", i+1); //prompt the to enter salary
            scanf("%lf", &salary[i]); //scan user’s input
            printf("---------------------------------------\n"); //prompt the to enter name
        }
    for(j = 0; j < 3; j++)
        {
            //print Prints information (name, age, salary) of each employee in a separate line
            printf("The name of employee %d is: %s. They are %d years old, and their salary is $%.2f.\n", j+1, name[j], age[j], salary[j]);
        }
    return 0;
    }