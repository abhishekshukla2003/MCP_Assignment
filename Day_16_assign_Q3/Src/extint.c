/*
 * extint.c
 *
 *  Created on: Sep 16, 2025
 *      Author: sunbeam
 */

#include"extint.h"

#include "stm32f4xx.h"  // Adjust to your STM32 series
#define BV(x) (1U << (x))

volatile int ext_flag =0;
// 1 = increasing, 0 = decreasing

void extint_init(void)
{
    // 1. Enable clock for GPIOA and SYSCFG
    RCC->AHB1ENR |= BV(0);       // Enable GPIOA clock (bit 0)
    RCC->APB2ENR |= BV(14);      // Enable SYSCFG clock (bit 14)

    // 2. Configure PA0 as input (MODER = 00), no pull-up/down (PUPDR = 00)
    GPIOA->MODER &= ~(BV(0) | BV(1));
    GPIOA->PUPDR &= ~(BV(0) | BV(1));

    // 3. Connect EXTI0 to PA0
    SYSCFG->EXTICR[0] &= ~(0xF);  // EXTI0 = PA0

    // 4. Configure EXTI0: enable interrupt mask and rising edge trigger
    EXTI->IMR  |= BV(0);     // Unmask EXTI0
    EXTI->RTSR |= BV(0);     // Rising edge trigger
    EXTI->FTSR &= ~BV(0);    // Disable falling edge trigger

    // 5. Enable EXTI0 interrupt in NVIC
    NVIC_EnableIRQ(EXTI0_IRQn);
}

void EXTI0_IRQHandler(void)
{
    EXTI->PR |=BV(0); // Check if EXTI0 triggered

      ext_flag=1;  // Clear EXTI0 pending bit by writing 1

}







