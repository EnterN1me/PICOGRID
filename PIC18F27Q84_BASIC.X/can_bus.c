#include "can_bus.h"

struct Can_Errors get_can_errors(){
    struct Can_Errors can_errors;
    can_errors.errors_tx   = CAN1_IsTxErrorPassive();
    can_errors.errors_rx   = CAN1_IsRxErrorPassive();
    can_errors.errors_busoff = CAN1_IsBusOff();
    return can_errors;
}

void can_send()
{
    /*
     This function send tx_data data in a can bus message
     */
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

int can_receive()
{
    /*
     This function receive can message and pass it to rx_buff buffer
     */
    nrMsg = CAN1_ReceivedMessageCountGet();
    if (nrMsg > 0)
    {
        if(true == CAN1_Receive(&msg_rx))
        {
           for(uint8_t i=0; i<msg_rx.field.dlc; i++)
           {
             rx_buff[i] = msg_rx.data[i];
           }
           return msg_rx.field.dlc;
        }
    }
    return -1;
}
