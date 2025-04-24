/*
 * stm32_F103C6_RCC_driver.h
 *
 *  Created on: Apr 13, 2025
 *      Author: alaar
 */

#ifndef INC_STM32_F103C6_RCC_DRIVER_H_
#define INC_STM32_F103C6_RCC_DRIVER_H_

//Includes
#include "stm32f103x6.h"
#include "Stm32_F103C6_gpio_driver.h"


#define HSE_Clock	(uint32_t)16000000
#define HSI_RC_Clk	(uint32_t)8000000

uint32_t MCAL_RCC_GetSYS_CLKFreq(void);
uint32_t MCAL_RCC_GetHCLKFreq(void);
uint32_t MCAL_RCC_GetPCLK1Freq(void);
uint32_t MCAL_RCC_GetPCLK2Freq(void);

#endif /* INC_STM32_F103C6_RCC_DRIVER_H_ */
