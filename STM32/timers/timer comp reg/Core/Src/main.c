#include "stm32f4xx.h"
void gpio_init()
{
	RCC->AHB1ENR |= 1<<0;
	GPIOA->MODER |= 1<<11;
	GPIOA->AFR[0] &= 0x00F00000;
	GPIOA->AFR[0]|= 0x00100000;
}
void tim_init()
{
	RCC->APB1ENR |= 1<<0;


	TIM2->PSC = 1600-1;
	TIM2->ARR = 10000-1;
	TIM2->CCMR1 = 0x30;
	TIM2->CCR1 =0;
	TIM2->CCER|=1;
	TIM2->CNT =0;
	TIM2->CR1 =1;//TIM EN

}
int main()
{
	gpio_init();
	tim_init();

	while(1)
	{

	}
}




