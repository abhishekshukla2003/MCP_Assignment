/*
 * led.c
 *
 *  Created on: Sep 13, 2025
 *      Author: sunbeam
 */
#include"led.h"

void led_init(void)
{
	RCC->AHB1ENR |= BV(3);

	GPIOD->MODER |=  (BV(24) |BV(26) | BV(28)| BV(30));

	GPIOD->MODER &= ~(BV(25) |BV(27) | BV(29) | BV(31));

	GPIOD->OTYPER &= ~(BV(12) | BV(13) | BV(14) | BV(15));

	GPIOD->OSPEEDR &= ~(BV(24) | BV(26) |BV(28) |BV(30));
	GPIOD->OSPEEDR &= ~(BV(25) | BV(27) |BV(29) |BV(31));

	GPIOD->PUPDR  &= ~(BV(24) | BV(26) |BV(28) |BV(30));
	GPIOD->PUPDR  &= ~(BV(25) | BV(27) |BV(29) |BV(31));
}
void led_on(void)
{
	GPIOD->ODR |=BV(12)|BV(13) |BV(14) |BV(15);

}
void led_off(void)
{
	GPIOD->ODR &= ~(BV(12) | BV(13) |BV(14) |BV(15));
}

void led_toggle(void)
{
	GPIOD->ODR ^= BV(12) | BV(13) |BV(14) |BV(15);
}

