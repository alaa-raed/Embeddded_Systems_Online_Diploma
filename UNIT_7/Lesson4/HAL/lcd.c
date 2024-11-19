/*
 * lcd.c
 *
 *  Created on: Oct 16, 2024
 *      Author: alaar
 */

#include "lcd.h"


void delay_ms(uint32_t time){
	uint32_t i,j;
	for(i=0;i<time;i++)
		for(j=0;j<255;j++);
}

void LCD_KICK(){
	MCAL_GPIO_WritePin(LCD_CTRL,EN_SWITCH ,GPIO_PIN_SET );
	delay_ms(50);
	MCAL_GPIO_WritePin(LCD_CTRL,EN_SWITCH ,GPIO_PIN_RESET );

}


void LCD_INIT(){

	delay_ms(20);
	PINCFG.GPIO_PinNumber= RS_SWITCH;
	PINCFG.GPIO_MODE =GPIO_MODE_OUTPUT_PP;
	PINCFG.GPIO_OUTPUT_SPEED=GPIO_SPEED_10M;
	MCAL_GPIO_Init_Port_Range(LCD_CTRL, &PINCFG, 3);

	delay_ms(15);

	PINCFG.GPIO_PinNumber = GPIO_PIN_0;
	PINCFG.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PINCFG.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init_Port_Range(LCD_Port, &PINCFG, 8);





	LCD_clear_screen();
	LCD_WRITE_COMMAND(LCD_FUNCTION_8BITS_2LINES);
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_BLINK);
}
void LCD_WRITE_COMMAND(unsigned char command){
	LCD_CHECK_LCD_ISBUSY();
	MCAL_GPIO_WritePort(LCD_Port, command);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	delay_ms(1);
	LCD_KICK();
}

void LCD_WRITE_CHAR(unsigned char character){
	LCD_CHECK_LCD_ISBUSY();
	MCAL_GPIO_WritePort(LCD_Port, character);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_SET);
	delay_ms(1);
	LCD_KICK();
}

void LCD_WRITE_STRING(char *string){
	int count=0;
	while(*string>0){
		count++;
		LCD_WRITE_CHAR(*string++);
		if(count==16){
			LCD_GOTO_XY(2, 0);
		}
		else if(count==32){
			LCD_clear_screen();
			LCD_GOTO_XY(1, 0);
			count=0;
		}
	}
}

void LCD_CHECK_LCD_ISBUSY(){
	PINCFG.GPIO_PinNumber = GPIO_PIN_0;
	PINCFG.GPIO_MODE=GPIO_MODE_INPUT_FLO;
	MCAL_GPIO_Init_Port_Range(LCD_Port, &PINCFG, 8);



	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_SET);
	MCAL_GPIO_WritePin(LCD_CTRL, RS_SWITCH, GPIO_PIN_RESET);

	LCD_KICK();

	PINCFG.GPIO_PinNumber = GPIO_PIN_0;
	PINCFG.GPIO_MODE=GPIO_MODE_OUTPUT_PP;
	PINCFG.GPIO_OUTPUT_SPEED = GPIO_SPEED_10M;
	MCAL_GPIO_Init_Port_Range(LCD_Port, &PINCFG, 8);
	MCAL_GPIO_WritePin(LCD_CTRL, RW_SWITCH, GPIO_PIN_RESET);
}


void LCD_clear_screen(){
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);
}

void LCD_GOTO_XY(unsigned char line,unsigned char position){
	if(line == 1){
		if(position<16 && position>=0){
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW+position);
		}

	}
	if(line == 2){
		if(position<16 && position>=0){
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+position);
		}
	}
}
