#include <stdint.h>

int main(void)
{
	uint32_t *ptr_RCC_CLKREG	= (uint32_t*)0x40023830;
	uint32_t *ptr_GPIO_MODREG	= (uint32_t*)0x40020C00;
	uint32_t *ptr_GPIO_ODR	= (uint32_t*)0x40020C14;

	//Enable RCC CLK REG
	*ptr_RCC_CLKREG |= (1 << 3);

	//CONFIGURE THE MODE OF I/O PIN

	//CLEAR THE MODE REG
	*ptr_GPIO_MODREG &= ~(3 << 24);

	//SET THE MODE REG
	*ptr_GPIO_MODREG |= (1 << 24);


	//TO BLINK AN LED SET 12th BIT OF THE ODR TO MAKE 12th PIN AS HIGH AND LOW

    /* Loop forever */
	for(;;)
	{
		//GREEN LED ON
			*ptr_GPIO_ODR |= (1 << 12);
		//Software Delay
			 for(uint32_t i = 0; i < 500000; i++);
		//GREEN LED OFF
			*ptr_GPIO_ODR &= ~(1 << 12);
		//Software Delay
			 for(uint32_t i = 0; i < 500000; i++);
	}

}
