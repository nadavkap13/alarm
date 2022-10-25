#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"
#include "LED.h"

void led_init(LED* led,GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin,int num)
{
	led->GPIO_Pin=GPIO_Pin;
	led->GPIOx = GPIOx;
	led->delay = num;
}
