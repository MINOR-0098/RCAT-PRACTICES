#include "stm32f4xx.h"
#include <stdio.h>
#include "main.h"
int _write(int file, char *ptr, int len)
{
  (void)file;
  int DataIdx;

  for (DataIdx = 0; DataIdx < len; DataIdx++)
  {
    ITM_SendChar(*ptr++);
  }
  return len;
}

int main()
{
  __disable_irq();

  RCC->AHB1ENR |= (101<<0);
  RCC->APB2ENR |= (1<<14); // enabling clock for syconfig controlle
  GPIOA->MODER |= (1<<10)|(1<<14);

  GPIOC->MODER &= ~(11<<(2*13));

  EXTI->IMR |= (1<<13); // unmask interrupt

  EXTI->RTSR |= (1<<13); // enabling rising edge trigger

  SYSCFG->EXTICR[3] |= (1<<5); // enable interrupt source PC13

  NVIC_EnableIRQ(EXTI15_10_IRQn); // Enable Interrupt

  __enable_irq();

  while(1)
    {
      // only required in Polling Mode
    }
}

void delay(int n)
{
  while(n>0)
    {
      n--;
    }
}
void
fun()
{
	static int count = 0;
	count++;
	printf("\n times pressed = %d \n",count);
	for (int var = 0; var < 2*count; var++)
	{
		GPIOA->ODR ^= 1<<5;
		for (int I = 0; I < 900000; ++I);
	}
	for (int var = 0; var < 6*count; ++var)
	{
		GPIOA->ODR ^= 1<<7;
		for (int I = 0; I < 900000; ++I);
	}
}

void EXTI15_10_IRQHandler(void)
{

  	if (EXTI->PR & (1 << 13)) // checks whether interrupt occured or not
  	{
  		fun();
  	  EXTI->PR |= (1<<13); // clearing pending register for bit 13
  	}

}
