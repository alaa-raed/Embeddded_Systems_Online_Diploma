/*
 * Alarm_Actuator.c
 *
 *  Created on: Apr 27, 2024
 *      Author: Alaa
 */


#include "Alarm_Actuator.h"

int alarm_flag=0;

enum{
	Waiting,
	ON,
	OFF

}Alarm_Actuator_State_id;

void (*Alarm_Actuator)();

void Alarm_Actuator_Init(){
	GPIO_INITIALIZATION();
}

void Start_Alarm(){
	Alarm_Actuator=STATE(ON);
	Alarm_Actuator();
}

void Stop_Alarm(){
	Alarm_Actuator=STATE(OFF);
		Alarm_Actuator();
}

STATE_DEFINE(Waiting){
	Alarm_Actuator_State_id=Waiting;
}

STATE_DEFINE(OFF){
	Alarm_Actuator_State_id=OFF;
	Set_Alarm_actuator(1);
	Alarm_Actuator=STATE(Waiting);
}

STATE_DEFINE(ON){
	Alarm_Actuator_State_id=ON;
	Set_Alarm_actuator(0);
	Alarm_Actuator=STATE(Waiting);
}
