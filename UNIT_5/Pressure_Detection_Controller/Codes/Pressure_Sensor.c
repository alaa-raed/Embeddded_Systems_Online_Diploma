/*
 * Pressure_Sensor.c
 *
 *  Created on: Apr 27, 2024
 *      Author: Alaa
 */

#include"Pressure_Sensor.h"

enum{
	reading,


}PS_State_id;

static int Pval=0;


void (*Pressure_Sensor_State)(void);

void Pressure_Sensor_Init(){
	GPIO_INITIALIZATION();

}

STATE_DEFINE(reading){

	PS_State_id=reading;
	Pval=getPressureVal();
	Set_Presssure_Val(Pval);
	Delay(10000);
}

