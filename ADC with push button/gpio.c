#include "main.h"

void gpio_config(void)
{
	RCC->AHB1ENR   = 0x08;
	GPIOD->MODER 	 = 0x55000000;
	GPIOD->OSPEEDR = 0xFF000000;
	GPIOD->PUPDR   = 0xAA000000;
	GPIOD->OTYPER  = 0x00000000;
}
