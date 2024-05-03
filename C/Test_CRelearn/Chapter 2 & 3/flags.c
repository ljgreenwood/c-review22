#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void){
    /*
    continue reading in values and overwriting letter until a valid input, display %s is not within %s and %s 
    */
    int valid = 0; // init bool
    char letter, upper, lower; //character initialization
    printf("Input Lower Bound > ");
    scanf("%s", &lower);
    printf("\nInput Upper Bound > ");
    scanf("%s", &upper);
    
    while (!valid) /* while the range is invalid, continue to scan new inputs */{
        printf("\nEnter a letter %c through %c inclusive > ", lower, upper);
        scanf("%s", &letter);
        valid = (letter >= lower && letter <= upper); /*    condition is re-evaluated manually 
                                                            at the end of the statement. */
        if(!valid){
            printf("\n#####################################");
            printf("\n# Invalid. %c is not within %c and %c. #", letter, lower, upper);
            printf("\n#####################################\n");
        }
        else {
            printf("\n*****************************************");
            printf("\n* Valid! %c is within %c and %c inclusive! *", letter, lower, upper);
            printf("\n*****************************************\n\n");
        }
    }
    return (0);
}