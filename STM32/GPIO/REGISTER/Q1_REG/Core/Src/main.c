#include "stm32f4xx.h"

void gpio_init()
{
	RCC->AHB1ENR |= 11<<0;
	GPIOA ->MODER |= 1<<16;
}

int main()
{
	while(1)
	{
		if(GPIOB->IDR & 1<<7)
		{
			GPIOB->ODR=1<8;
		}
		else
		{
			GPIOB->ODR=0<8;
		}
	}
}
