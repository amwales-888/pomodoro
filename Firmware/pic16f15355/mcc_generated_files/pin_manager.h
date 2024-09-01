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
        Device            :  PIC16F15355
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

// get/set IO_LEDR0 aliases
#define IO_LEDR0_TRIS                 TRISAbits.TRISA0
#define IO_LEDR0_LAT                  LATAbits.LATA0
#define IO_LEDR0_PORT                 PORTAbits.RA0
#define IO_LEDR0_WPU                  WPUAbits.WPUA0
#define IO_LEDR0_OD                   ODCONAbits.ODCA0
#define IO_LEDR0_ANS                  ANSELAbits.ANSA0
#define IO_LEDR0_SetHigh()            do { LATAbits.LATA0 = 1; } while(0)
#define IO_LEDR0_SetLow()             do { LATAbits.LATA0 = 0; } while(0)
#define IO_LEDR0_Toggle()             do { LATAbits.LATA0 = ~LATAbits.LATA0; } while(0)
#define IO_LEDR0_GetValue()           PORTAbits.RA0
#define IO_LEDR0_SetDigitalInput()    do { TRISAbits.TRISA0 = 1; } while(0)
#define IO_LEDR0_SetDigitalOutput()   do { TRISAbits.TRISA0 = 0; } while(0)
#define IO_LEDR0_SetPullup()          do { WPUAbits.WPUA0 = 1; } while(0)
#define IO_LEDR0_ResetPullup()        do { WPUAbits.WPUA0 = 0; } while(0)
#define IO_LEDR0_SetPushPull()        do { ODCONAbits.ODCA0 = 0; } while(0)
#define IO_LEDR0_SetOpenDrain()       do { ODCONAbits.ODCA0 = 1; } while(0)
#define IO_LEDR0_SetAnalogMode()      do { ANSELAbits.ANSA0 = 1; } while(0)
#define IO_LEDR0_SetDigitalMode()     do { ANSELAbits.ANSA0 = 0; } while(0)

// get/set IO_LEDR1 aliases
#define IO_LEDR1_TRIS                 TRISAbits.TRISA1
#define IO_LEDR1_LAT                  LATAbits.LATA1
#define IO_LEDR1_PORT                 PORTAbits.RA1
#define IO_LEDR1_WPU                  WPUAbits.WPUA1
#define IO_LEDR1_OD                   ODCONAbits.ODCA1
#define IO_LEDR1_ANS                  ANSELAbits.ANSA1
#define IO_LEDR1_SetHigh()            do { LATAbits.LATA1 = 1; } while(0)
#define IO_LEDR1_SetLow()             do { LATAbits.LATA1 = 0; } while(0)
#define IO_LEDR1_Toggle()             do { LATAbits.LATA1 = ~LATAbits.LATA1; } while(0)
#define IO_LEDR1_GetValue()           PORTAbits.RA1
#define IO_LEDR1_SetDigitalInput()    do { TRISAbits.TRISA1 = 1; } while(0)
#define IO_LEDR1_SetDigitalOutput()   do { TRISAbits.TRISA1 = 0; } while(0)
#define IO_LEDR1_SetPullup()          do { WPUAbits.WPUA1 = 1; } while(0)
#define IO_LEDR1_ResetPullup()        do { WPUAbits.WPUA1 = 0; } while(0)
#define IO_LEDR1_SetPushPull()        do { ODCONAbits.ODCA1 = 0; } while(0)
#define IO_LEDR1_SetOpenDrain()       do { ODCONAbits.ODCA1 = 1; } while(0)
#define IO_LEDR1_SetAnalogMode()      do { ANSELAbits.ANSA1 = 1; } while(0)
#define IO_LEDR1_SetDigitalMode()     do { ANSELAbits.ANSA1 = 0; } while(0)

// get/set IO_LEDR2 aliases
#define IO_LEDR2_TRIS                 TRISAbits.TRISA2
#define IO_LEDR2_LAT                  LATAbits.LATA2
#define IO_LEDR2_PORT                 PORTAbits.RA2
#define IO_LEDR2_WPU                  WPUAbits.WPUA2
#define IO_LEDR2_OD                   ODCONAbits.ODCA2
#define IO_LEDR2_ANS                  ANSELAbits.ANSA2
#define IO_LEDR2_SetHigh()            do { LATAbits.LATA2 = 1; } while(0)
#define IO_LEDR2_SetLow()             do { LATAbits.LATA2 = 0; } while(0)
#define IO_LEDR2_Toggle()             do { LATAbits.LATA2 = ~LATAbits.LATA2; } while(0)
#define IO_LEDR2_GetValue()           PORTAbits.RA2
#define IO_LEDR2_SetDigitalInput()    do { TRISAbits.TRISA2 = 1; } while(0)
#define IO_LEDR2_SetDigitalOutput()   do { TRISAbits.TRISA2 = 0; } while(0)
#define IO_LEDR2_SetPullup()          do { WPUAbits.WPUA2 = 1; } while(0)
#define IO_LEDR2_ResetPullup()        do { WPUAbits.WPUA2 = 0; } while(0)
#define IO_LEDR2_SetPushPull()        do { ODCONAbits.ODCA2 = 0; } while(0)
#define IO_LEDR2_SetOpenDrain()       do { ODCONAbits.ODCA2 = 1; } while(0)
#define IO_LEDR2_SetAnalogMode()      do { ANSELAbits.ANSA2 = 1; } while(0)
#define IO_LEDR2_SetDigitalMode()     do { ANSELAbits.ANSA2 = 0; } while(0)

