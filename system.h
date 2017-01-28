/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/

/* TODO Define system operating frequency */

/* Microcontroller MIPs (FCY) */

#define SYS_FREQ        40000000L
#define FCY             SYS_FREQ/4

//#define SYS_FREQ        32000000L
//#define FCY             SYS_FREQ/4
//#define FOSC            32000000L
//#define INT_OSC            8000000L

/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

/* Custom oscillator configuration funtions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */

void ConfigureOscillator(void); /* Handles clock switching/osc initialization */
