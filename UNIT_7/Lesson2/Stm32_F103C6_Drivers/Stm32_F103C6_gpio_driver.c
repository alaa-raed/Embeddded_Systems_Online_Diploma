/*
 * Stm32_F103C6_gpio_driver.c
 *
 *  Created on: Oct 14, 2024
 *      Author: alaar
 */
 /*--------------------------------------------------------
  * @Fn					-MCAL_GPIO_Init
  * @brief				-Initialize GPIOx PINy according to specified parameter in the PinConfig
  * @Param [in]			-GPIOx:where X can be(A..E depending on device used)to select GPIO peripheral
  * @Param [in]			-PinConfig pointer to a GPIO_PINCONFIG_t structure that contains
  * 					 the configuration information for the specified GPIO Pin
  * @retval				-none
  * Note				-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
  * 					 but LQFP48 PACKAGE has only GPIO A,B part of C,D exported as external pins from the MCU
  */
#include "Stm32_F103C6_gpio_driver.h"

uint8_t Get_CRLH_Position(uint16_t PinNumber){
	switch(PinNumber){
	case GPIO_PIN_0:
		return 0;
		break;
	case GPIO_PIN_1:
			return 4;
			break;
	case GPIO_PIN_2:
			return 8;
			break;
	case GPIO_PIN_3:
			return 12;
			break;
	case GPIO_PIN_4:
			return 16;
			break;
	case GPIO_PIN_5:
			return 20;
			break;
	case GPIO_PIN_6:
			return 24;
			break;
	case GPIO_PIN_7:
			return 28;
			break;
	case GPIO_PIN_8:
			return 0;
			break;
	case GPIO_PIN_9:
			return 4;
			break;
	case GPIO_PIN_10:
			return 8;
			break;
	case GPIO_PIN_11:
			return 12;
			break;
	case GPIO_PIN_12:
			return 16;
			break;
	case GPIO_PIN_13:
			return 20;
			break;
	case GPIO_PIN_14:
			return 24;
			break;
	case GPIO_PIN_15:
			return 28;
			break;
	}
	return 0;
}

