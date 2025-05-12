/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC18F27Q84
        Driver Version    :  2.00
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

#include "mcc_generated_files/mcc.h"
#include <string.h>

#include "test.h"
//#include "can_bus.h"

/*
 RC2 is led 0
 RC3 is led 1
 RC4 is led 2
 */
/*
CAN_MSG_OBJ msg_tx;    // TX message object
uint8_t tx_data[8];    // TX data bytes buffer
//uint8_t tx_success; // transmission flag
*/

//can tx
CAN_MSG_OBJ msg_tx;
uint8_t tx_data[8];
uint8_t tx_success;
CAN_TX_MSG_REQUEST_STATUS tx_status ;

//can rx
CAN_MSG_OBJ msg_rx;    // RX message object
uint8_t rx_buff[DLC_8];  // RX data bytes buffer
uint8_t nrMsg; // number of messages available

//mppt
float V_bat, V_pv, I_pv, P_pv, V_prev = 50.0, P_prev = 300.0;
float duty_cycle = 50.0;
float max_duty, min_duty;
const float DUTY_CYCLE_STEP = 0.1;


void can_send();
void can_receive();
void can_light_command();
void mppt_loop();

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    memset( &msg_rx, 0 , sizeof(msg_rx) );
    
    nrMsg = 0;
    //led_test();
  __delay_ms(50);

    while (1)
    {
        //led2_Toggle();
        //led0_Toggle();
        __delay_ms(50);
        //__delay_ms(4000);
        
        //can_send();
        can_light_command();
    }
}

/*
void mppt_loop()
{
    while (1) {
        ADC_SelectContext(CONTEXT_1);
    	V_pv = ADC_GetSingleConversion(channel_ANA0) * (5.0 / 1023.0);
        
        ADC_SelectContext(CONTEXT_2);
    	I_pv = ADC_GetSingleConversion(channel_ANA0) * (5.0 / 1023.0);
        
        ADC_SelectContext(CONTEXT_3);
    	V_bat = ADC_GetSingleConversion(channel_ANA0) * (5.0 / 1023.0);

    	P_pv = V_pv * I_pv;

    	if (P_pv > P_prev) {
        		if (V_pv > V_prev) {
          			duty_cycle -= DUTY_CYCLE_STEP;
    		} else {
        			duty_cycle += DUTY_CYCLE_STEP;
    		}
	} else {
    		if (V_pv > V_prev) {
        			duty_cycle += DUTY_CYCLE_STEP;
    		} else {
        			duty_cycle -= DUTY_CYCLE_STEP;
    		}
	}

    	min_duty = 2 * V_bat - 2;
    	max_duty = min_duty + 1;
    	if (duty_cycle > max_duty) duty_cycle = max_duty;
    	if (duty_cycle < min_duty) duty_cycle = min_duty;

    	setPWM(duty_cycle / 100.0);

    	P_prev = P_pv;
    	V_prev = V_pv;

    	__delay_ms(100);
	}
}
 * */


  
void can_receive()
{
    nrMsg = CAN1_ReceivedMessageCountGet();
    if(nrMsg > 0) 
    {
        if(true == CAN1_Receive(&msg_rx))
       {
           for(uint8_t i=0; i<msg_rx.field.dlc; i++)
           {
             rx_buff[i] = msg_rx.data[i];
           }
           if(msg_rx.field.dlc>0)
           {
            //do something with rx_buff
          }
      }
      nrMsg--;
    }  
 }


void can_light_command()
{
    nrMsg = CAN1_ReceivedMessageCountGet();
    if(nrMsg > 0) 
    {
        if(true == CAN1_Receive(&msg_rx))
       {
           for(uint8_t i=0; i<msg_rx.field.dlc; i++)
           {
             rx_buff[i] = msg_rx.data[i];
           }
           if(msg_rx.field.dlc>0)
           {
            led0_LAT = rx_buff[0]; //change with gpio for lights
            led1_LAT = rx_buff[1]; //change with gpio for lights
            led2_LAT = rx_buff[2]; //change with gpio for lights
          }
      }
      nrMsg--;
   }  
 }


void can_send()
{
    memset( &msg_tx, 0 , sizeof(msg_tx) );// initialize all message bytes with 0
    
    msg_tx.msgId    = 0x444;       // message ID
    msg_tx.field.formatType = CAN_2_0_FORMAT;
    msg_tx.field.brs = CAN_NON_BRS_MODE;    
    msg_tx.field.frameType = CAN_FRAME_DATA;
    msg_tx.field.idType = CAN_FRAME_STD;
    msg_tx.field.dlc = DLC_8;         // message length
    msg_tx.data = tx_data;          // set pointer to tx data buffer
 
    tx_data[0] = 0x40; // led command
    tx_data[1] = 0x11; // dummy data
    tx_data[2] = 0x22; // dummy data
    tx_data[3] = 0x33; // dummy data
    tx_data[4] = 0x40; // dummy data
    tx_data[5] = 0x50; // dummy data
    tx_data[6] = 0x60; // dummy data
    tx_data[7] = 0x70; // dummy data
  
    if(CAN_TX_FIFO_AVAILABLE == (CAN1_TransmitFIFOStatusGet(TXQ) & CAN_TX_FIFO_AVAILABLE))
    {
        tx_status = CAN1_Transmit(TXQ, &msg_tx); // transmit the CAN message
    }
    return;
}
