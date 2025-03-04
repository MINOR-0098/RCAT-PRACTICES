#include "stm32f4xx.h"

void gpio_init()
{
	RCC->AHB1ENR |= 11<<0;
	GPIOA ->MODER |= 0x54000;
	GPIOB ->MODER |= 0x000;
}

int main()
{
	gpio_init();
	while(1)
	{
		if(GPIOB ->IDR & 0x80){
		GPIOA ->ODR = 1<<7;
		}
		else{
			GPIOA ->ODR =0<<7;
		}
		if(GPIOB ->IDR & (1<<8) ){
			GPIOA ->ODR = 1<<7;
			GPIOA ->ODR = 1<<8;
		}
		else{
			GPIOA ->ODR =0<<7;
			GPIOA ->ODR =0<<8;
		}
		if(GPIOB ->IDR & (1<<9) ){
			GPIOA ->ODR = 1<<7;
			GPIOA ->ODR = 1<<8;
			GPIOA ->ODR = 1<<9;
		}
		else{
			GPIOA ->ODR = 0<<7;
			GPIOA ->ODR = 0<<8;
			GPIOA ->ODR = 0<<9;}
	}
}
