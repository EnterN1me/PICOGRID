/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CAN_H //ATTENTION FAUT LES CHANGER DU TRUC DE BASE !!!!
#define	CAN_H

#include <xc.h> // include processor files - each processor file is guarded. 
#include "mcc_generated_files/can1.h" //can module auto generated function
#include <string.h>

struct Can_Errors { 
uint8_t errors_tx; // TX error passive
uint8_t errors_rx; // RX error passive
uint8_t errors_busoff; // bus off error
};

//tx
CAN_MSG_OBJ msg_tx;
uint8_t tx_data[8];
uint8_t tx_success;
CAN_TX_MSG_REQUEST_STATUS tx_status ;

//rx
CAN_MSG_OBJ msg_rx;    // RX message object
uint8_t rx_buff[DLC_8];  // RX data bytes buffer
uint8_t nrMsg; // number of messages available

struct Can_Errors get_can_errors();
void can_send(uint32_t id);
int can_receive();

#endif	/* CAN_H */