// get/set IO_LEDR3 aliases
#define IO_LEDR3_TRIS                 TRISAbits.TRISA3
#define IO_LEDR3_LAT                  LATAbits.LATA3
#define IO_LEDR3_PORT                 PORTAbits.RA3
#define IO_LEDR3_WPU                  WPUAbits.WPUA3
#define IO_LEDR3_OD                   ODCONAbits.ODCA3
#define IO_LEDR3_ANS                  ANSELAbits.ANSA3
#define IO_LEDR3_SetHigh()            do { LATAbits.LATA3 = 1; } while(0)
#define IO_LEDR3_SetLow()             do { LATAbits.LATA3 = 0; } while(0)
#define IO_LEDR3_Toggle()             do { LATAbits.LATA3 = ~LATAbits.LATA3; } while(0)
#define IO_LEDR3_GetValue()           PORTAbits.RA3
#define IO_LEDR3_SetDigitalInput()    do { TRISAbits.TRISA3 = 1; } while(0)
#define IO_LEDR3_SetDigitalOutput()   do { TRISAbits.TRISA3 = 0; } while(0)
#define IO_LEDR3_SetPullup()          do { WPUAbits.WPUA3 = 1; } while(0)
#define IO_LEDR3_ResetPullup()        do { WPUAbits.WPUA3 = 0; } while(0)
#define IO_LEDR3_SetPushPull()        do { ODCONAbits.ODCA3 = 0; } while(0)
#define IO_LEDR3_SetOpenDrain()       do { ODCONAbits.ODCA3 = 1; } while(0)
#define IO_LEDR3_SetAnalogMode()      do { ANSELAbits.ANSA3 = 1; } while(0)
#define IO_LEDR3_SetDigitalMode()     do { ANSELAbits.ANSA3 = 0; } while(0)

// get/set IO_LEDR4 aliases
#define IO_LEDR4_TRIS                 TRISAbits.TRISA4
#define IO_LEDR4_LAT                  LATAbits.LATA4
#define IO_LEDR4_PORT                 PORTAbits.RA4
#define IO_LEDR4_WPU                  WPUAbits.WPUA4
#define IO_LEDR4_OD                   ODCONAbits.ODCA4
#define IO_LEDR4_ANS                  ANSELAbits.ANSA4
#define IO_LEDR4_SetHigh()            do { LATAbits.LATA4 = 1; } while(0)
#define IO_LEDR4_SetLow()             do { LATAbits.LATA4 = 0; } while(0)
#define IO_LEDR4_Toggle()             do { LATAbits.LATA4 = ~LATAbits.LATA4; } while(0)
#define IO_LEDR4_GetValue()           PORTAbits.RA4
#define IO_LEDR4_SetDigitalInput()    do { TRISAbits.TRISA4 = 1; } while(0)
#define IO_LEDR4_SetDigitalOutput()   do { TRISAbits.TRISA4 = 0; } while(0)
#define IO_LEDR4_SetPullup()          do { WPUAbits.WPUA4 = 1; } while(0)
#define IO_LEDR4_ResetPullup()        do { WPUAbits.WPUA4 = 0; } while(0)
#define IO_LEDR4_SetPushPull()        do { ODCONAbits.ODCA4 = 0; } while(0)
#define IO_LEDR4_SetOpenDrain()       do { ODCONAbits.ODCA4 = 1; } while(0)
#define IO_LEDR4_SetAnalogMode()      do { ANSELAbits.ANSA4 = 1; } while(0)
#define IO_LEDR4_SetDigitalMode()     do { ANSELAbits.ANSA4 = 0; } while(0)

// get/set IO_LEDR5 aliases
#define IO_LEDR5_TRIS                 TRISAbits.TRISA5
#define IO_LEDR5_LAT                  LATAbits.LATA5
#define IO_LEDR5_PORT                 PORTAbits.RA5
#define IO_LEDR5_WPU                  WPUAbits.WPUA5
#define IO_LEDR5_OD                   ODCONAbits.ODCA5
#define IO_LEDR5_ANS                  ANSELAbits.ANSA5
#define IO_LEDR5_SetHigh()            do { LATAbits.LATA5 = 1; } while(0)
#define IO_LEDR5_SetLow()             do { LATAbits.LATA5 = 0; } while(0)
#define IO_LEDR5_Toggle()             do { LATAbits.LATA5 = ~LATAbits.LATA5; } while(0)
#define IO_LEDR5_GetValue()           PORTAbits.RA5
#define IO_LEDR5_SetDigitalInput()    do { TRISAbits.TRISA5 = 1; } while(0)
#define IO_LEDR5_SetDigitalOutput()   do { TRISAbits.TRISA5 = 0; } while(0)
#define IO_LEDR5_SetPullup()          do { WPUAbits.WPUA5 = 1; } while(0)
#define IO_LEDR5_ResetPullup()        do { WPUAbits.WPUA5 = 0; } while(0)
#define IO_LEDR5_SetPushPull()        do { ODCONAbits.ODCA5 = 0; } while(0)
#define IO_LEDR5_SetOpenDrain()       do { ODCONAbits.ODCA5 = 1; } while(0)
#define IO_LEDR5_SetAnalogMode()      do { ANSELAbits.ANSA5 = 1; } while(0)
#define IO_LEDR5_SetDigitalMode()     do { ANSELAbits.ANSA5 = 0; } while(0)

