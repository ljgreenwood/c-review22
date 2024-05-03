#include <msp430.h>
#include "msp430g2553.h"
int sw2 = 0; //WHY IS THIS OUTSIDE? WHAT IS THIS?
int count_sema=0;
/*
Using sensors... infinite running loop which needs to perform action on interrupt circuit.
any changes on the port spurs interrupt, wakes up mp. 

How to write in C?

To Do:
    - change program to include interrupt
    - change program to integrate watchdog

*/

int main(void){
    WDTCTL = WDTPW | WDTHOLD; // stop watchdog
    P1DIR = 0x00;   //port 1 all inputs
    P1DIR |= (BIT0 \ BIT6); // set P1.0 and P1.6 as outputs (LED1, LED2)
    P1REN |= BIT3; //activate resister (resister enable) on P1.3 (need resister on P1.3)
    P1OUT |= BIT3; //make it pull up because SW2 is active low

    for(;;){
        sw2 = P1IN; //reads in values from all inputs (next line specifies P1.3)
        sw2 &= BIT3; //mask out only BIT3 where SW2 is connected and read 
        if (sw2 == BIT3){ //if SW2 is high
            P1OUT &= ~BIT6; //turn LED2 off (~BIT6 is inverse or "NOT")
            P1OUT ^= BIT0; //toggle LED1 (^= is XOR operation) - XOR functions as toggle to 0 or 1, whichever is the operator
            _delay_cycles(50000); //delay 50,000 microseconds
        }
        else{ //(sw2 != BIT3) // SW2 is low
            P1OUT &= ~BIT0; // turns LED1 off
            P1OUT ^= BIT6; //toggles LED2
            _delay_cycles(200000); //200,000 microseconds
        }
    } //end loop
}
// 500 milliseconds each 1000 mill cycle is one second cycle or 1 hertz
//end int