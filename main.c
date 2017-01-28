/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>        /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>       /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>   /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>        /* For uint8_t definition */
#include <stdbool.h>       /* For true/false definition */

#endif

#include "system.h"        /* System funct/params, like osc/peripheral config */
#include "user.h"          /* User funct/params, such as InitApp */
#include "delay.h"
#include "share.h"

/******************************************************************************/
/* User Global Variable Declaration                                           */
/******************************************************************************/

/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    /* TODO <INSERT USER APPLICATION CODE HERE> */

    TRISA = 0; 
    
    while(1) {
        
//      if (tr1SecSignal) {
//        LATBbits.LATB0=1;
//        LATBbits.LATB1=0;
//      } else {
//        LATBbits.LATB0=0;
//        LATBbits.LATB1=1;
//       }
        
        LATBbits.LATB0=1;
        LATBbits.LATB1=0;        
        __delay_ms(1000);
        
        LATBbits.LATB0=0;
        LATBbits.LATB1=1;
        __delay_ms(1000);
    }  
}