// get/set IO_LEDR6 aliases
#define IO_LEDR6_TRIS                 TRISAbits.TRISA6
#define IO_LEDR6_LAT                  LATAbits.LATA6
#define IO_LEDR6_PORT                 PORTAbits.RA6
#define IO_LEDR6_WPU                  WPUAbits.WPUA6
#define IO_LEDR6_OD                   ODCONAbits.ODCA6
#define IO_LEDR6_ANS                  ANSELAbits.ANSA6
#define IO_LEDR6_SetHigh()            do { LATAbits.LATA6 = 1; } while(0)
#define IO_LEDR6_SetLow()             do { LATAbits.LATA6 = 0; } while(0)
#define IO_LEDR6_Toggle()             do { LATAbits.LATA6 = ~LATAbits.LATA6; } while(0)
#define IO_LEDR6_GetValue()           PORTAbits.RA6
#define IO_LEDR6_SetDigitalInput()    do { TRISAbits.TRISA6 = 1; } while(0)
#define IO_LEDR6_SetDigitalOutput()   do { TRISAbits.TRISA6 = 0; } while(0)
#define IO_LEDR6_SetPullup()          do { WPUAbits.WPUA6 = 1; } while(0)
#define IO_LEDR6_ResetPullup()        do { WPUAbits.WPUA6 = 0; } while(0)
#define IO_LEDR6_SetPushPull()        do { ODCONAbits.ODCA6 = 0; } while(0)
#define IO_LEDR6_SetOpenDrain()       do { ODCONAbits.ODCA6 = 1; } while(0)
#define IO_LEDR6_SetAnalogMode()      do { ANSELAbits.ANSA6 = 1; } while(0)
#define IO_LEDR6_SetDigitalMode()     do { ANSELAbits.ANSA6 = 0; } while(0)

// get/set IO_BUTTON aliases
#define IO_BUTTON_TRIS                 TRISAbits.TRISA7
#define IO_BUTTON_LAT                  LATAbits.LATA7
#define IO_BUTTON_PORT                 PORTAbits.RA7
#define IO_BUTTON_WPU                  WPUAbits.WPUA7
#define IO_BUTTON_OD                   ODCONAbits.ODCA7
#define IO_BUTTON_ANS                  ANSELAbits.ANSA7
#define IO_BUTTON_SetHigh()            do { LATAbits.LATA7 = 1; } while(0)
#define IO_BUTTON_SetLow()             do { LATAbits.LATA7 = 0; } while(0)
#define IO_BUTTON_Toggle()             do { LATAbits.LATA7 = ~LATAbits.LATA7; } while(0)
#define IO_BUTTON_GetValue()           PORTAbits.RA7
#define IO_BUTTON_SetDigitalInput()    do { TRISAbits.TRISA7 = 1; } while(0)
#define IO_BUTTON_SetDigitalOutput()   do { TRISAbits.TRISA7 = 0; } while(0)
#define IO_BUTTON_SetPullup()          do { WPUAbits.WPUA7 = 1; } while(0)
#define IO_BUTTON_ResetPullup()        do { WPUAbits.WPUA7 = 0; } while(0)
#define IO_BUTTON_SetPushPull()        do { ODCONAbits.ODCA7 = 0; } while(0)
#define IO_BUTTON_SetOpenDrain()       do { ODCONAbits.ODCA7 = 1; } while(0)
#define IO_BUTTON_SetAnalogMode()      do { ANSELAbits.ANSA7 = 1; } while(0)
#define IO_BUTTON_SetDigitalMode()     do { ANSELAbits.ANSA7 = 0; } while(0)

