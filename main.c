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

#define LCD_DB PORTC
//#define LCD_DB    LATC
#define LCD_RS      LATAbits.LATA0 //PORTCbits.RC0
#define LCD_EN      LATAbits.LATA1 //PORTCbits.RC1
#define LCD_RST     LATAbits.LATA2 //PORTCbits.RC2
#define LCD_RW      LATAbits.LATA3 //PORTCbits.RC3
#define LCD_PSB     LATAbits.LATA4 //PORTCbits.RC4


/* i.e. uint8_t <variable_name>; */

/******************************************************************************/
/* Main Program                                                               */
/******************************************************************************/

void lcdWait(void) {
    
    LCD_RS = 0;
    LCD_RW = 1;
    
    TRISC = 0xFF;

    while(1)
    {
        __delay_us(1);
        
        LCD_EN = 1;
        __delay_us(1);
        
        if(PORTCbits.RC7) break;
        if(LATCbits.LATC7) break;
       
        __delay_us(1);
        LCD_EN = 0;
        
        if(PORTCbits.RC7) break;
        if(LATCbits.LATC7) break;

    }
    LCD_EN = 0;
    __delay_us(1);
    TRISC = 0;
    __delay_us(1);
}


void lcdWriteCmd(unsigned char comm) {
    
//    lcdWait();
    LCD_RS = 0;
    __delay_us(1);
    LCD_RW = 0;
    __delay_us(1);
    LCD_DB = comm;    
    __delay_us(1);
    
    LCD_EN = 1;
    __delay_us(1);
    
    LCD_EN = 0;   
    __delay_us(20);
}

void lcdWriteData(unsigned char c) {
    
//    lcdWait();
    LCD_RS = 1;    
    __delay_us(1);
    LCD_RW = 0;
    __delay_us(1);
    LCD_DB = c;
    __delay_us(1);

    LCD_EN = 1;   
    __delay_us(1);
    
    LCD_EN = 0;    
    __delay_us(20);
}

void lcdInit(void) {
    
    __delay_ms(100);
    
    LCD_PSB = 1;  
    __delay_us(1);
    LCD_RST = 1;
    __delay_us(1);
    LCD_RST = 0;
    __delay_us(1);
    LCD_RST = 1;
    __delay_us(1);
  
    lcdWriteCmd(0x30);
    __delay_ms(100);

    lcdWriteCmd(0x06);
    __delay_ms(100);
    
    lcdWriteCmd(0x01);
    __delay_ms(100);
    
    lcdWriteCmd(0x0c);
    __delay_ms(100);
    
    lcdWriteCmd(0x02);
    __delay_ms(100);
//    
//    lcdWriteCmd(0b00110000); // Function Set
//    __delay_ms(100);
//
//    lcdWriteCmd(0b00110000); // Function Set
//    __delay_ms(100);
//    
//    lcdWriteCmd(0b00001100); // Display Control
//    __delay_ms(100);
//    
//    lcdWriteCmd(0b00000001); // Display Clear
//    __delay_ms(100);
//    
//    lcdWriteCmd(0b00000110); // Entry mode Set
//    __delay_ms(100);
//
//    lcdWriteCmd(0b00000010); // Address of Zero
//    __delay_ms(100);
}

void main(void)
{
    /* Configure the oscillator for the device */
    ConfigureOscillator();

    /* Initialize I/O and Peripherals for application */
    InitApp();

    TRISC = 0;
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA3 = 0;
    TRISAbits.TRISA4 = 0;
    TRISAbits.TRISA5 = 0;

    /* TODO <INSERT USER APPLICATION CODE HERE> */

    LATAbits.LATA5=0;
    
    lcdInit();
    
    LATAbits.LATA5=1;

    while(1) {
     
        lcdWriteCmd(0x80);
        lcdWriteData('H');
        lcdWriteData('E');
        lcdWriteData('L');
        lcdWriteData('L');
        lcdWriteData('O');
    
//      if (tr1SecSignal) {
//        LATBbits.LATB0=1;
//        LATBbits.LATB1=0;
//      } else {
//        LATBbits.LATB0=0;
//        LATBbits.LATB1=1;
//       }
//        
        __delay_ms(1000);

        LATAbits.LATA5=1;
        __delay_ms(1000);
        
        LATAbits.LATA5=0;
        __delay_ms(1000);
                
    }  
}

