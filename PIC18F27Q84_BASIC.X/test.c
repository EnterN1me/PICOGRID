/*
 * File:   test.c
 * Author: EnterN1me
 *
 * Created on May 12, 2025, 2:50 PM
 */
#include "test.h"

void led_test(void)
{
/*
 Test pic board hadware by making led blink
 */
    while(1)
        {
        led2_LAT = (led1_LAT && led0_LAT) ? !led2_LAT : led2_LAT ;
        led1_LAT = (led0_LAT) ? !led1_LAT : led1_LAT ;
        led0_Toggle();
        __delay_ms(1000);
    }
}

void can_receive_test()
{
/*
 Test can receiving message
 3 first byte of can bus give command to one of the led each
 0x00: led off
 other: led on
 */
    while(1)
    {
        if(can_receive()>=3){
            led0_LAT = rx_buff[0]; //change with gpio for lights
            led1_LAT = rx_buff[1]; //change with gpio for lights
            led2_LAT = rx_buff[2]; //change with gpio for lights
        
        }
    }
 }

void can_send_test()
{
/*
 Test can sending message
 send message :
 at id 0x444
 */
    tx_data[0] = 0x40; 
    tx_data[1] = 0x11; 
    tx_data[2] = 0x22; 
    tx_data[3] = 0x33; 
    tx_data[4] = 0x44; 
    tx_data[5] = 0x55; 
    tx_data[6] = 0x66; 
    tx_data[7] = 0x77; 
  
    while(1)
    {
        can_send((uint32_t)0x444);
    }
}