void MCAL_GPIO_Init (GPIO_TypeDef *GPIOx, GPIO_PINCONFIG_t* PinConfig){
	volatile uint32_t* configregister = NULL;
	uint8_t PIN_Config;
	//port configuration low register (GPIOx_CRL) configure pins from 0 >>> 7
	//port configuration high register (GPIOx_CRH) configure pins from 8 >>> 15
	configregister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8) ? &GPIOx->CRL: &GPIOx->CRH;

	//clear CNF8[1:0] MODE8[1:0]
	(*configregister) &=~( 0xf<< Get_CRLH_Position(PinConfig->GPIO_PinNumber));
	//if pin is output
	if((PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP) || (PinConfig->GPIO_MODE == GPIO_MODE_AF_OUTPUT_OD) || (PinConfig->GPIO_MODE == GPIO_MODE_AF_OUTPUT_PU)){

		//set CNF8[1:0] MODE8[1:0]
		PIN_Config = ((((PinConfig->GPIO_MODE - 4) <<2 ) | (PinConfig->GPIO_OUTPUT_SPEED  ))&0x0f);

	}
	//if pin is input
	else{//MODE = 00:INPUT Mode (reset state)
		if((PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) || (PinConfig->GPIO_MODE == GPIO_MODE_Analog)){
			//set CNF8[1:0] MODE8[1:0]00
			PIN_Config = ((((PinConfig->GPIO_MODE ) <<2 ) | 0x0)&0x0f);
		}
		else if( PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT){//consider it as iput floating
			//set CNF8[1:0] MODE8[1:0]00
			PIN_Config = ((((GPIO_MODE_INPUT_FLO) <<2 ) | 0X0)&0X0F);
		}
		else{//PU PD INPUT
			PIN_Config = ((((GPIO_MODE_INPUT_PU) <<2 ) | 0X0)&0X0F);
			if( PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU){
				//PxODR:1 Input Pull-up :Table 20. Port bit configuration table
				GPIOx->ODR |= PinConfig->GPIO_PinNumber;
			}
			else{
				//PxODR:0 Input Pull-down :Table 20. Port bit configuration table
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}
	//write on CRL or CRH
	(*configregister) |=((PIN_Config) << (Get_CRLH_Position(PinConfig->GPIO_PinNumber)));
}

/*--------------------------------------------------------
 * @Fn					-MCAL_GPIO_Deinit
 * @brief				-Reset all the GPIO Registers
 * @Param [in]			-GPIOx:where X can be(A..E depending on device used)to select GPIO peripheral
 * @retval				-none
 * Note				    -none
 */
void MCAL_GPIO_Deinit (GPIO_TypeDef *GPIOx){
	if(GPIOx == GPIOA){
		RCC->APB2RSTR |= (1<<2); //Bit 2 :IOAPRST:IO PORT A reset
		RCC->APB2RSTR &=~ (1<<2);
	}
	else if(GPIOx == GPIOB){
		RCC->APB2RSTR |= (1<<3); //Bit 3 :IOBPRST:IO PORT B reset
		RCC->APB2RSTR &=~ (1<<3);
	}
	else if(GPIOx == GPIOC){
		RCC->APB2RSTR |= (1<<4); //Bit 4 :IOCPRST:IO PORT C reset
		RCC->APB2RSTR &=~ (1<<4);
	}
	else if(GPIOx == GPIOD){
		RCC->APB2RSTR |= (1<<5); //Bit 5 :IODPRST:IO PORT D reset
		RCC->APB2RSTR &=~ (1<<5);
	}
	else if(GPIOx == GPIOE){
		RCC->APB2RSTR |= (1<<6); //Bit 6 :IOEPRST:IO PORT E reset
		RCC->APB2RSTR &=~ (1<<6);
	}
}

/*--------------------------------------------------------
 * @Fn					-MCAL_GPIO_READPin
 * @brief				-Read Specific PIN
 * @Param [in]			-GPIOx:where X can be(A..E depending on device used)to select GPIO peripheral
 * @Param [in]			-PinNumber:set PIN according to @ref  GPIO_PINS_define
 * @retval				-the input pin value (two values based on @ref GPIO_PIN_state)
 * Note				    -none
 */

uint8_t MCAL_GPIO_ReadPin (GPIO_TypeDef *GPIOx,uint16_t PinNumber){
	uint8_t bitstatus;
	if(((GPIOx->IDR) & PinNumber)  != (uint32_t) GPIO_PIN_RESET){
		bitstatus = GPIO_PIN_SET;
	}
	else{
		bitstatus = GPIO_PIN_RESET;
	}
	return bitstatus;
}

/*--------------------------------------------------------
 * @Fn					-MCAL_GPIO_ReadPort
 * @brief				-Read the input PORT value
 * @Param [in]			-GPIOx:where X can be(A..E depending on device used)to select GPIO peripheral
 * @retval				-the input PORT value
 * Note				    -none
 */

uint16_t MCAL_GPIO_ReadPort (GPIO_TypeDef *GPIOx){
	uint16_t Port_value;
	Port_value = (uint16_t)GPIOx->IDR;
	return Port_value;
}

/*--------------------------------------------------------
 * @Fn					-MCAL_GPIO_WritePin
 * @brief				-write on specific input pin
 * @Param [in]			-GPIOx:where X can be(A..E depending on device used)to select GPIO peripheral
 * @Param [in]          -Pin Number: specifies the port bit to raed, set by GPIO_PINS_define
 * @Param [in]			-value:Pin Value
 * @retval				-the input PORT value
 * Note				    -none
 */
void MCAL_GPIO_WritePin (GPIO_TypeDef *GPIOx,uint16_t PinNumber,uint8_t value){
	if(value != GPIO_PIN_RESET){
		//Bits 15:0 BSy:Posrt x set bit y (y=0..15)
				//These bits are write-only and can be accepted in word mode only
				//0:No action on the corresponding ODRx bit
				//1:Set Corresponding ODRx bit
		GPIOx->BSRR = (uint32_t)PinNumber;
	}
	else{
		//Bits 31:16 BRy:Posrt x reset bit y (y=0..15)
		//These bits are write-only and can be accepted in word mode only
		//0:No action on the corresponding ODRx bit
		//1:Reset Corresponding ODRx bit
		GPIOx->BRR = (uint32_t)PinNumber;
	}
}

/*--------------------------------------------------------
 * @Fn					-MCAL_GPIO_WritePort
 * @brief				-write on output PORT
 * @Param [in]			-GPIOx:where X can be(A..E depending on device used)to select GPIO peripheral
 * @retval				-the input PORT value
 * Note				    -none
 */
void MCAL_GPIO_WritePort (GPIO_TypeDef *GPIOx,uint16_t value){
	GPIOx->ODR = (uint32_t)value;
}

/*--------------------------------------------------------
 * @Fn					-MCAL_GPIO_TogglePin
 * @brief				-Toggle the specified GPIO pin
 * @Param [in]			-GPIOx:where X can be(A..E depending on device used)to select GPIO peripheral
 * @Param [in]          -Pin Number: specifies the port bit to raed, set by GPIO_PINS_define
 * @retval				-none
 * Note				    -none
 */
void MCAL_GPIO_TogglePin (GPIO_TypeDef *GPIOx,uint16_t PinNumber){
	GPIOx->ODR ^= (PinNumber);
}
/*--------------------------------------------------------
 * @Fn					-MCAL_GPIO_LOCKPint
 * @brief				-the locking mechanism allow the IO configuration to be frozen
 * @Param [in]			-GPIOx:where X can be(A..E depending on device used)to select GPIO peripheral
 * @Param [in]          -Pin Number: specifies the port bit to raed, set by GPIO_PINS_define
 * @retval				-OK if pin config is locked or ERROR if pin not locked(OK &ERROR Are defined @ref GPIO_return_lock)
 * Note				    -none
 */
uint8_t MCAL_GPIO_LOCKPin (GPIO_TypeDef *GPIOx,uint16_t PinNumber){
//	Bit 16 LCKK[16]: Lock key
//	This bit can be read anytime. It can only be modified using the Lock Key Writing Sequence.
//	0: Port configuration lock key not active
//	1: Port configuration lock key active. GPIOx_LCKR register is locked until the next reset.
//	LOCK key writing sequence:
//	Write 1
//	Write 0
//	Write 1
//	Read 0
//	Read 1 (this read is optional but confirms that the lock is active)
//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.
//	Any error in the lock sequence will abort the lock.
//	Bits 15:0 LCKy: Port x Lock bit y (y= 0 .. 15)
//	These bits are read write but can only be written when the LCKK bit is 0.
//	0: Port configuration not locked
//	1: Port configuration locked.

	//Set LCKK[16]
		volatile uint32_t tmp = 1<<16;
	//Set LCKy[16]
		tmp |= PinNumber;
//		Write 1
		GPIOx->LCKR = tmp;
//		Write 0
		GPIOx->LCKR = PinNumber;
//		Write 1
		GPIOx->LCKR = tmp;
//		Read 0
		tmp = GPIOx->LCKR;
//		Read 1 (this read is optional but confirms that the lock is active)
		if((uint32_t)(GPIOx->LCKR & 1<<16)){

			return GPIO_RETURN_LOCK_Enabled;
		}
		else{
			return GPIO_RETUN_LOCK_ERROR;
		}
}
