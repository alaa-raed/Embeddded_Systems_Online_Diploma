/*
 * Stm32_F103C6_gpio_driver.h
 *
 *  Created on: Oct 14, 2024
 *      Author: alaar
 */

#ifndef INC_STM32_F103C6_GPIO_DRIVER_H_
#define INC_STM32_F103C6_GPIO_DRIVER_H_

/*Include*/
#include "stm32f103x6.h"

//========================
//Config Structure
typedef struct{
	uint16_t GPIO_PinNumber   ;//specifies the GPIO pins to be configured
							   //This parameter must be set based on @ref GPIO_Pins_define
	uint8_t GPIO_MODE         ;//specifies the operating mode for selected pins
							   //This parameter can be value @ref GPIO_MODE_define
	uint8_t GPIO_OUTPUT_SPEED ;//specifies the speed for selected pins
	                           //This parameter can be value @ref GPIO_SPEED_define
}GPIO_PINCONFIG_t;

//@ref GPIO_PIN_state
#define GPIO_PIN_SET		1
#define GPIO_PIN_RESET		0

//@ref GPIO_return_lock
#define GPIO_RETURN_LOCK_Enabled		1
#define GPIO_RETUN_LOCK_ERROR			0

/*Macros Configuration References*/
//@ref GPIO_PINS_define

#define GPIO_PIN_0				((uint16_t)0x0001) /*pin 0 is selected*/
#define GPIO_PIN_1				((uint16_t)0x0002) /*pin 1 is selected*/
#define GPIO_PIN_2				((uint16_t)0x0004) /*pin 2 is selected*/
#define GPIO_PIN_3				((uint16_t)0x0008) /*pin 3 is selected*/
#define GPIO_PIN_4				((uint16_t)0x0010) /*pin 4 is selected*/
#define GPIO_PIN_5				((uint16_t)0x0020) /*pin 5 is selected*/
#define GPIO_PIN_6				((uint16_t)0x0040) /*pin 6 is selected*/
#define GPIO_PIN_7				((uint16_t)0x0080) /*pin 7 is selected*/
#define GPIO_PIN_8				((uint16_t)0x0100) /*pin 8 is selected*/
#define GPIO_PIN_9				((uint16_t)0x0200) /*pin 9 is selected*/
#define GPIO_PIN_10				((uint16_t)0x0400) /*pin 10 is selected*/
#define GPIO_PIN_11				((uint16_t)0x0800) /*pin 11 is selected*/
#define GPIO_PIN_12				((uint16_t)0x1000) /*pin 12 is selected*/
#define GPIO_PIN_13				((uint16_t)0x2000) /*pin 13 is selected*/
#define GPIO_PIN_14				((uint16_t)0x4000) /*pin 14 is selected*/
#define GPIO_PIN_15				((uint16_t)0x8000) /*pin 15 is selected*/
#define GPIO_PIN_ALL			((uint16_t)0xFFFF) /*All pins is selected*/

#define GPIO_PIN_MASK			0x0000FFFFu        /*pin mask for assert test*/


/*@ref GPIO_MODE_define*/
//0:Analog mode
//1:Floating mode(reset mode)
//2:Input with pull up
//3:pull-down
//4:General purpose output push-pull
//5:General purpose output open-drain
//6:Alternate Function output push-pull
//7:Alternate Function output open-drain
//8:Alternate Function INPUT
#define GPIO_MODE_Analog				0x00000000u //Analog mode
#define GPIO_MODE_INPUT_FLO				0x00000001u //Floating mode
#define GPIO_MODE_INPUT_PU				0x00000002u //Input with pull up
#define GPIO_MODE_INPUT_PD				0x00000003u //input with pull down
#define GPIO_MODE_OUTPUT_PP				0x00000004u //General purpose output push-pull
#define GPIO_MODE_OUTPUT_OD				0x00000005u //General purpose output open-drain
#define GPIO_MODE_AF_OUTPUT_PU			0x00000006u //Alternate Function output push-pull
#define GPIO_MODE_AF_OUTPUT_OD			0x00000007u //Alternate Function output open-drain
#define GPIO_MODE_AF_INPUT				0x00000008u //Alternate Function INPUT

//@ref GPIO_SPEED_define

//1:Output mode,Max speed 10MHz
//2:Output mode,Max speed 2MHz
//3:Output mode,Max speed 50MHz
#define GPIO_SPEED_10M					0x00000001u //Output mode,Max speed 10MHz
#define GPIO_SPEED_2M					0x00000002u //Output mode,Max speed 2MHz
#define GPIO_SPEED_50M					0x00000003u //Output mode,Max speed 50MHz

/*----------------------------------------------------------------------
 -----------------"APIs Supported by MCAL GPIO DRIVER" -----------------
 ----------------------------------------------------------------------*/
void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_PINCONFIG_t* PinConfig);
void MCAL_GPIO_Deinit (GPIO_TypeDef *GPIOx);

uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef *GPIOx,uint16_t PinNumber);
uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef *GPIOx);

void MCAL_GPIO_WritePin (GPIO_TypeDef *GPIOx,uint16_t PinNumber,uint8_t value);
void MCAL_GPIO_WritePort (GPIO_TypeDef *GPIOx,uint16_t value);

void MCAL_GPIO_TogglePin (GPIO_TypeDef *GPIOx,uint16_t PinNumber);
uint8_t MCAL_GPIO_LOCKPin (GPIO_TypeDef *GPIOx,uint16_t PinNumber);

void MCAL_GPIO_Init_Port_Range(GPIO_TypeDef *GPIOx, GPIO_PINCONFIG_t* PinConfig,uint8_t PinCount);

#endif /* INC_STM32_F103C6_GPIO_DRIVER_H_ */

