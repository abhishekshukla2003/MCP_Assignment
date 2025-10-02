/*
 * timer.c
 *
 *  Created on: Sep 29, 2025
 *      Author: Sunbeam
 */

#include "timer.h"

int GC=0;
void TimerInit(uint32_t ms) {
	// Enable Timer APB clock
	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
	// Set the Prescalar
	TIM6->PSC = PR - 1;
	// calculate number of clocks to count
	uint32_t cnt = (FPCLK / 1000) * ms / PR;
	// set max count in ARR
	TIM6->ARR = cnt - 1;
	// start counting from zero
	TIM6->CNT = 0;
	// enable the timer interrupt in peripheral
	TIM6->DIER |= TIM_DIER_UIE;
	// enable the timer interrupt in NVIC
	NVIC_EnableIRQ(TIM6_DAC_IRQn);
	// enable timer clock (mandatory) and set APRE (optional)
	TIM6->CR1 |= TIM_CR1_CEN;
	TIM6->CR2 |= BV(5);     //ENABLE UPDATE EVENT
}

// implement Interrupt Handler for TIM6
void TIM6_DAC_IRQHandler(void) {
	// check if TIM6 interrupt occurred.
	if(TIM6->SR & TIM_SR_UIF) {
		// Handle TIM6 interrupt - Toggle LED
		GC=1;
		// Clear/Ack TIM6 interrupt
		TIM6->SR &= ~TIM_SR_UIF;
	}
}


