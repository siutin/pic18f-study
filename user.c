/******************************************************************************/
/* Files to Include                                                           */
/******************************************************************************/

#if defined(__XC)
    #include <xc.h>         /* XC8 General Include File */
#elif defined(HI_TECH_C)
    #include <htc.h>        /* HiTech General Include File */
#elif defined(__18CXX)
    #include <p18cxxx.h>    /* C18 General Include File */
#endif

#if defined(__XC) || defined(HI_TECH_C)

#include <stdint.h>         /* For uint8_t definition */
#include <stdbool.h>        /* For true/false definition */

#endif

#include "user.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

/* <Initialize variables in user.h and insert code for user algorithms.> */

void InitApp(void)
{
    /* TODO Initialize User Ports/Peripherals/Project here */

    /* Setup analog functionality and port direction */

    /* Initialize peripherals */

    /* Configure the IPEN bit (1=on) in RCON to turn on/off int priorities */

    /* Enable interrupts */
    
    setupTimer0();   
}

void setupTimer0(void)
{
    // Delay 1 second
    
    // FOSC = 20MHz
    // FCPU = FOSC/4 = 20MHz/4 = 5MHz
    // Overflow period = Time Period * Prescaler * Prescaler 
    //                 = 1/FCPU * Prescaler * Prescaler
    //                 = 0.2 * 256 * 256 us = 13107.2 us = 0.0131072 sec
    // Overflow Count  = 1/0.0131072 = 76.293945313 ~ 76
    
    T0PS0=1;    //Prescaler is divide by 256
    T0PS1=1;
    T0PS2=1;

    PSA=0;      //Timer Clock Source is from Prescaler

    T0CS=0;     //Prescaler gets clock from FCPU (5MHz)

    T08BIT=1;   //8 BIT MODE

    TMR0IE=1;   //Enable TIMER0 Interrupt
    PEIE=1;     //Enable Peripheral Interrupt

    GIE=1;      //Enable INTs globally

    TMR0ON=1;      //Now start the timer!
}

