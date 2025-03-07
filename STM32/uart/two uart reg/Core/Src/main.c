#include "stm32f446xx.h"
#include<stdio.h>
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

void delay(int n)
{
  int temp;
  for(int i=0; i<n; i++)
    {
      temp = n;
      while(temp>0)
        {
          temp--;
        }
    }
}

void gpio_init()
{
  RCC->AHB1ENR |= (0x7);

  GPIOA->MODER &= ~(1<<(2*5));
  GPIOA->MODER |= (1<<(2*5));

  GPIOB->MODER &= ~(0xFFFF);
  GPIOB->MODER |= (0x5400);

  GPIOC->MODER &= ~(0xFFFF);
  GPIOC->MODER |= (0x5555);
}

void usart1_init()
{
  RCC->APB2ENR |= (1<<4); // Enable clock to USART1
  // AF7:  PA9-Tx, PA10-Rx

  // Clear the GPIOA till Pin 11
  GPIOA->MODER &= ~(0xFFFFFF);


  GPIOA->MODER |= (1<<((2*9)+1)); // PA9 set to AF
  GPIOA->MODER |= (1<<((2*10)+1));// PA10 set to AF

  GPIOA->AFR[1] |= (0x70);
  GPIOA->AFR[1] |= (0x700);

  USART1->BRR |= (0x8B);

  // related to USART1 interrupt configuration
  USART1->CR1 |= (1<<5); // Enable RXNIE
//  USART1->CR1 |= (1<<7); // Enable TXEIE
  NVIC_EnableIRQ(USART1_IRQn);

  USART1->CR1 |= (1<<13) | (1<<3) | (1<<2);
}


int main()
{
  gpio_init();
  usart1_init();

  while(1)
    {

    }
}

void USART1_IRQHandler()
{
  uint8_t data[10];
  for (int i = 0; i < 10; ++i) {
	  data[i] = USART1->DR;
}

  uint8_t transmit[15]="HELLO \r\n ";
  for (int i = 0; i < 15; ++i) {
	  USART1->DR = transmit[i];
}
}
