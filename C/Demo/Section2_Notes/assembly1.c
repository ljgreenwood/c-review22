
"""
look up about DEBOUNCING, #PRAGMA VECTOR = PORT1_VECTOR, and PULL-UP/PULL-DOWN
--> also downloading libraries for programming in C?
"""

#include <msp430g2553.h>
#define LED1 BIT0 //Ports?
#define LED2 BIT6
#define BUTTON BIT3

unsigned int folds = 1;
int i=1;

void main(){
    WDTCTL = WDTPW + WDTHOLD; //stop watchdog

    P1OUT = 0x00; //set default outputs to zero
    P1DIR = 0x00; //set all port pins default "input"
    P1DIR = (LED1 | LED2); //Set p1.0 and P1.6 to output direction
   
    '''Setting Interrupt to Input port P1.3'''
    P1REN |= BUTTON; //Port 1 resistor enabled on the button pin (pin 3)
    P1OUT |= BUTTON; //make that a pull up resistor (**)
    P1IES |= BUTTON; //interrupt edge select, high to low (falling edge)
    P1IE  |= BUTTON; //enable interrupt on selected pin
    _enable_interrupt(); //enables interrupts in general

    for (;;){
        P1OUT ^= (LED2); //toggle P1.0 using XOR
        for(i=1;i <= folds; i++){
            _delay_cycles(100000); // 100,000 micro second delay
        }
    }
    // end main
}

//pull up = active low

// Port 1 interrupt routine
#pragma vector = PORT1_VECTOR 
_interrupt void Port_1(void)
{
    P1OUT |= LED1; //LED1 set on start of interrupt (visual indicator)

    folds ++; //increments folds
    if (folds >= 4){folds = 1;} //cycle folds for 1, 2 , 3
    _delay_cycles(20000); //allow some delay for switch debounce --> recognize first transition and ignore following "bouncing" makes micro pause for switch signal to stop bouncing.

    P1IFG &= ~BUTTON; //P1 interrupt flag is cleared by ANDING it with the inverse of button
        // --> interrupt flag is 8 bits, flag for every input pin, so you can distinguish which input had a flag
    _delay_cycles(20000); //allow some delay for switch debounce 

    P1OUT &= ~LED1; // LED1 off to indicate end of interrupt
}
//end port 1 interrupt
//SIGMA 4 * in this case counting sigma 4 is ""
