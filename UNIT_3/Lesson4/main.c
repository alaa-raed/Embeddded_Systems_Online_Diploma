/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

//Alaa Raed

#define SYSCTLRCGC2_R (*((volatile unsigned long*)0x400FE108)) 
#define GPIO_DIR_R    (*((volatile unsigned long*)0x40025400)) 
#define GPIO_DEN_R    (*((volatile unsigned long*)0x4002551C)) 
#define GPIO_DATA_R   (*((volatile unsigned long*)0x400253FC)) 

int main()
{
	volatile unsigned long delay_count; //Optmiztion off l ay hage stkhdm eldelay f ana kda dmnt en elfor ely hna msh httms7
	SYSCTLRCGC2_R=0x20;
	//delay to make sure if the GPIOF is up and running  
	for(delay_count=0;delay_count<200;delay_count++);
	GPIO_DIR_R |=1<<3;
	GPIO_DEN_R |=1<<3;
	while(1)
	{
		GPIO_DATA_R |=1<<3;
		for(delay_count=0;delay_count<200000;delay_count++);
		GPIO_DATA_R &=~(1<<3);
		for(delay_count=0;delay_count<200000;delay_count++);
	}
	return 0;
}
