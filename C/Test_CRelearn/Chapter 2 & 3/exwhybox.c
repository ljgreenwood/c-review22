#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(){
    int x, y;
    printf("*****************************************\n");
    printf("*      Welcome to the Box Creator!      *\n");
    printf("*  Press <return> or <enter> to submit. *\n");
    printf("*****************************************\n\n");
    printf("x-side length を入力してください > ");
    scanf("%d", &x);
    printf("\ny-side length を入力してください > ");
    scanf("%d", &y);

    for (int j = 0; j < y; j++)
    {
        for (int i = 0; i < x; i++)
        {
            printf("*");
        }
        printf("\n");
    }

}