/*
 * File:   test.c
 * Author: EnterN1me
 *
 * Created on May 12, 2025, 2:50 PM
 */

#include "mcc_generated_files/mcc.h"
#include <xc.h>
#include "test.h"

void led_test()
{
    while(1)
    {
    //led2_LAT = (led1_LAT) ? !led2_LAT : led2_LAT ;
    led1_LAT = (led0_LAT) ? !led1_LAT : led1_LAT ;
    led0_Toggle();
    __delay_ms(1000);
    }
}
