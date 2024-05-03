#include <stdio.h>
/*
Data Types
int, char, float, double, void, string? (char[]), global
*/
int main(void){

    int int_var = 5;
    char char_var = 'a';
    float float_var = 3.141592;
    double double_var = 3.14159;
    char string_var[12] = "Hello World\n";
    
    /*
    Print statements --> others:
    %ld or %li - long int
    %x - hex
    */  

    printf("int_var = %d \n", int_var); // %d or %i
    printf("int_var = %i \n", int_var); // %d or %i
    printf("char_var = %c \n", char_var); // %c
    printf("float_var = %f \n", float_var); // %f
    printf("double_var = %lf \n", double_var); // %lf or %g
    printf("double_var = %g \n", double_var); // %lf or %g
    printf("string_var = %s \n", string_var); // %lf or %g

    scanf("%d%f%g", &int_var, &float_var, &double_var);
    scanf("%s", string_var);

    printf("new int_var = %d \n", int_var); // print new values
    printf("new float_var = %f \n", float_var); // print new values
    printf("new double_var = %lf \n", double_var); // print new values
    printf("new string_var = %s \n", string_var); // %lf or %g

    return 0;
}

/* control structs */
int main(void){
    printf("global_var = %d \n", global_var); // %lf or %g
    int num;
    scanf("%d", num);
    // if
    if (num == 1){
        printf("Number is 1\n");
    } else if (num == 2){
        printf("Number is 2\n");
    } else {
        printf("Number is not 1 or 2\n");
    }
    // switch
    switch (num){
        case 1:
            printf("Number is 1\n");
            break;
        case 2:
            printf("Number is 2\n");
            break;
        default:
            printf("Number is not 1 or 2\n");
            break;
    }
    return 0;
}

/* loops */
int main(void){
    int i;

    //for loop
    for (i = 0; i <= 5; i++){

    }
    //while loop
    while (i <= 5){
        puts("iteration %d", i);
        i++;
    }
    //do-while
    do
    {
        puts("iteration %d", i);
        i++;
    } while (i < 5);
    
    return 0;
}

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

/* end */