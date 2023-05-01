
#include "stm32f4xx.h"
#include "stm32f4xx_gpio.h"


void configuracionpines (void);

int main (void) {

	configuracionpines (); //si no anda asi definir toda la funcion dentro del main a ver que hace

													//PROGRAMA 2.1
	while(1)
	{

		if(GPIO_ReadInputDataBit(GPIOC, GPIO_Pin_13) == Bit_RESET )		//si el boton esta presionado entonces que entre y ponga el bit en 1
		{
			GPIO_SetBits(GPIOA, GPIO_Pin_5); 							//ESTA PONE DIRECTAMENTE EL BIT EN 1 si no anda poner el puerto no el bit
		}
		else
		{
			GPIO_ResetBits(GPIOA, GPIO_Pin_5);			//mantener apagado el led -- Si se configura con un pull down no es neceesario esta linea
		}
	}

													//PROGRAMA 2.2
//	while(1)
//	{
//
//		if(GPIO_ReadInputDataBit(GPIOB, GPIO_Pin_9) == Bit_RESET )		//si el boton esta presionado entonces que entre y ponga el bit en 1
//		{
//			GPIO_SetBits(GPIOA, GPIO_Pin_5); 							//ESTA PONE DIRECTAMENTE EL BIT EN 1 si no anda poner el puerto no el bit
//		}
//		else
//		{
//			GPIO_ResetBits(GPIOA, GPIO_Pin_5);			//mantener apagado el led -- Si se configura con un pull down no es neceesario esta linea
//		}
//	}

}

void configuracionpines (void)
{

	GPIO_InitTypeDef GPIO_InitStruct;

																	//Configuramos el boton interno
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd= GPIO_PuPd_NOPULL;					//configurado con NOPULL puede ir PD OR PP
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStruct);

																	//Configuramos el boton externo
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);

	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd= GPIO_PuPd_UP;						//configurado con NOPULL puede ir PD OR PP
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStruct);

																	//Configuramos el led
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_5;
	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_OType=GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd=GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &GPIO_InitStruct);

}