// get/set IO_WORK0 aliases
#define IO_WORK0_TRIS                 TRISBbits.TRISB0
#define IO_WORK0_LAT                  LATBbits.LATB0
#define IO_WORK0_PORT                 PORTBbits.RB0
#define IO_WORK0_WPU                  WPUBbits.WPUB0
#define IO_WORK0_OD                   ODCONBbits.ODCB0
#define IO_WORK0_ANS                  ANSELBbits.ANSB0
#define IO_WORK0_SetHigh()            do { LATBbits.LATB0 = 1; } while(0)
#define IO_WORK0_SetLow()             do { LATBbits.LATB0 = 0; } while(0)
#define IO_WORK0_Toggle()             do { LATBbits.LATB0 = ~LATBbits.LATB0; } while(0)
#define IO_WORK0_GetValue()           PORTBbits.RB0
#define IO_WORK0_SetDigitalInput()    do { TRISBbits.TRISB0 = 1; } while(0)
#define IO_WORK0_SetDigitalOutput()   do { TRISBbits.TRISB0 = 0; } while(0)
#define IO_WORK0_SetPullup()          do { WPUBbits.WPUB0 = 1; } while(0)
#define IO_WORK0_ResetPullup()        do { WPUBbits.WPUB0 = 0; } while(0)
#define IO_WORK0_SetPushPull()        do { ODCONBbits.ODCB0 = 0; } while(0)
#define IO_WORK0_SetOpenDrain()       do { ODCONBbits.ODCB0 = 1; } while(0)
#define IO_WORK0_SetAnalogMode()      do { ANSELBbits.ANSB0 = 1; } while(0)
#define IO_WORK0_SetDigitalMode()     do { ANSELBbits.ANSB0 = 0; } while(0)

// get/set IO_WORK1 aliases
#define IO_WORK1_TRIS                 TRISBbits.TRISB1
#define IO_WORK1_LAT                  LATBbits.LATB1
#define IO_WORK1_PORT                 PORTBbits.RB1
#define IO_WORK1_WPU                  WPUBbits.WPUB1
#define IO_WORK1_OD                   ODCONBbits.ODCB1
#define IO_WORK1_ANS                  ANSELBbits.ANSB1
#define IO_WORK1_SetHigh()            do { LATBbits.LATB1 = 1; } while(0)
#define IO_WORK1_SetLow()             do { LATBbits.LATB1 = 0; } while(0)
#define IO_WORK1_Toggle()             do { LATBbits.LATB1 = ~LATBbits.LATB1; } while(0)
#define IO_WORK1_GetValue()           PORTBbits.RB1
#define IO_WORK1_SetDigitalInput()    do { TRISBbits.TRISB1 = 1; } while(0)
#define IO_WORK1_SetDigitalOutput()   do { TRISBbits.TRISB1 = 0; } while(0)
#define IO_WORK1_SetPullup()          do { WPUBbits.WPUB1 = 1; } while(0)
#define IO_WORK1_ResetPullup()        do { WPUBbits.WPUB1 = 0; } while(0)
#define IO_WORK1_SetPushPull()        do { ODCONBbits.ODCB1 = 0; } while(0)
#define IO_WORK1_SetOpenDrain()       do { ODCONBbits.ODCB1 = 1; } while(0)
#define IO_WORK1_SetAnalogMode()      do { ANSELBbits.ANSB1 = 1; } while(0)
#define IO_WORK1_SetDigitalMode()     do { ANSELBbits.ANSB1 = 0; } while(0)

// get/set IO_WORK2 aliases
#define IO_WORK2_TRIS                 TRISBbits.TRISB2
#define IO_WORK2_LAT                  LATBbits.LATB2
#define IO_WORK2_PORT                 PORTBbits.RB2
#define IO_WORK2_WPU                  WPUBbits.WPUB2
#define IO_WORK2_OD                   ODCONBbits.ODCB2
#define IO_WORK2_ANS                  ANSELBbits.ANSB2
#define IO_WORK2_SetHigh()            do { LATBbits.LATB2 = 1; } while(0)
#define IO_WORK2_SetLow()             do { LATBbits.LATB2 = 0; } while(0)
#define IO_WORK2_Toggle()             do { LATBbits.LATB2 = ~LATBbits.LATB2; } while(0)
#define IO_WORK2_GetValue()           PORTBbits.RB2
#define IO_WORK2_SetDigitalInput()    do { TRISBbits.TRISB2 = 1; } while(0)
#define IO_WORK2_SetDigitalOutput()   do { TRISBbits.TRISB2 = 0; } while(0)
#define IO_WORK2_SetPullup()          do { WPUBbits.WPUB2 = 1; } while(0)
#define IO_WORK2_ResetPullup()        do { WPUBbits.WPUB2 = 0; } while(0)
#define IO_WORK2_SetPushPull()        do { ODCONBbits.ODCB2 = 0; } while(0)
#define IO_WORK2_SetOpenDrain()       do { ODCONBbits.ODCB2 = 1; } while(0)
#define IO_WORK2_SetAnalogMode()      do { ANSELBbits.ANSB2 = 1; } while(0)
#define IO_WORK2_SetDigitalMode()     do { ANSELBbits.ANSB2 = 0; } while(0)

