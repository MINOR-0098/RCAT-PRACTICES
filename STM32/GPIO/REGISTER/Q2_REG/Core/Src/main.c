#include "stm32f4xx.h"

void delay(int seconds)
{
	for(;seconds>0;seconds--)
		for(int count1 =0;count1<3000; count1++);
}

void gpio_init()
{
	RCC->AHB1ENR |= 11<<0;
	GPIOA ->MODER |= 0x4000;
}

int main()
{
	int x=0;
	gpio_init();
	while(1)
	{
		if((GPIOB ->IDR & 1<<7)&& x==0)
		{
			GPIOA ->ODR=1<<7;
			delay(500);
			x=1;
		}
		if((GPIOB ->IDR & 1<<7)&&x==1)
		{
			GPIOA ->ODR=0<<7;
			delay(500);
			x=0;
		}

	}
}
