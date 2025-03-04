#include "stm32f4xx.h"

void delay(int seconds)
{
	for(;seconds>0;seconds--)
		for(int count1 =0;count1<3000; count1++);
}

void gpio_init()
{
	RCC->AHB1ENR |= 11<<1;
	GPIOC ->MODER |= 0x5555;
	GPIOB ->MODER |= 0x5555;
}
void fun()
{
	GPIOB ->ODR = 0x6F;
	delay(1000);
	GPIOB ->ODR = 0x3F;
	delay(1000);
	GPIOB ->ODR = 0x6;
	delay(1000);
	GPIOB ->ODR = 0x5B;
	delay(1000);
	GPIOB ->ODR = 0x4F;
	delay(1000);
	GPIOB ->ODR = 0x66;
	delay(1000);
	GPIOB ->ODR = 0x6D;
	delay(1000);
	GPIOB ->ODR = 0x7D;
	delay(1000);
	GPIOB ->ODR = 0x7;
	delay(1000);
	GPIOB ->ODR = 0xFF;
	delay(1000);
}

int main()
{
	gpio_init();
	while(1)
	{
		GPIOC ->ODR = 0x6F;
		delay(1000);
		fun();
		GPIOC ->ODR = 0x3F;
		delay(1000);
		fun();
		GPIOC ->ODR = 0x6;
		delay(1000);
		fun();
		GPIOC ->ODR = 0x5B;
		delay(1000);
		fun();
		GPIOC ->ODR = 0x4F;
		delay(1000);
		fun();
		GPIOC ->ODR = 0x66;
		delay(1000);
		fun();
		GPIOC ->ODR = 0x6D;
		delay(1000);
		fun();
		GPIOC ->ODR = 0x7D;
		delay(1000);
		fun();
		GPIOC ->ODR = 0x7;
		delay(1000);
		fun();
		GPIOC ->ODR = 0xFF;
		delay(1000);
		fun();

	}
}
