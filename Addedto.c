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
    TA1CCR0 = 100;						// set signal period


    while (1) {

//move forward some
    	forward(60)
        __delay_cycles(3000000);
//stop for a bit
        STOP()
        __delay_cycles(2000000);

//turn left a little
        turnleft(60)
        __delay_cycles(1000000);

//stop for a bit
        STOP()
        __delay_cycles(2000000);

//turn right a little
        turnright(60)
        __delay_cycles(1000000);

//stop for a bit
        STOP()
        __delay_cycles(2000000);

//large left turn
        turnleft(60)
        __delay_cycles(3000000);

//stop for a bit
        STOP()
        __delay_cycles(2000000);

 //large right turn
        turnright(60)
        __delay_cycles(3000000);

 //stop for a bit
       STOP()
       __delay_cycles(2000000);

//move backwards
       backwards(80)
       __delay_cycles(2000000);

//stop for a bit
       STOP()
       __delay_cycles(2000000);


    } // end loop

    void STOP() {
    	P2OUT &= ~BIT0;
    }

    void forward(int fast) {
    	P2OUT |= BIT0;
    	P2OUT &= ~BIT1;
    	TA1CCR1 = fast;
    	TA1CCTL1 = OUTMOD_7;

    	P2OUT &= ~BIT3;
    	TA1CCTL2 = OUTMOD_7;
    	TA1CCR2 = fast;
    }

    void backwards(int fast) {
    	P2OUT |= BIT0;
    	P2OUT |= BIT1;
    	TA1CCR1 = fast;
    	TA1CCTL1 = OUTMOD_3;

    	P2OUT |= BIT3;
    	TA1CCTL2 = OUTMOD_3;
    	TA1CCR2 = fast;

    }

    void turnleft(int fast) {
    	 P2OUT |= BIT0;
    	 P2OUT &= ~BIT1;
    	 TA1CCR1 = fast;
    	 TA1CCTL1 = OUTMOD_7;

    	 P2OUT &= ~BIT3;
    	 TA1CCTL2 = OUTMOD_7;
    	 TA1CCR2 = fast;

    }

    void turnright(int fast) {
    	P2OUT |= BIT0;
    	P2OUT &= ~BIT1;
    	TA1CCR1 = fast;
    	TA1CCTL1 = OUTMOD_7;

    	P2OUT &= ~BIT3;
    	TA1CCTL2 = OUTMOD_7;
    	TA1CCR2 = fast;

    }



} // end main