// get/set IO_WORK3 aliases
#define IO_WORK3_TRIS                 TRISBbits.TRISB3
#define IO_WORK3_LAT                  LATBbits.LATB3
#define IO_WORK3_PORT                 PORTBbits.RB3
#define IO_WORK3_WPU                  WPUBbits.WPUB3
#define IO_WORK3_OD                   ODCONBbits.ODCB3
#define IO_WORK3_ANS                  ANSELBbits.ANSB3
#define IO_WORK3_SetHigh()            do { LATBbits.LATB3 = 1; } while(0)
#define IO_WORK3_SetLow()             do { LATBbits.LATB3 = 0; } while(0)
#define IO_WORK3_Toggle()             do { LATBbits.LATB3 = ~LATBbits.LATB3; } while(0)
#define IO_WORK3_GetValue()           PORTBbits.RB3
#define IO_WORK3_SetDigitalInput()    do { TRISBbits.TRISB3 = 1; } while(0)
#define IO_WORK3_SetDigitalOutput()   do { TRISBbits.TRISB3 = 0; } while(0)
#define IO_WORK3_SetPullup()          do { WPUBbits.WPUB3 = 1; } while(0)
#define IO_WORK3_ResetPullup()        do { WPUBbits.WPUB3 = 0; } while(0)
#define IO_WORK3_SetPushPull()        do { ODCONBbits.ODCB3 = 0; } while(0)
#define IO_WORK3_SetOpenDrain()       do { ODCONBbits.ODCB3 = 1; } while(0)
#define IO_WORK3_SetAnalogMode()      do { ANSELBbits.ANSB3 = 1; } while(0)
#define IO_WORK3_SetDigitalMode()     do { ANSELBbits.ANSB3 = 0; } while(0)

// get/set IO_RELAX0 aliases
#define IO_RELAX0_TRIS                 TRISBbits.TRISB4
#define IO_RELAX0_LAT                  LATBbits.LATB4
#define IO_RELAX0_PORT                 PORTBbits.RB4
#define IO_RELAX0_WPU                  WPUBbits.WPUB4
#define IO_RELAX0_OD                   ODCONBbits.ODCB4
#define IO_RELAX0_ANS                  ANSELBbits.ANSB4
#define IO_RELAX0_SetHigh()            do { LATBbits.LATB4 = 1; } while(0)
#define IO_RELAX0_SetLow()             do { LATBbits.LATB4 = 0; } while(0)
#define IO_RELAX0_Toggle()             do { LATBbits.LATB4 = ~LATBbits.LATB4; } while(0)
#define IO_RELAX0_GetValue()           PORTBbits.RB4
#define IO_RELAX0_SetDigitalInput()    do { TRISBbits.TRISB4 = 1; } while(0)
#define IO_RELAX0_SetDigitalOutput()   do { TRISBbits.TRISB4 = 0; } while(0)
#define IO_RELAX0_SetPullup()          do { WPUBbits.WPUB4 = 1; } while(0)
#define IO_RELAX0_ResetPullup()        do { WPUBbits.WPUB4 = 0; } while(0)
#define IO_RELAX0_SetPushPull()        do { ODCONBbits.ODCB4 = 0; } while(0)
#define IO_RELAX0_SetOpenDrain()       do { ODCONBbits.ODCB4 = 1; } while(0)
#define IO_RELAX0_SetAnalogMode()      do { ANSELBbits.ANSB4 = 1; } while(0)
#define IO_RELAX0_SetDigitalMode()     do { ANSELBbits.ANSB4 = 0; } while(0)

// get/set IO_RELAX1 aliases
#define IO_RELAX1_TRIS                 TRISBbits.TRISB5
#define IO_RELAX1_LAT                  LATBbits.LATB5
#define IO_RELAX1_PORT                 PORTBbits.RB5
#define IO_RELAX1_WPU                  WPUBbits.WPUB5
#define IO_RELAX1_OD                   ODCONBbits.ODCB5
#define IO_RELAX1_ANS                  ANSELBbits.ANSB5
#define IO_RELAX1_SetHigh()            do { LATBbits.LATB5 = 1; } while(0)
#define IO_RELAX1_SetLow()             do { LATBbits.LATB5 = 0; } while(0)
#define IO_RELAX1_Toggle()             do { LATBbits.LATB5 = ~LATBbits.LATB5; } while(0)
#define IO_RELAX1_GetValue()           PORTBbits.RB5
#define IO_RELAX1_SetDigitalInput()    do { TRISBbits.TRISB5 = 1; } while(0)
#define IO_RELAX1_SetDigitalOutput()   do { TRISBbits.TRISB5 = 0; } while(0)
#define IO_RELAX1_SetPullup()          do { WPUBbits.WPUB5 = 1; } while(0)
#define IO_RELAX1_ResetPullup()        do { WPUBbits.WPUB5 = 0; } while(0)
#define IO_RELAX1_SetPushPull()        do { ODCONBbits.ODCB5 = 0; } while(0)
#define IO_RELAX1_SetOpenDrain()       do { ODCONBbits.ODCB5 = 1; } while(0)
#define IO_RELAX1_SetAnalogMode()      do { ANSELBbits.ANSB5 = 1; } while(0)
#define IO_RELAX1_SetDigitalMode()     do { ANSELBbits.ANSB5 = 0; } while(0)

