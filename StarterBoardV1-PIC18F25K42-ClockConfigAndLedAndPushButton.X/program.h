#ifndef program_H
#define	program_H

#include <xc.h>

#ifdef	__cplusplus
extern "C" {
#endif
    
    
#define led1        LATBbits.LATB7
#define led2        LATBbits.LATB6
    
#define pb_Up       PORTAbits.RA1
#define pb_Down     PORTAbits.RA3
#define pb_Left     PORTAbits.RA4
#define pb_Right    PORTAbits.RA5


    void delay_x750ns(uint8_t delay);
    void delay_x21o125us(uint16_t delay);
    void delay_ms(uint32_t delay);
    
    void programInitialize(void);
    void programLoop(void);
    

#ifdef	__cplusplus
}
#endif

#endif	/* program_H */
