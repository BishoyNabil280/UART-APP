 /******************************************************************************
 *
 * Module: UART
 *
 * File Name: uart.h
 *
 * Author: Bishoy Nabil
 *
 *******************************************************************************/

#ifndef UART_H_
#define UART_H_

#include "../../compiler.h"
#include "../../common_macros.h"
#include "../../micro_config.h"
#include "uart_registers.h"


/* Baud Rate */
#define UART_BAUDRATE 9600




/**************           APIs           **************/
void UART_init(void);

void UART_sendByte(const uint8_t data);

uint8_t UART_recieveByte(void);

void UART_sendString(const uint8_t *Str);

void UART_receiveString(uint8_t *Str); // Receive until #

#endif /* UART_H_ */
