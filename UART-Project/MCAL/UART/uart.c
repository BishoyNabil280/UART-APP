/******************************************************************************
 *
 * Module: UART
 * Author: Bishoy Nabil
 *
 *******************************************************************************/

#include "uart.h"


#define BAUD_PRESCALE (((F_CPU/(UART_BAUDRATE* 8UL))) - 1)

/***************              Functions Definitions              ***************/
void UART_init(void)
{
	/* U2X = 1 for double transmission speed */
	UCSRA_REG = (1<<U2X);
	UCSRB_REG = (1<<RXEN) | (1<<TXEN);
	UCSRC_REG = (1<<URSEL) | (1<<UCSZ0) | (1<<UCSZ1);
	/* First 8 bits from the UART BAUD RATE REGISTER inside UBRRL and last 4 bits in UBRRH*/
	UBRRH_REG = BAUD_PRESCALE>>8;
	UBRRL_REG = BAUD_PRESCALE;
}

void UART_sendByte(const uint8_t data)
{
	/* UDRE Flag is set when the TX Buffer is ready to recieve new data to transmit */
	while(BIT_IS_CLEAR(UCSRA_REG,UDRE)){}
	UDR_REG = data;
}

uint8_t UART_recieveByte(void)
{
	/* RXC flag is set when the UART receive data */
	while(BIT_IS_CLEAR(UCSRA_REG,RXC)){}
	return UDR_REG;
}

void UART_sendString(const uint8_t *Str)
{
	uint8_t i = 0;
	while(Str[i] != '\0')
	{
		UART_sendByte(Str[i]);
		i++;
	}
}


void UART_receiveString(uint8_t *Str)
{
	uint8_t i = 0;
	Str[i] = UART_recieveByte();
	while(Str[i] != '\x0D')
	{
		i++;
		Str[i] = UART_recieveByte();
	}
	Str[i] = '\0';
}
