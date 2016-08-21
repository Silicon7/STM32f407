#include "main.h"
static char i=0;
char a;
int main()
{
	gpio_config();
	NVIC_EnableIRQ(EXTI0_IRQn);
	while(1)
	{
	}
}

void EXTI0_IRQHandler(void)
{
	//NVIC->ICER[0] = 1<<22;
	a = GPIOA->IDR & 0x00000001;
	if(a==1)
	{
		delay(8000000);
		if((GPIOA->IDR & 0x1) == 1)
		{
			if(i==0)
			{
				GPIOD->ODR = 0x00000000;
				GPIOD->ODR ^= 0x1000;
			}
			else if(i==1)
			{
				GPIOD->ODR = 0x00000000;
				GPIOD->ODR ^= 0x2000;
			}
			else if(i==2)
			{
				GPIOD->ODR = 0x00000000;
				GPIOD->ODR ^= 0x4000;
			}
			else if(i==3)
			{
				GPIOD->ODR = 0x00000000;
				GPIOD->ODR ^= 0x8000;
			}
			
			i++;
			if(i>3)
				i=0;
		}
	}
	else
	{}
	EXTI->PR |= 0x1;
	NVIC->ICPR[0] = 1<<22;
	//NVIC_EnableIRQ(EXTI0_IRQn);	
}

void delay(long long x)
{
	long long i;
	for(i=0;i<x;i++)
	{}
}