// get/set IO_RELAX2 aliases
#define IO_RELAX2_TRIS                 TRISBbits.TRISB6
#define IO_RELAX2_LAT                  LATBbits.LATB6
#define IO_RELAX2_PORT                 PORTBbits.RB6
#define IO_RELAX2_WPU                  WPUBbits.WPUB6
#define IO_RELAX2_OD                   ODCONBbits.ODCB6
#define IO_RELAX2_ANS                  ANSELBbits.ANSB6
#define IO_RELAX2_SetHigh()            do { LATBbits.LATB6 = 1; } while(0)
#define IO_RELAX2_SetLow()             do { LATBbits.LATB6 = 0; } while(0)
#define IO_RELAX2_Toggle()             do { LATBbits.LATB6 = ~LATBbits.LATB6; } while(0)
#define IO_RELAX2_GetValue()           PORTBbits.RB6
#define IO_RELAX2_SetDigitalInput()    do { TRISBbits.TRISB6 = 1; } while(0)
#define IO_RELAX2_SetDigitalOutput()   do { TRISBbits.TRISB6 = 0; } while(0)
#define IO_RELAX2_SetPullup()          do { WPUBbits.WPUB6 = 1; } while(0)
#define IO_RELAX2_ResetPullup()        do { WPUBbits.WPUB6 = 0; } while(0)
#define IO_RELAX2_SetPushPull()        do { ODCONBbits.ODCB6 = 0; } while(0)
#define IO_RELAX2_SetOpenDrain()       do { ODCONBbits.ODCB6 = 1; } while(0)
#define IO_RELAX2_SetAnalogMode()      do { ANSELBbits.ANSB6 = 1; } while(0)
#define IO_RELAX2_SetDigitalMode()     do { ANSELBbits.ANSB6 = 0; } while(0)

// get/set IO_RELAX3 aliases
#define IO_RELAX3_TRIS                 TRISBbits.TRISB7
#define IO_RELAX3_LAT                  LATBbits.LATB7
#define IO_RELAX3_PORT                 PORTBbits.RB7
#define IO_RELAX3_WPU                  WPUBbits.WPUB7
#define IO_RELAX3_OD                   ODCONBbits.ODCB7
#define IO_RELAX3_ANS                  ANSELBbits.ANSB7
#define IO_RELAX3_SetHigh()            do { LATBbits.LATB7 = 1; } while(0)
#define IO_RELAX3_SetLow()             do { LATBbits.LATB7 = 0; } while(0)
#define IO_RELAX3_Toggle()             do { LATBbits.LATB7 = ~LATBbits.LATB7; } while(0)
#define IO_RELAX3_GetValue()           PORTBbits.RB7
#define IO_RELAX3_SetDigitalInput()    do { TRISBbits.TRISB7 = 1; } while(0)
#define IO_RELAX3_SetDigitalOutput()   do { TRISBbits.TRISB7 = 0; } while(0)
#define IO_RELAX3_SetPullup()          do { WPUBbits.WPUB7 = 1; } while(0)
#define IO_RELAX3_ResetPullup()        do { WPUBbits.WPUB7 = 0; } while(0)
#define IO_RELAX3_SetPushPull()        do { ODCONBbits.ODCB7 = 0; } while(0)
#define IO_RELAX3_SetOpenDrain()       do { ODCONBbits.ODCB7 = 1; } while(0)
#define IO_RELAX3_SetAnalogMode()      do { ANSELBbits.ANSB7 = 1; } while(0)
#define IO_RELAX3_SetDigitalMode()     do { ANSELBbits.ANSB7 = 0; } while(0)

// get/set IO_LEDG0 aliases
#define IO_LEDG0_TRIS                 TRISCbits.TRISC0
#define IO_LEDG0_LAT                  LATCbits.LATC0
#define IO_LEDG0_PORT                 PORTCbits.RC0
#define IO_LEDG0_WPU                  WPUCbits.WPUC0
#define IO_LEDG0_OD                   ODCONCbits.ODCC0
#define IO_LEDG0_ANS                  ANSELCbits.ANSC0
#define IO_LEDG0_SetHigh()            do { LATCbits.LATC0 = 1; } while(0)
#define IO_LEDG0_SetLow()             do { LATCbits.LATC0 = 0; } while(0)
#define IO_LEDG0_Toggle()             do { LATCbits.LATC0 = ~LATCbits.LATC0; } while(0)
#define IO_LEDG0_GetValue()           PORTCbits.RC0
#define IO_LEDG0_SetDigitalInput()    do { TRISCbits.TRISC0 = 1; } while(0)
#define IO_LEDG0_SetDigitalOutput()   do { TRISCbits.TRISC0 = 0; } while(0)
#define IO_LEDG0_SetPullup()          do { WPUCbits.WPUC0 = 1; } while(0)
#define IO_LEDG0_ResetPullup()        do { WPUCbits.WPUC0 = 0; } while(0)
#define IO_LEDG0_SetPushPull()        do { ODCONCbits.ODCC0 = 0; } while(0)
#define IO_LEDG0_SetOpenDrain()       do { ODCONCbits.ODCC0 = 1; } while(0)
#define IO_LEDG0_SetAnalogMode()      do { ANSELCbits.ANSC0 = 1; } while(0)
#define IO_LEDG0_SetDigitalMode()     do { ANSELCbits.ANSC0 = 0; } while(0)

