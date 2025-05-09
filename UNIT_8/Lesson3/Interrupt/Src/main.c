/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

#include "stm32f103x6.h"
#include "Stm32_F103C6_gpio_driver.h"
#include "Keypad.h"
#include "lcd.h"
#include "stm32_F103C6_USART_driver.h"
#include "Stm32_F103C6_EXTI_driver.h"


unsigned char ch;

void UART_IRQ_CallBack(void){
	MCAL_UART_ReceiveData(USART1, &ch, disable);
	MCAL_UART_SendData(USART1, &ch, disable);
}

int main(void)
{
	UART_Config uartCFG ;
		uartCFG.BaudRate = UART_BaudRate_115200 ;
		uartCFG.HwFlowCtl = UART_HwFlowCtl_NONE ;
		uartCFG.IRQ_Enable = UART_IRQ_Enable_RXNEIE ;
		uartCFG.P_IRQ_CallBack = UART_IRQ_CallBack ;
		uartCFG.Parity =UART_Parity__NONE ;
		uartCFG.Payload_Length = UART_Payload_Length_8B;
		uartCFG.StopBits = UART_StopBits__1 ;
		uartCFG.USART_Mode = UART_MODE_TX_RX ;

		MCAL_UART_Init(USART1, &uartCFG);
		MCAL_UART_GPIO_Set_Pins(USART1);


		while(1)
		{


		}
}
