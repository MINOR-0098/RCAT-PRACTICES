#include "stm32f446xx.h"

void usart_int()
{
	RCC->AHB1ENR |= 1;
	RCC->APB1ENR |= 1<<17;
	GPIOA->MODER |= ((1<<5)|(1<<7));
	GPIOA->AFR[0] |= 0x7700;
	USART2->BRR|=0x8B;
	USART2->CR1|=(1<<2|1<<3|1<<13);
}
void delay(int sec)
{
	for (int var = 0; var < sec; ++var)
	{
		for (int i = 0; i < 3500; ++i);
	}
}
uint8_t usart_rx()
{
	while(!(USART2->SR & 1<<5));
	return USART2->DR & 0xFF;
}

void usart_tx(uint8_t data)
{
	while(!(USART2->SR & 1<<7))
	{

	}
	USART2->DR = (data & 0xFF);
}
void tx(uint8_t str)
{
		usart_tx(str);
}

int main()
{
	uint8_t buff;
	usart_int();
	while(1)
	{
		buff = usart_rx();
		tx(buff);

	}
}
