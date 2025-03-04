#include"stm32f4xx.h"

void gpio()
{
	RCC->AHB1ENR |= 0x5;
	GPIOA->MODER = 0x2000;
	GPIOA->AFR=0x2000000;
}
void tim()
{
	RCC->APB1ENR |= 0x3;
	TIM2->PSC = 16000-1;
	TIM2->ARR = 3000-1;
	TIM2->CNT = 0;
	TIM2->DIER |= 1<<0; //EN INT
	TIM2->CR1 |=1<<0; //TIM EN
	NVIC_EnableIRQ(TIM2_IRQn);

	TIM3->PSC = 160-1;
	TIM3->ARR = 100-1;
//	TIM3->CNT = 0 ;
	TIM3->CCMR1 |= 0X60;
	TIM3->CCMR1 |=0X8;
//	TIM3->CCER|=1;
//	TIM3->CR1 |=1<<7;
	TIM3->CCR1 = 50;
	TIM3->CR1 |=1;
}
int a,x=0;
void TIM2_IRQHandler(void)
{
	TIM2->SR &= ~(1);
		  switch (x)
		  {
			case 0:
				TIM3->ARR = 100-1;
				TIM3->CCR1 = 50;
				x=1;
				break;
			case 1:
				TIM3->ARR = 50-1;
				TIM3->CCR1 = 25;
				x=0;
				break;
		  }
}
int main()
{
	gpio();
	tim();
	while(1)
	{
//		a=GPIOC->IDR&1<<8;
		for (int i = 0; i < 500; ++i) {

		}
	}
}
