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

uint8_t Get_CRLH_Position(uint16_t PinNumber)
{
	volatile uint8_t PinOrder = 0 ;
	while(!(PinNumber&0x01))
	{
		PinOrder ++ ;
		PinNumber >>= 1 ;
	}

	PinNumber = PinOrder ;
	volatile uint16_t Position  = (PinNumber < 8)? PinNumber * 4 :(PinNumber - 8) * 4 ;
	return Position ;
}
/**================================================================
 * @Fn				-MCAL_GPIO_Init
 * @brief 			-Initializes the GPIOx PINy according to specified parameters in the PinConfig
 * @param [in] 		- GPIOx    : where x can be (A..E depending on device used ) to select the GPIO peripherals
 * @param [in] 		-PinConfig : pointer to a GPIO_PinConfig_t structure that contains
 * 					the configuration information for the specified GPIO PIN
 * @retval 			-none
 * Note				-Stm32F103C6 MCU has GPIO A,B,C,D,E Modules
 * 					but LQFP48 package has only GPIO A,B PART of C/D exported as external PINS from the MCU
 */
void MCAL_GPIO_Init(GPIO_TypeDef *GPIOx , GPIO_PINCONFIG_t *PinConfig)
{
	//Port configuration register low (GPIOx_CRL) Configure PINS from 0 >>> 7
	//Port configuration register High (GPIOx_CRH) Configure PINS from 8 >>> 15

	volatile uint32_t *ConfigRegister= NULL ;
	volatile uint8_t Pin_Config = 0 ;
	ConfigRegister = (PinConfig->GPIO_PinNumber < GPIO_PIN_8 )? &GPIOx->CRL :&GPIOx->CRH ;

	//clear CNF8[1:0] MODE8[1:0]

	(*ConfigRegister) &= ~(0xF << Get_CRLH_Position(PinConfig->GPIO_PinNumber)) ;

	//if Pin is output
	if (PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_OD || PinConfig->GPIO_MODE == GPIO_MODE_OUTPUT_PP || PinConfig->GPIO_MODE == GPIO_MODE_AF_OUTPUT_OD || PinConfig->GPIO_MODE == GPIO_MODE_AF_OUTPUT_PU)
	{
		Pin_Config = ((((PinConfig->GPIO_MODE - 4) << 2 ) | (PinConfig->GPIO_OUTPUT_SPEED))) & 0x0F ;
	}
	//if Pin is input
	else
	{
		//if  analog mode of input floating
		if (PinConfig->GPIO_MODE == GPIO_MODE_Analog || PinConfig->GPIO_MODE == GPIO_MODE_INPUT_FLO) //if  analog mode of input floating
		{
			Pin_Config = ((((PinConfig->GPIO_MODE << 2 )) | 0x0) & 0x0F) ;
		}
		else if(PinConfig->GPIO_MODE == GPIO_MODE_AF_INPUT) //if mode is Alternative input it considered as input floating
		{
			Pin_Config = ((((GPIO_MODE_INPUT_FLO << 2 )) | 0x0) & 0x0F) ;
		}
		else //then mode is PP or PU
		{
			Pin_Config = ((((GPIO_MODE_INPUT_PU << 2 )) | 0x0) & 0x0F) ;
			if(PinConfig->GPIO_MODE == GPIO_MODE_INPUT_PU)
			{
				GPIOx->ODR |= (PinConfig->GPIO_PinNumber) ;
			}
			else
			{
				GPIOx->ODR &= ~(PinConfig->GPIO_PinNumber);
			}
		}
	}

	//write on the CRL or CRH
	(*ConfigRegister) |= (Pin_Config << Get_CRLH_Position(PinConfig->GPIO_PinNumber)) ;
}




void MCAL_GPIO_Init_Port_Range(GPIO_TypeDef *GPIOx , GPIO_PINCONFIG_t *PinConfig, uint8_t PinCount)
{
	GPIO_PINCONFIG_t PinCfg  = *PinConfig ;
	volatile uint8_t StartingPin = 0 ;
	uint8_t i ;

	uint16_t PinsList[16] = {GPIO_PIN_0,GPIO_PIN_1,GPIO_PIN_2,GPIO_PIN_3,
							GPIO_PIN_4,GPIO_PIN_5,GPIO_PIN_6,GPIO_PIN_7,
							GPIO_PIN_8,GPIO_PIN_9,GPIO_PIN_10,GPIO_PIN_11,
							GPIO_PIN_12,GPIO_PIN_13,GPIO_PIN_14,GPIO_PIN_15};


	uint16_t PinNumber = PinConfig->GPIO_PinNumber ;
	while(!(PinNumber&0x01))
	{
		StartingPin++ ;
		PinNumber >>= 1 ;
	}

	for(i=StartingPin; PinCount>0; PinCount--)
	{
		PinCfg.GPIO_PinNumber = PinsList[i];
		MCAL_GPIO_Init(GPIOx, &PinCfg);
		i++ ;

	}

}


/**================================================================
 * @Fn				-MCAL_GPIO_DeInit
 * @brief 			-Reset the GPIOx PINy to default values
 * @param [in] 		- GPIOx : where x can be (A..E depending on device used ) to select the GPIO peripherals
 * @retval 			-none
 * Note				-none
 */
