/*
 * systick.h
 *
 *  Created on: Oct 1, 2025
 *      Author: sunbeam
 */
#include"stm32f4xx.h"
#ifndef SYSTICK_H_
#define SYSTICK_H_

void SysTick_DelayMs(uint32_t);
void SysTick_Handler(void);


#endif /* SYSTICK_H_ */
