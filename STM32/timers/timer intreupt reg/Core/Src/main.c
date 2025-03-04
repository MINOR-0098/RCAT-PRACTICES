#include "stm32f4xx.h"
void gpio_init()
{
	RCC->AHB1ENR |= 1<<0;
	GPIOA->MODER |= 1<<10;
}
void tim_init()
{
	RCC->APB1ENR |= 1<<0;

	TIM2->PSC = 16000-1;
	TIM2->ARR = 1000-1;
	TIM2->CNT = 0;
	TIM2->DIER |= 1<<0; //EN INT
	TIM2->CR1 |=1<<0; //TIM EN
	NVIC_EnableIRQ(TIM2_IRQn);

}
void TIM2_IRQHandler(void)
{
	if(TIM2->SR & 1)
	{
		TIM2->SR &= ~(1);
		GPIOA->ODR ^= 1<<5;
	}
}
int main()
{
	gpio_init();
	tim_init();

	while(1)
	{

	}
}
