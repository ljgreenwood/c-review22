/* 
C Project # 2
Declare all variables at the top of the program and use the correct placeholder for each variable.
*/

// Prompts the user for six numbers.
// Scans/reads those numbers.
// Calculates: minimum, maximum, average, and sum of those numbers.
// Prints results on the screen.

#include <stdio.h>
#include <string.h>
int main ()
    {
    int numbers[6], i = 0, sum = 0, minimum = 0, maximum = 0;
    double average = 0;
    for(i = 0; i < 6; i++)
        {
        printf("\nEnter number %d: ", i+1);   //prompt to enter a number
        scanf("%d", &numbers[i]);  //scan the number
        }
    
    for(i = 0; i < 6; i++)
        {
            sum += numbers[i];  //sum computation (loop)
        }
    average = (double)sum / 6;;    //average computation (line)
    
    minimum = maximum = numbers[0];  //reset min/max to first value in entered array
    for (i = 0; i < 6; i++) //compute min/max
        {
        if (numbers[i] < minimum)
            {
            minimum = numbers[i];
            }
        if (numbers[i] > maximum)
            {
            maximum = numbers[i];
            }
        }
    printf("\nFor the entered array, the sum is %d, the average is %lf, the minimum is %d, and the maximum is %d.", sum, average, minimum, maximum); //print stats
    return 0;
    }