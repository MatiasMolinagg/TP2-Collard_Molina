
/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */


#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"


void delay_ms(uint32_t milisegundos)
{
	uint32_t i;
	for(i=0 ; i  < ( milisegundos * 0x2961 )   ; i++) ;
}
//SIENDO QUE 1 mSeg es 0x2961



int main(void)
{

	GPIO_InitTypeDef GPIO_InitStruct;

																		//configuramos el led
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

	uint32_t miliseg = 50 ;
	while (1)
	{
		GPIO_SetBits(GPIOA, GPIO_Pin_5);
		delay_ms(miliseg);					//llamamos la funcion y le pasamos la variable milisegundos
		GPIO_ResetBits(GPIOA, GPIO_Pin_5);
		delay_ms(miliseg);

		miliseg = miliseg + 50 ;

		if (miliseg == 200){
		miliseg = 50 ;
		}

	}

}
