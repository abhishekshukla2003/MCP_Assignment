/*
 * timer.h
 *
 *  Created on: Sep 29, 2025
 *      Author: Sunbeam
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "stm32f4xx.h"

#define FPCLK	16000000UL
#define PR		16000

void TimerInit(uint32_t ms);

#endif /* TIMER_H_ */
