//PA5-LED
//PA13-BUTTON

#include "stm32f4xx.h"

void delay(int seconds)
{
	for(;seconds>0;seconds--)
		for(int count1 =0;count1<3000; count1++);
}

void gpio_init()
{
	RCC->AHB1ENR |= 101<<0;
	GPIOA ->MODER |= 1<<10;
}

int main()
{
	int x=0;
	while(1)
	{
		if(GPIOC->IDR & 1<<13)
		{
			x=x+1;
		}
		for (int var = 0; var < x; var++)
		{
			GPIOA->ODR=1<<5;
			delay(200);
			GPIOA->ODR=0<<5;
			delay(200);
		}
	}
}
