/*
 * uart.h
 *
 *  Created on: Sep 25, 2025
 *      Author: sunbeam
 */

#ifndef UART_H_
#define UART_H_

#include "stm32f4xx.h"

void UartInit(uint32_t baud);
void UartPutch(int ch);
void UartPuts(char *str);
int UartGetch(void);
void UartGets(char *str);

#endif /* UART_H_ */
