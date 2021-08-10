/*
 * app.h
 *
 *      Author: Bishoy Nabil
 */

#ifndef APP_H_
#define APP_H_

#include "../MCAL/DIO/DIO.h"
#include "../micro_config.h"
#include "../MCAL/UART/uart.h"
#include "../compiler.h"
#include "../common_macros.h"

/****** APIs *******/
void System_Init();
void System_Update();

#endif /* APP_H_ */
