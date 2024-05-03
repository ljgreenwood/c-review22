#include <msp430.h>
#include "msp430g2553.h"
int sw2 = 0; //switch variable
int count_sema=0; //count sephamore

/*
modify so that at the push of the button the micro cycles through 4 different modes of operation
use a counting semaphore (1-3), which is incremented whenever the siwtch is closed, and it resets to 1 when it reaches value >=4.
When the switch is open, the software uses a case statement to execute the 4 ifferent modes of operations based on the semaphore value as follows
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
            // insert case statement here using semaphore
            _delay_cycles(50000); //delay 50,000 microseconds
        }
        else{ //(sw2 != BIT3) // SW2 is low
            //insert semaphore increment here
            _delay_cycles(200000); //200,000 microseconds
        }
    } //end loop
}
// 500 milliseconds each 1000 mill cycle is one second cycle or 1 hertz
//end int