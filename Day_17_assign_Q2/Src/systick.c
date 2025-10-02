/*
 * systick.c
 *
 *  Created on: Oct 1, 2025
 *      Author: sunbeam
 */
#include"systick.h"

uint32_t xTicks=0;
void SysTick_Handler(void) {
	xTicks++;
}
// Create a Delay Fn using SysTick
void SysTick_DelayMs(uint32_t ms) {
	// get current number of ticks
	uint32_t curTicks = xTicks;
	// wait for "ms" more ticks (1 tick per ms).
	uint32_t waitTill = curTicks + ms;
	while(xTicks < waitTill);
}

