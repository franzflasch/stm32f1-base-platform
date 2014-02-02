/*
 * main.h
 *
 *  Created on: Feb 1, 2014
 *      Author: franz
 */

#ifndef MAIN_H_
#define MAIN_H_

#include <usart.h>

#define UART_BUF_LEN 256

typedef struct AppWa_s
{
	uartInfo_t uartInfo;

}AppWa_t;

/* Application specific declarations */
extern char UartBuffer[UART_BUF_LEN];
extern AppWa_t applicationData;

#endif /* MAIN_H_ */
