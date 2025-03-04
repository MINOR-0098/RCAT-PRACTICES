#include "stm32f446xx.h"

void usart_int()
{
	RCC->AHB1ENR |= 1;
	RCC->APB1ENR |= 1<<17;
	GPIOA->MODER |= ((1<<5)|(1<<7)|(1<<10));
	GPIOA->AFR[0] |= 0x7700;
	USART2->BRR|=0x8B;
	USART2->CR1|=(1<<2|1<<3|1<<13);
}
char usart_rx()
{
	return USART2->DR & 0xFF;
}

int main()
{
	char buff;
	usart_int();
	while(1)
	{
		buff = usart_rx();
		if (buff == 'N' || buff=='n')
		{
			GPIOA->ODR &= ~(1<<5);
		}
		if (buff == 'y' || buff=='Y')
		{
			GPIOA->ODR|=1<<5;
		}

	}
}