// get/set IO_LEDG1 aliases
#define IO_LEDG1_TRIS                 TRISCbits.TRISC1
#define IO_LEDG1_LAT                  LATCbits.LATC1
#define IO_LEDG1_PORT                 PORTCbits.RC1
#define IO_LEDG1_WPU                  WPUCbits.WPUC1
#define IO_LEDG1_OD                   ODCONCbits.ODCC1
#define IO_LEDG1_ANS                  ANSELCbits.ANSC1
#define IO_LEDG1_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define IO_LEDG1_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define IO_LEDG1_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define IO_LEDG1_GetValue()           PORTCbits.RC1
#define IO_LEDG1_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define IO_LEDG1_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define IO_LEDG1_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define IO_LEDG1_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define IO_LEDG1_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define IO_LEDG1_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define IO_LEDG1_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define IO_LEDG1_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set IO_LEDG2 aliases
#define IO_LEDG2_TRIS                 TRISCbits.TRISC2
#define IO_LEDG2_LAT                  LATCbits.LATC2
#define IO_LEDG2_PORT                 PORTCbits.RC2
#define IO_LEDG2_WPU                  WPUCbits.WPUC2
#define IO_LEDG2_OD                   ODCONCbits.ODCC2
#define IO_LEDG2_ANS                  ANSELCbits.ANSC2
#define IO_LEDG2_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define IO_LEDG2_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define IO_LEDG2_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define IO_LEDG2_GetValue()           PORTCbits.RC2
#define IO_LEDG2_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define IO_LEDG2_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define IO_LEDG2_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define IO_LEDG2_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define IO_LEDG2_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define IO_LEDG2_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define IO_LEDG2_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define IO_LEDG2_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set IO_LEDG3 aliases
#define IO_LEDG3_TRIS                 TRISCbits.TRISC3
#define IO_LEDG3_LAT                  LATCbits.LATC3
#define IO_LEDG3_PORT                 PORTCbits.RC3
#define IO_LEDG3_WPU                  WPUCbits.WPUC3
#define IO_LEDG3_OD                   ODCONCbits.ODCC3
#define IO_LEDG3_ANS                  ANSELCbits.ANSC3
#define IO_LEDG3_SetHigh()            do { LATCbits.LATC3 = 1; } while(0)
#define IO_LEDG3_SetLow()             do { LATCbits.LATC3 = 0; } while(0)
#define IO_LEDG3_Toggle()             do { LATCbits.LATC3 = ~LATCbits.LATC3; } while(0)
#define IO_LEDG3_GetValue()           PORTCbits.RC3
#define IO_LEDG3_SetDigitalInput()    do { TRISCbits.TRISC3 = 1; } while(0)
#define IO_LEDG3_SetDigitalOutput()   do { TRISCbits.TRISC3 = 0; } while(0)
#define IO_LEDG3_SetPullup()          do { WPUCbits.WPUC3 = 1; } while(0)
#define IO_LEDG3_ResetPullup()        do { WPUCbits.WPUC3 = 0; } while(0)
#define IO_LEDG3_SetPushPull()        do { ODCONCbits.ODCC3 = 0; } while(0)
#define IO_LEDG3_SetOpenDrain()       do { ODCONCbits.ODCC3 = 1; } while(0)
#define IO_LEDG3_SetAnalogMode()      do { ANSELCbits.ANSC3 = 1; } while(0)
#define IO_LEDG3_SetDigitalMode()     do { ANSELCbits.ANSC3 = 0; } while(0)

