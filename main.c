#include <msp430.h>

void main(void) {
    WDTCTL = WDTPW|WDTHOLD;                 // stop the watchdog timer


    P2DIR |= BIT0;
    P2OUT |= BIT0;

    P2DIR |= BIT1;
    P2OUT &= ~BIT1;

    P2DIR |= BIT2;							// P2.2 is associated with TA1CCR1
    P2SEL |= BIT2;							// P2.2 is associated with TA1CCTL1

    P2DIR |= BIT3;
    P2OUT &= ~BIT3;

    P2DIR |= BIT4;							// P2.4 is associated with TA1CCR2
    P2SEL |= BIT4;							// P2.4 is associated with TA1CCTL2


	TA1CTL = ID_3 | TASSEL_2 | MC_1;		// Use 1:8 presclar off MCLK
    TA1CCR0 = 0x0100;						// set signal period


    while (1) {

//move forward some
    	P2OUT |= BIT0;
        P2OUT &= ~BIT1;
        TA1CCR1 = 0x0070;
        TA1CCTL1 = OUTMOD_7;

        P2OUT &= ~BIT3;
        TA1CCTL2 = OUTMOD_7;
        TA1CCR2 = 0x0070;

        __delay_cycles(3000000);
//stop for a bit
        P2OUT &= ~BIT0;

        __delay_cycles(2000000);

//turn left a little
        P2OUT |= BIT0;
        P2OUT &= ~BIT1;
        TA1CCR1 = 0x0030;
        TA1CCTL1 = OUTMOD_7;

        P2OUT &= ~BIT3;
        TA1CCTL2 = OUTMOD_7;
        TA1CCR2 = 0x0080;

        __delay_cycles(1000000);

//stop for a bit
        P2OUT &= ~BIT0;

        __delay_cycles(2000000);

//turn right a little
        P2OUT |= BIT0;
        P2OUT &= ~BIT1;
        TA1CCR1 = 0x0080;
        TA1CCTL1 = OUTMOD_7;

        P2OUT &= ~BIT3;
        TA1CCTL2 = OUTMOD_7;
        TA1CCR2 = 0x0030;

        __delay_cycles(1000000);

//stop for a bit
        P2OUT &= ~BIT0;

        __delay_cycles(2000000);

//large left turn
        P2OUT |= BIT0;
        P2OUT &= ~BIT1;
        TA1CCR1 = 0x0030;
        TA1CCTL1 = OUTMOD_7;

        P2OUT &= ~BIT3;
        TA1CCTL2 = OUTMOD_7;
        TA1CCR2 = 0x0080;

        __delay_cycles(3000000);

//stop for a bit
        P2OUT &= ~BIT0;

        __delay_cycles(2000000);

 //large left turn
        P2OUT |= BIT0;
        P2OUT &= ~BIT1;
        TA1CCR1 = 0x0080;
        TA1CCTL1 = OUTMOD_7;

        P2OUT &= ~BIT3;
        TA1CCTL2 = OUTMOD_7;
        TA1CCR2 = 0x0030;

        __delay_cycles(3000000);

 //stop for a bit
       P2OUT &= ~BIT0;

       __delay_cycles(2000000);

//move backwards
       P2OUT |= BIT0;
       P2OUT |= BIT1;
       TA1CCR1 = 0x0080;
       TA1CCTL1 = OUTMOD_3;

       P2OUT |= BIT3;
       TA1CCTL2 = OUTMOD_3;
       TA1CCR2 = 0x0080;

       __delay_cycles(2000000);

//stop for a bit
       P2OUT &= ~BIT0;

       __delay_cycles(2000000);


    } // end loop
} // end main
