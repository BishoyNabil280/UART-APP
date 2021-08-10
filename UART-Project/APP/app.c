/*
 * app.c
 *
 *      Author: Bishoy Nabil
 */

#include "app.h"

uint8_t Str[20];
uint8_t Data[20]="START";
uint8_t Wait[20]="WAIT";
uint8_t Stop[20]="STOP";
uint8_t AT[3]="AT";

void System_Init()
{
	UART_init();
	DIO_setPinDirection(PortD,Pin2,OUTPUT);
	DIO_setPinDirection(PortD,Pin3,OUTPUT);
	DIO_setPinDirection(PortD,Pin4,OUTPUT);
}

void System_Update()
{
	/* Receive byte from terminal */
			UART_receiveString(Str);
			if(strcmp(Str,Data)==0)  //START Case
			{
				DIO_writePin(PortD, Pin2, HIGH);
				DIO_writePin(PortD, Pin3, LOW);
				DIO_writePin(PortD, Pin4, LOW);
				UART_sendString("Green LED is on\r");
			}else if(strcmp(Str,Wait)==0)  //WAIT Case
			{
				DIO_writePin(PortD, Pin2, LOW);
				DIO_writePin(PortD, Pin3, HIGH);
				DIO_writePin(PortD, Pin4, LOW);
				UART_sendString("Yellow LED is on\r");
			}else if(strcmp(Str,Stop)==0)  //STOP Case
			{
				DIO_writePin(PortD, Pin2, LOW);
				DIO_writePin(PortD, Pin3, LOW);
				DIO_writePin(PortD, Pin4, HIGH);
				UART_sendString("Red LED is on\r");
				UART_receiveString(Str);
			}else if(strcmp(Str,AT)==0)  //AT Case
			{
				UART_sendString("OK\r");
			}else
			{
				UART_sendString("Invalid Entry!\r");
			}
}
