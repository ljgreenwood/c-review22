// #include <stdlib.h>
#include <stdio.h>
// #include <math.h>

#define DEMAND_CHG  35.00
#define PER_100_CHG 1.10
#define LATE_CHG    2.00


void instruct();
/* displays user instructions */

double comp_use_charge(int previous0, int current0);
/* calculates the late_charge variable */

double comp_late_charge(double unpaid0);
/* calculates the late_charge variable */

double bill_fig();
/* calculate the bill given the inputs */

void display_bill(double late_charge0, double bill0, double unpaid0);
/* print the bill given  */

int main(){
   
    /*
    manipulate with set argument inputs from command
    line to make this a callable program in terminal
    */
    
    /*
    main() creates the water bill given subfunctions,
    also calls a function to retrive data from the user;
    */

    /* readings in thousands */
    int previous, /*input - previous quarter*/
        current; /*input - current meter reading*/
 
    double  unpaid, /*input - unpaid prior balance*/
            bill, /*output - water bill*/
            use_charge, /*charge for actual use*/
            late_charge; /*charge for nonpayment on unpaid*/

    /* call instruction display function */
    instruct();

    /* retrieve data from user */
    // unpaid balance, previous/current meter readings

    printf("Enter unpaid balance> $");
    scanf("%lf", &unpaid);
    printf("Enter previous meter reading> ");
    scanf("%d", &previous);
    printf("Enter current meter reading> ");
    scanf("%d", &current);

    /*  compute use charge:
        passes __ and __ variables as arguments */
    use_charge = comp_use_charge(previous, current);

    /*  compute late charge:
        passes __ and __ variables as arguments */
    late_charge = comp_late_charge(unpaid);

    bill = DEMAND_CHG + use_charge + unpaid + late_charge;
    display_bill(late_charge, bill, unpaid);
    return(0);
}

void
instruct(){
    /**/
    printf("This program figures a water bill based on the demand charge\n");
    printf("($%.2f) and a $%.2f per 1000 gallons use charge. \n\n", DEMAND_CHG, PER_100_CHG);
    printf("A $%.2f surcharge is added to accounts with an unpaid balance.\n", LATE_CHG);
    printf("\nEnter unpaid balance, previous and current meter readings on separate lines after the prompts.\n");
    printf("Press <return> or <enter> after typing each number. \n\n");
}

double
comp_use_charge(int previous0, int current0){
    return ((current0-previous0)*PER_100_CHG);
}

double
comp_late_charge(double unpaid0){
    if(unpaid0 > 0)
        return(LATE_CHG);
    else
        return(0.0);
}

void
display_bill(double late_charge0, double bill0, double unpaid0){
    if (late_charge0 > 0.0) {
        printf("\nBill includes $%.2f late charge on unpaid balance of $%.2f\n", late_charge0, unpaid0);
    }
    printf("\nTotal due = $%.2f\n", bill0);
}