#include "stm32f4xx.h"

void delay(int seconds)
{
	for(;seconds>0;seconds--)
		for(int count1 =0;count1<3000; count1++);
}

void gpio_init()
{
	RCC->AHB1ENR |= 11<<0;
	GPIOA ->MODER |= 0x54000;
}

int main()
{
	gpio_init();
	while(1)
	{
		if(GPIOB ->IDR & 1<<7)
		{
			GPIOA ->ODR=1<<7;
			delay(500);
			GPIOA ->ODR=0<<7;
		}
		if(GPIOB ->IDR & 1<<8)
		{
			GPIOA ->ODR=1<<8;
			delay(500);
			GPIOA ->ODR=0<<8;
		}
		if(GPIOB ->IDR & 1<<9)
		{
			GPIOA ->ODR=1<<9;
			delay(500);
			GPIOA ->ODR=0<<9;
		}
	}
}
