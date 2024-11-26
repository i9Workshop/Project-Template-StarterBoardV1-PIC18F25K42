#include "program.h"


// Delay x750ns
void delay_x750ns(uint8_t delay) {
    for(uint8_t i=0; i<delay; i++) NOP();
}

// Delay x21.125us
void delay_x21o125us(uint16_t delay) {
    for(uint16_t i=0; i<delay; i++) delay_x750ns(27);
}

// Delay x1ms
void delay_ms(uint32_t delay) {
    for(uint32_t i=0; i<delay; i++) delay_x21o125us(47);
}


void programInitialize(void) {
    // LED 1 pin
    TRISBbits.TRISB7 = 0;
    ANSELBbits.ANSELB7 = 0;
    LATBbits.LATB7 = 0;
    
    // LED 2 pin
    TRISBbits.TRISB6 = 0;
    ANSELBbits.ANSELB6 = 0;
    LATBbits.LATB6 = 0;
    
    // Push button up pin
    TRISAbits.TRISA1 = 1;
    ANSELAbits.ANSELA1 = 0;
    
    // Push button up pin
    TRISAbits.TRISA3 = 1;
    ANSELAbits.ANSELA3 = 0;
    
    // Push button up pin
    TRISAbits.TRISA4 = 1;
    ANSELAbits.ANSELA4 = 0;
    
    // Push button up pin
    TRISAbits.TRISA5 = 1;
    ANSELAbits.ANSELA5 = 0;
}

void programLoop(void) {
    if(!pb_Up) {
        led1 = 1;
        led2 = 1;
        delay_ms(300);
        
        led1 = 0;
        led2 = 0;
        delay_ms(300);
    }
    
    if(!pb_Left) {
        led1 = 1;
        led2 = 0;
        delay_ms(300);
        
        led1 = 0;
        led2 = 0;
        delay_ms(300);
    }
    
    if(!pb_Right) {
        led1 = 0;
        led2 = 1;
        delay_ms(300);
        
        led1 = 0;
        led2 = 0;
        delay_ms(300);
    }
    
    if(!pb_Down) {
        led1 = 1;
        led2 = 0;
        delay_ms(300);
        
        led1 = 0;
        led2 = 1;
        delay_ms(300);
    }
    
    else {
        led1 = 0;
        led2 = 0;
    }
}
