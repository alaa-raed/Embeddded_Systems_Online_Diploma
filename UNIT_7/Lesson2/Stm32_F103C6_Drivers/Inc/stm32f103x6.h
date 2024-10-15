/*
 * stm32f103x6.h
 *
 *  Created on: Oct 14, 2024
 *      Author: alaar
 */

#ifndef INC_STM32F103X6_H_
#define INC_STM32F103X6_H_

/*Includes*/
#include<stdlib.h>
#include<stdint.h>

/*Base Addresses For Memories*/
#define FLASH_Memory_BASE					0x80000000UL
#define System_Memory_BASE					0x1FFFF000UL
#define SRAM_Memory_BASE					0x20000000UL


#define Peripherals_BASE					0x40000000UL

#define cortex_M3_internal_Peripherals_BASE	0xE0000000UL

/*Base Addresses for AHB Peripherals*/
#define RCC_BASE							0X40021000UL

/*Base Addresses for APB2 Peripherals*/

//GPIO
//A,B fully included in LQFP48 Package
#define GPIOA_BASE								0X40010800UL
#define GPIOB_BASE								0X40010C00UL
//C,D partially included in LQFP48 Package
#define GPIOC_BASE								0X40011000UL
#define GPIOD_BASE								0X40011400UL
//E not included in LQFP48 Package
#define GPIOE_BASE								0X40011800UL

//=================

/*AFIO*/
#define AFIO_BASE							0X40010000UL

/*EXTI*/
#define EXTI_BASE							0X40010400UL


/*Base Addresses for APB1 Peripherals*/

//===========================================================

/***************Peripheral Register***************/

/*Peripheral Register : GPIO*/
typedef struct{
	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;
}GPIO_TypeDef;

/*Peripheral Register : RCC*/
typedef struct{
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
	volatile uint32_t APB2RSTR;
	volatile uint32_t APB1RSTR;
	volatile uint32_t AHBENR;
	volatile uint32_t APB2ENR;
	volatile uint32_t APB1ENR;
	volatile uint32_t BDCR;
	volatile uint32_t CSR;
}RCC_TypeDef;

/*Peripheral Register : EXTI*/
typedef struct{
	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t BRR;
	volatile uint32_t PR;
}EXTI_TypeDef;

/*Peripheral Register : AFIO*/
typedef struct{
	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR1;
	volatile uint32_t EXTICR2;
	volatile uint32_t EXTICR3;
	volatile uint32_t EXTICR4;
	uint32_t RESRVED0;
	volatile uint32_t MAPR2;
}AFIO_TypeDef;

/*Peripheral Instant*/
#define GPIOA							((GPIO_TypeDef*)GPIOA_BASE)
#define GPIOB							((GPIO_TypeDef*)GPIOB_BASE)
#define GPIOC							((GPIO_TypeDef*)GPIOC_BASE)
#define GPIOD							((GPIO_TypeDef*)GPIOD_BASE)
#define GPIOE							((GPIO_TypeDef*)GPIOE_BASE)

#define RCC								((RCC_TypeDef*)RCC_BASE)

#define EXTI							((EXTI_TypeDef*)EXTI_BASE)

#define AFIO							((AFIO_TypeDef*)AFIO_BASE)

/*clock enable macros*/
#define RCC_GPIOA_CLK_EN()				(RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()				(RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()				(RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()				(RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()				(RCC->APB2ENR |= 1<<6)

#define AFIO_GPIOE_CLK_EN()				(RCC->APB2ENR |= 1<<0)

#endif /* INC_STM32F103X6_H_ */
