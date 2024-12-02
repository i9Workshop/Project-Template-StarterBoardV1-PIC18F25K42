// CONFIG1L
#pragma config FEXTOSC = HS         // Oscillator selection -> HS, High-speed crystal/resonator above 8MHz connected between OSC1 and OSC2 pins
#pragma config RSTOSC = EXTOSC_4PLL // Reset oscillator selection -> EXTOSC with 4x PLL

// CONFIG1H
#pragma config CLKOUTEN = ON        // CLKOUT, clock out function on pin -> enable
#pragma config PR1WAY = OFF         // PRLOCKED one-way -> PRLOCK can be set and cleared repeatedly
#pragma config CSWEN = OFF          // Internal/External switchover -> disable, the NOSC and NDIV bits cannot be changed by user software
#pragma config FCMEN = OFF          // Fail-safe clock monitor -> disable

// CONFIG2L
#pragma config MCLRE = EXTMCLR      // MCLR, master clear function on pin -> enable
#pragma config PWRTS = PWRT_64      // Power-up timer -> enable, timer = 64ms
#pragma config MVECEN = ON          // Multi-vector -> enabled, vector table used for interrupts
#pragma config IVT1WAY = OFF        // IVTLOCK one-way -> IVTLOCK can be cleared and set repeatedly
#pragma config LPBOREN = OFF        // Low power BOR -> disable
#pragma config BOREN = ON           // Brown-out reset -> enable

// CONFIG2H
#pragma config BORV = VBOR_2P45     // Brown-out reset voltage -> VBOR = 2.45V
#pragma config ZCD = OFF            // ZCD module -> disabled
#pragma config PPS1WAY = OFF        // PPSLOCK one-way -> PPSLOCK can be set and cleared repeatedly, subject to the unlock sequence
#pragma config STVREN = ON          // Stack full/underflow reset -> enable
#pragma config DEBUG = OFF          // Background debugger -> disabled
#pragma config XINST = OFF          // Extended instruction set and indexed addressing mode -> disabled

// CONFIG3L
#pragma config WDTE = OFF           // Watchdog timer -> disabled
#pragma config WDTCPS = WDTCPS_31   // WDT period selection bits -> Divider ratio 1:65536, software control of WDTPS

// CONFIG3H
#pragma config WDTCWS = WDTCWS_7    // WDT window select bits -> window always open 100%, software control keyed access not required
#pragma config WDTCCS = SC          // WDT input clock selector -> software sontrol


#include "program.h"


void main(void) {
    delay_ms(10);     // Additional PSU power up timing after 64ms CPU power up timer, PWRTS
    delay_x750ns(22); // Oscillator start up timing and I/O high impedance from reset
                      // Tost = 16us
    
    programInitialize(); // Initialize prorgram
    
    while(1) {
        programLoop(); // Main prorgram
    }
}
