/******************************************************************************/
/*Files to Include                                                            */
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

#include "share.h"

/******************************************************************************/
/* Interrupt Routines                                                         */
/******************************************************************************/

void interrupt ISR()
{
   //Check if it is TMR0 Overflow ISR
   if(TMR0IE && TMR0IF)
   {
      //TMR0 Overflow ISR
      tr1SecCounter++;  //Increment Over Flow Counter

      if(tr1SecCounter==122)
      {
        if (tr1SecSignal == false) 
            tr1SecSignal = true;
        else
            tr1SecSignal = false;
          
        tr1SecCounter = 0;  //Reset Counter
      }

      //Clear Flag
      TMR0IF=0;
   }
}
