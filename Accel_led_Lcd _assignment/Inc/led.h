/*
 * led.h
 *
 *  Created on: Sep 13, 2025
 *      Author: sunbeam
 */

#ifndef LED_H_
#define LED_H_

#include "led.h"

#include "stm32f407xx.h"

#define BV(n) (1<<(n))

void led_on1(void);
void led_on2(void);
void led_on3(void);
void led_on4(void);
void led_init(void);
void led_off1(void);
void led_off2(void);
void led_off3(void);
void led_off4(void);


#endif /* LED_H_ */