// get/set IO_LEDG4 aliases
#define IO_LEDG4_TRIS                 TRISCbits.TRISC4
#define IO_LEDG4_LAT                  LATCbits.LATC4
#define IO_LEDG4_PORT                 PORTCbits.RC4
#define IO_LEDG4_WPU                  WPUCbits.WPUC4
#define IO_LEDG4_OD                   ODCONCbits.ODCC4
#define IO_LEDG4_ANS                  ANSELCbits.ANSC4
#define IO_LEDG4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define IO_LEDG4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define IO_LEDG4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define IO_LEDG4_GetValue()           PORTCbits.RC4
#define IO_LEDG4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define IO_LEDG4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define IO_LEDG4_SetPullup()          do { WPUCbits.WPUC4 = 1; } while(0)
#define IO_LEDG4_ResetPullup()        do { WPUCbits.WPUC4 = 0; } while(0)
#define IO_LEDG4_SetPushPull()        do { ODCONCbits.ODCC4 = 0; } while(0)
#define IO_LEDG4_SetOpenDrain()       do { ODCONCbits.ODCC4 = 1; } while(0)
#define IO_LEDG4_SetAnalogMode()      do { ANSELCbits.ANSC4 = 1; } while(0)
#define IO_LEDG4_SetDigitalMode()     do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set IO_LEDG5 aliases
#define IO_LEDG5_TRIS                 TRISCbits.TRISC5
#define IO_LEDG5_LAT                  LATCbits.LATC5
#define IO_LEDG5_PORT                 PORTCbits.RC5
#define IO_LEDG5_WPU                  WPUCbits.WPUC5
#define IO_LEDG5_OD                   ODCONCbits.ODCC5
#define IO_LEDG5_ANS                  ANSELCbits.ANSC5
#define IO_LEDG5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define IO_LEDG5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define IO_LEDG5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define IO_LEDG5_GetValue()           PORTCbits.RC5
#define IO_LEDG5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define IO_LEDG5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define IO_LEDG5_SetPullup()          do { WPUCbits.WPUC5 = 1; } while(0)
#define IO_LEDG5_ResetPullup()        do { WPUCbits.WPUC5 = 0; } while(0)
#define IO_LEDG5_SetPushPull()        do { ODCONCbits.ODCC5 = 0; } while(0)
#define IO_LEDG5_SetOpenDrain()       do { ODCONCbits.ODCC5 = 1; } while(0)
#define IO_LEDG5_SetAnalogMode()      do { ANSELCbits.ANSC5 = 1; } while(0)
#define IO_LEDG5_SetDigitalMode()     do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set IO_LEDG6 aliases
#define IO_LEDG6_TRIS                 TRISCbits.TRISC6
#define IO_LEDG6_LAT                  LATCbits.LATC6
#define IO_LEDG6_PORT                 PORTCbits.RC6
#define IO_LEDG6_WPU                  WPUCbits.WPUC6
#define IO_LEDG6_OD                   ODCONCbits.ODCC6
#define IO_LEDG6_ANS                  ANSELCbits.ANSC6
#define IO_LEDG6_SetHigh()            do { LATCbits.LATC6 = 1; } while(0)
#define IO_LEDG6_SetLow()             do { LATCbits.LATC6 = 0; } while(0)
#define IO_LEDG6_Toggle()             do { LATCbits.LATC6 = ~LATCbits.LATC6; } while(0)
#define IO_LEDG6_GetValue()           PORTCbits.RC6
#define IO_LEDG6_SetDigitalInput()    do { TRISCbits.TRISC6 = 1; } while(0)
#define IO_LEDG6_SetDigitalOutput()   do { TRISCbits.TRISC6 = 0; } while(0)
#define IO_LEDG6_SetPullup()          do { WPUCbits.WPUC6 = 1; } while(0)
#define IO_LEDG6_ResetPullup()        do { WPUCbits.WPUC6 = 0; } while(0)
#define IO_LEDG6_SetPushPull()        do { ODCONCbits.ODCC6 = 0; } while(0)
#define IO_LEDG6_SetOpenDrain()       do { ODCONCbits.ODCC6 = 1; } while(0)
#define IO_LEDG6_SetAnalogMode()      do { ANSELCbits.ANSC6 = 1; } while(0)
#define IO_LEDG6_SetDigitalMode()     do { ANSELCbits.ANSC6 = 0; } while(0)

// get/set IO_BUZZER aliases
#define IO_BUZZER_TRIS                 TRISCbits.TRISC7
#define IO_BUZZER_LAT                  LATCbits.LATC7
#define IO_BUZZER_PORT                 PORTCbits.RC7
#define IO_BUZZER_WPU                  WPUCbits.WPUC7
#define IO_BUZZER_OD                   ODCONCbits.ODCC7
#define IO_BUZZER_ANS                  ANSELCbits.ANSC7
#define IO_BUZZER_SetHigh()            do { LATCbits.LATC7 = 1; } while(0)
#define IO_BUZZER_SetLow()             do { LATCbits.LATC7 = 0; } while(0)
#define IO_BUZZER_Toggle()             do { LATCbits.LATC7 = ~LATCbits.LATC7; } while(0)
#define IO_BUZZER_GetValue()           PORTCbits.RC7
#define IO_BUZZER_SetDigitalInput()    do { TRISCbits.TRISC7 = 1; } while(0)
#define IO_BUZZER_SetDigitalOutput()   do { TRISCbits.TRISC7 = 0; } while(0)
#define IO_BUZZER_SetPullup()          do { WPUCbits.WPUC7 = 1; } while(0)
#define IO_BUZZER_ResetPullup()        do { WPUCbits.WPUC7 = 0; } while(0)
#define IO_BUZZER_SetPushPull()        do { ODCONCbits.ODCC7 = 0; } while(0)
#define IO_BUZZER_SetOpenDrain()       do { ODCONCbits.ODCC7 = 1; } while(0)
#define IO_BUZZER_SetAnalogMode()      do { ANSELCbits.ANSC7 = 1; } while(0)
#define IO_BUZZER_SetDigitalMode()     do { ANSELCbits.ANSC7 = 0; } while(0)

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


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCAF7 pin functionality
 * @Example
    IOCAF7_ISR();
 */
void IOCAF7_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCAF7 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCAF7 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF7_SetInterruptHandler(MyInterruptHandler);

*/
void IOCAF7_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCAF7 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCAF7_SetInterruptHandler() method.
    This handler is called every time the IOCAF7 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF7_SetInterruptHandler(IOCAF7_InterruptHandler);

*/
extern void (*IOCAF7_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCAF7 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCAF7_SetInterruptHandler() method.
    This handler is called every time the IOCAF7 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCAF7_SetInterruptHandler(IOCAF7_DefaultInterruptHandler);

*/
void IOCAF7_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/