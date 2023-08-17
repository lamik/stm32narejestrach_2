/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Mateusz Salamon
 * @brief          : STM32 na Rejestrach
 ******************************************************************************
 ******************************************************************************

 	 	 	 	 https://msalamon.pl
 	 	 	 	 https://sklep.msalamon.pl
 	 	 	 	 https://kursstm32.pl
 	 	 	 	 https://stm32narejestrach.pl

 */
#include "main.h"

#define LD4_ON GPIOA->BSRR = GPIO_BSRR_BS5
#define LD4_OFF GPIOA->BSRR = GPIO_BSRR_BR5

// PA5 - LD4

void ConfigureLD4(void);
void Delay(void);

int main(void)
{

	ConfigureLD4();

    /* Loop forever */
	while(1)
	{
		// Set LED on PA5
		LD4_ON;
		Delay();

		// Reset LED on PA5
		LD4_OFF;
		Delay();
	}
}

void ConfigureLD4(void)
{
	// Enable Clock for PORTD
	RCC->IOPENR |= RCC_IOPENR_GPIOAEN;

	// Configure GPIO Mode - Output
	GPIOA->MODER |= GPIO_MODER_MODE5_0; // It's default reset state. Not necessary.
	GPIOA->MODER &= ~(GPIO_MODER_MODE5_1);

	// Configure Output Mode - Push-pull
	GPIOA->OTYPER &= ~(GPIO_OTYPER_OT5); // It's default reset state. Not necessary.

	// Configure GPIO Speed - Low
	GPIOA->OSPEEDR &= ~(GPIO_OSPEEDR_OSPEED5); // Two bits together. It's default reset state. Not necessary.

	// Configure Pull-up/Pull-down - no PU/PD
	GPIOA->PUPDR &= ~(GPIO_PUPDR_PUPD5); // It's default reset state. Not necessary.
}

void Delay(void)
{
	uint32_t i;

	for(i = 0; i < 99999; i++)
	{

	}
}






