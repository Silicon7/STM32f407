#include "main.h"

int main()
{
	gpio_config();
	while(1)
	{
		GPIOD->ODR = 0x8000;
	}
}
