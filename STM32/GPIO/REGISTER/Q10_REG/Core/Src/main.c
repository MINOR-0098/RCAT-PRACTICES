#include "stm32f4xx.h"
#include "stdio.h"

int __io_putchar(int ch)
{
 ITM_SendChar(ch);
 return(ch);
}


void delay(int seconds)
{
	for(;seconds>0;seconds--)
		for(int count1 =0;count1<3000; count1++);
}

void gpio_init()
{
	RCC->AHB1ENR |= 11<<0;
	GPIOA ->MODER |= 1<<16;
//	GPIOB ->PUPDR |= 7<<15;
}


int main()
{
	HAL_Init();
	int x=0;
	gpio_init();
	while(1)
	{
		if(GPIOB ->IDR & 1<<7 && x==0)
		{
			GPIOA->ODR = 1<<8;
			printf("LED ON \n");
			HAL_Delay(500);
			x=1;

		}
		if(GPIOB ->IDR & 1<<7 && x==1)
		{
			GPIOA->ODR=0<<8;
			printf(" LED OFF \n ");
			HAL_Delay(500);
			x=0;
		}
	}
}