void MCAL_GPIO_DeInit(GPIO_TypeDef *GPIOx)
{
//	//Manual Reset
//	GPIOx->CRL = 0x44444444 ;
//	GPIOx->CRH = 0x44444444 ;
//	GPIOx->BRR = 0x00000000 ;
//	GPIOx->BSRR =0x00000000 ;
//	//GPIOx->IDR = ; (Read Only)
//	GPIOx->LCKR = 0x00000000 ;
//	GPIOx->ODR = 0x00000000 ;

	//Reset using RCC thought APB2 Peripheral reset Register (RCC_APB2ESTR)
	if(GPIOx == GPIOA)
	{
		RCC->APB2RSTR |= (1<<2);
	}
	else if (GPIOx == GPIOB)
	{
		RCC->APB2RSTR |= (1<<3);

	}
	else if (GPIOx == GPIOC)
	{
		RCC->APB2RSTR |= (1<<4);

	}
	else if (GPIOx == GPIOD)
	{
		RCC->APB2RSTR |= (1<<5);

	}
	else if (GPIOx == GPIOE)
	{
		RCC->APB2RSTR |= (1<<6);
	}
}



/**================================================================
 * @Fn				-MCAL_GPIO_ReadPin
 * @brief 			-reads specific Pin value
 * @param [in] 		- GPIOx    : where x can be (A..E depending on device used ) to select the GPIO peripherals
 * @param [in] 		-PinNumber : specify which pin to get value from the selected port according to @ref GPIO_Pins_define
 * @retval 			-the input Pin Value (two values according to @ref GPIO_Pin_state)
 * Note				-none
 */
uint8_t MCAL_GPIO_ReadPin(GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
	uint8_t Bit_State ;
	if ((GPIOx->IDR & PinNumber) != (uint16_t)GPIO_PIN_RESET)
	{
		Bit_State = GPIO_PIN_SET ;
	}
	else
	{
		Bit_State = GPIO_PIN_RESET ;
	}

	return Bit_State ;
}



/**================================================================
 * @Fn				-MCAL_GPIO_ReadPort
 * @brief 			-reads the input port value
 * @param [in] 		- GPIOx : where x can be (A..E depending on device used ) to select the GPIO peripherals
 * @retval 			- input Port Value
 * Note				-none
 */
uint16_t MCAL_GPIO_ReadPort(GPIO_TypeDef *GPIOx)
{
	uint16_t Port_Value ;
	Port_Value = (uint16_t)GPIOx->IDR  ;
	return Port_Value ;
}


/**================================================================
 * @Fn				-MCAL_GPIO_WritePin
 * @brief 			-writes output value to the specific Pin
 * @param [in] 		- GPIOx    : where x can be (A..E depending on device used ) to select the GPIO peripherals
 * @param [in] 		-PinNumber : to specify which pin to write the value on the selected port
 * @param [in] 		-PinValue  : value to be written on the specified pin
 * Note				-none
 */
void MCAL_GPIO_WritePin(GPIO_TypeDef *GPIOx , uint16_t PinNumber , uint8_t PinValue)
{
	if (PinValue != (uint8_t)GPIO_PIN_RESET)
	{
		//GPIOx->ODR |= PinNumber ;
		//or
		GPIOx->BSRR = PinNumber ;
	}
	else
	{
		//GPIOx->ODR &= ~PinNumber;
		//or
		GPIOx->BRR = PinNumber ;
	}
}


/**================================================================
 * @Fn				-MCAL_GPIO_WritePort
 * @brief 			-writes a value to the GPIOx port
 * @param [in] 		- GPIOx     : where x can be (A..E depending on device used ) to select the GPIO peripherals
 * @param [in] 		- PortValue : value to be written on the specified port
 * @retval 			- none
 * Note				-none
 */
void MCAL_GPIO_WritePort(GPIO_TypeDef *GPIOx , uint16_t PortValue)
{
	GPIOx->ODR = (uint32_t)PortValue ;
}



/**================================================================
 * @Fn				-MCAL_GPIO_TogglePin
 * @brief 			-toggles the GPIOx PINy value
 * @param [in] 		- GPIOx    : where x can be (A..E depending on device used ) to select the GPIO peripherals
 * @param [in] 		-PinNumber : to specify which pin to be toggled from the selected port
 * Note				-none
 */
void MCAL_GPIO_TogglePin(GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{
	GPIOx->ODR ^= PinNumber ;

}



/**================================================================
 * @Fn				-MCAL_GPIO_LockPin
 * @brief 			-The locking mechanism allows the IO configuration to be frozen
 * @param [in] 		-GPIOx : where x can be (A..E depending on device used ) to select the GPIO peripherals
 * @param [in] 		-PinNumber : specifies the port bit to read. Set by @ref GPIO_PINS_define
 * @retval 			-Ok if pin Config is locked Or ERROR if pin not locked (Ok & ERROR are defined @ref GPIO_Return_Lock)
 * Note				-none
 */
uint8_t MCAL_GPIO_LockPin(GPIO_TypeDef *GPIOx , uint16_t PinNumber)
{

	GPIOx->LCKR |= PinNumber ;
	uint32_t Temp = 1<<16 ;

	//lock sequance
	GPIOx->LCKR |= Temp ;
	GPIOx->LCKR &= ~Temp ;
	GPIOx->LCKR |= Temp ;
	Temp = GPIOx->LCKR ;

	if((uint32_t)(GPIOx->LCKR & 1<<16))
	{
		return GPIO_RETURN_LOCK_Enabled;
	}
	else
	{
		return GPIO_RETUN_LOCK_ERROR ;
	}
}
