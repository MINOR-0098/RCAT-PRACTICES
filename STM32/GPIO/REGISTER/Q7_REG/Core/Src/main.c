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
	int x=0;
	gpio_init();
	while(1)
	{
		if(GPIOB ->IDR & 1<<7)
		{
			x=x+1;
			delay(500);
		}
		switch (x) {
		case 1:
			GPIOA ->ODR=1<<7;
			break;
		case 2:
			GPIOA ->ODR=11<<7;
			break;
		case 3:
			GPIOA ->ODR=111<<7;
			break;
		case 4:
			GPIOA ->ODR=000<<7;
			x=0;
			break;

		}
	}
}

