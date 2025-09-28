/*
 * uart.c
 *
 *  Created on: Sep 25, 2025
 *      Author: sunbeam
 */
#include"uart.h"

void UartInit(uint32_t baud){
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	GPIOA-> PUPDR &= ~(BV(4)| BV(5) | BV(6)|BV(7));

	GPIOA->MODER &= ~(BV(4)|BV(6));
	GPIOA->MODER |=(BV(5)| BV(7));

	GPIOA->AFR[0] &= ~(BV(15)|BV(11));
	GPIOA->AFR[0] |= (BV(14)|BV(13)|BV(12)|BV(10)|BV(9)| BV(8));

	RCC->APB1ENR |= RCC_APB1ENR_USART2EN;

	USART2->CR1 = USART_CR1_UE;

	if (baud ==9600)
		USART2->BRR = 0x0683;
	else if(baud == 38400)
		USART2->BRR = 0x01A1;
	else if(baud ==115200)
		USART2->BRR = 0x008B;

	USART2->CR1 |= USART_CR1_UE;
}
void UartPutch(int ch){
	USART2->DR =ch;
	while((USART2->SR & USART_SR_TXE)==0);
}
void UartPuts(char *str){
	int i;
	for(i=0;str[i]!='\0';i++)
		UartPutch(str[i]);
}
int UartGetch(void){
	while ((USART2-> SR & USART_SR_RXNE)==0);
	return (int)USART2->DR;
}
void UartGets(char *str){
	int i=0;
	char ch;
	do{
		ch = UartGetch();
		str[i] =ch;
		i++;
	}while(ch !='\r');
	str[i] ='\n';
	i++;
	str[i]='\0';
}
