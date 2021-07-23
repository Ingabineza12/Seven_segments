/*
 * File:   seven_segment.c
 * Author: Deborah
 *
 * Created on July 23, 2021, 9:33 AM
 */
// CONFIG
#pragma config FOSC = EXTRC     // Oscillator Selection bits (RC oscillator)
#pragma config WDTE = ON        // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = ON         // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3/PGM pin has PGM function; low-voltage programming enabled)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#include <xc.h>
#define _XTAL_FREQ 8000000 //define frequency to 8MHz

// This array stores binary bit pattern that will be send to PORTD
unsigned char const binary_pattern[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
void main(void) 
{
    TRISD = 0x00; //define PORTD as a output pin
    while(1)
    {
        //this loop sends all binary patterns to PORTD
        for (int i=0;i<10;i++)
        {
            PORTD = binary_pattern[i];
            __delay_ms(200); 
        }
    }
    return;
}
