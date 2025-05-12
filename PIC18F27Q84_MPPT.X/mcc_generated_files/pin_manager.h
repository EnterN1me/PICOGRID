/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F27Q84
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set channel_ANA0 aliases
#define channel_ANA0_TRIS                 TRISAbits.TRISA0
#define channel_ANA0_LAT                  LATAbits.LATA0
#define channel_ANA0_PORT                 PORTAbits.RA0
#define channel_ANA0_WPU                  WPUAbits.WPUA0
#define channel_ANA0_OD                   ODCONAbits.ODCA0
#define channel_ANA0_ANS                  ANSELAbits.ANSELA0
#define channel_ANA0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define channel_ANA0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define channel_ANA0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define channel_ANA0_GetValue()           PORTAbits.RA0
#define channel_ANA0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define channel_ANA0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define channel_ANA0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define channel_ANA0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define channel_ANA0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define channel_ANA0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define channel_ANA0_SetAnalogMode()      do { ANSELAbits.ANSELA0 = 1; } while(0)
#define channel_ANA0_SetDigitalMode()     do { ANSELAbits.ANSELA0 = 0; } while(0)

// get/set RB0 procedures
#define RB0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define RB0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define RB0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define RB0_GetValue()              PORTBbits.RB0
#define RB0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define RB0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define RB0_SetPullup()             do { WPUBbits.WPUB0 = 1; } while(0)
#define RB0_ResetPullup()           do { WPUBbits.WPUB0 = 0; } while(0)
#define RB0_SetAnalogMode()         do { ANSELBbits.ANSELB0 = 1; } while(0)
#define RB0_SetDigitalMode()        do { ANSELBbits.ANSELB0 = 0; } while(0)

// get/set RB1 procedures
#define RB1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define RB1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define RB1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define RB1_GetValue()              PORTBbits.RB1
#define RB1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define RB1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define RB1_SetPullup()             do { WPUBbits.WPUB1 = 1; } while(0)
#define RB1_ResetPullup()           do { WPUBbits.WPUB1 = 0; } while(0)
#define RB1_SetAnalogMode()         do { ANSELBbits.ANSELB1 = 1; } while(0)
#define RB1_SetDigitalMode()        do { ANSELBbits.ANSELB1 = 0; } while(0)

// get/set RB2 procedures
#define RB2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define RB2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define RB2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define RB2_GetValue()              PORTBbits.RB2
#define RB2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define RB2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define RB2_SetPullup()             do { WPUBbits.WPUB2 = 1; } while(0)
#define RB2_ResetPullup()           do { WPUBbits.WPUB2 = 0; } while(0)
#define RB2_SetAnalogMode()         do { ANSELBbits.ANSELB2 = 1; } while(0)
#define RB2_SetDigitalMode()        do { ANSELBbits.ANSELB2 = 0; } while(0)

// get/set RB3 procedures
#define RB3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define RB3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define RB3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define RB3_GetValue()              PORTBbits.RB3
#define RB3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define RB3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define RB3_SetPullup()             do { WPUBbits.WPUB3 = 1; } while(0)
#define RB3_ResetPullup()           do { WPUBbits.WPUB3 = 0; } while(0)
#define RB3_SetAnalogMode()         do { ANSELBbits.ANSELB3 = 1; } while(0)
#define RB3_SetDigitalMode()        do { ANSELBbits.ANSELB3 = 0; } while(0)

// get/set RC0 aliases
#define RC0_TRIS                 TRISCbits.TRISC0
#define RC0_LAT                  LATCbits.LATC0
#define RC0_PORT                 PORTCbits.RC0
#define RC0_WPU                  WPUCbits.WPUC0
#define RC0_OD                   ODCONCbits.ODCC0
#define RC0_ANS                  ANSELCbits.ANSELC0
#define RC0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define RC0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define RC0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define RC0_GetValue()           PORTCbits.RC0
#define RC0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define RC0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define RC0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define RC0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define RC0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define RC0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define RC0_SetAnalogMode()      do { ANSELCbits.ANSELC0 = 1; } while(0)
#define RC0_SetDigitalMode()     do { ANSELCbits.ANSELC0 = 0; } while(0)

// get/set RC1 aliases
#define RC1_TRIS                 TRISCbits.TRISC1
#define RC1_LAT                  LATCbits.LATC1
#define RC1_PORT                 PORTCbits.RC1
#define RC1_WPU                  WPUCbits.WPUC1
#define RC1_OD                   ODCONCbits.ODCC1
#define RC1_ANS                  ANSELCbits.ANSELC1
#define RC1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define RC1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define RC1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define RC1_GetValue()           PORTCbits.RC1
#define RC1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define RC1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define RC1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define RC1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define RC1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define RC1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define RC1_SetAnalogMode()      do { ANSELCbits.ANSELC1 = 1; } while(0)
#define RC1_SetDigitalMode()     do { ANSELCbits.ANSELC1 = 0; } while(0)

// get/set led0 aliases
#define led0_TRIS                 TRISCbits.TRISC2
#define led0_LAT                  LATCbits.LATC2
#define led0_PORT                 PORTCbits.RC2
#define led0_WPU                  WPUCbits.WPUC2
#define led0_OD                   ODCONCbits.ODCC2
#define led0_ANS                  ANSELCbits.ANSELC2
#define led0_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define led0_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define led0_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define led0_GetValue()           PORTCbits.RC2
#define led0_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define led0_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define led0_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define led0_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define led0_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define led0_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define led0_SetAnalogMode()      do { ANSELCbits.ANSELC2 = 1; } while(0)
#define led0_SetDigitalMode()     do { ANSELCbits.ANSELC2 = 0; } while(0)

// get/set led1 aliases
#define led1_TRIS                 TRISCbits.TRISC3
#define led1_LAT                  LATCbits.LATC3
#define led1_PORT                 PORTCbits.RC3
#define led1_WPU                  WPUCbits.WPUC3
#define led1_OD                   ODCONCbits.ODCC3
#define led1_ANS                  ANSELCbits.ANSELC3
#define led1_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define led1_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define led1_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define led1_GetValue()           PORTCbits.RC3
#define led1_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define led1_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define led1_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define led1_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define led1_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define led1_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define led1_SetAnalogMode()      do { ANSELCbits.ANSELC3 = 1; } while(0)
#define led1_SetDigitalMode()     do { ANSELCbits.ANSELC3 = 0; } while(0)

// get/set led2 aliases
#define led2_TRIS                 TRISCbits.TRISC4
#define led2_LAT                  LATCbits.LATC4
#define led2_PORT                 PORTCbits.RC4
#define led2_WPU                  WPUCbits.WPUC4
#define led2_OD                   ODCONCbits.ODCC4
#define led2_ANS                  ANSELCbits.ANSELC4
#define led2_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define led2_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define led2_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define led2_GetValue()           PORTCbits.RC4
#define led2_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define led2_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define led2_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define led2_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define led2_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define led2_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define led2_SetAnalogMode()      do { ANSELCbits.ANSELC4 = 1; } while(0)
#define led2_SetDigitalMode()     do { ANSELCbits.ANSELC4 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/