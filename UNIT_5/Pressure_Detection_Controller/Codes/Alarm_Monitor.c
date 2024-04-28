/*
 * Alarm_Monitor.c
 *
 *  Created on: Apr 27, 2024
 *      Author: Alaa
 */


#include"Alarm_Monitor.h"

enum{
	alarm_off,
	alarm_on,
}AlarmMonitor_State_id;

void (*Alarm_Monitor_State)(void);

void High_Pressure_Detected(){
	Alarm_Monitor_State=STATE(alarm_on);

}

STATE_DEFINE(alarm_off){
	AlarmMonitor_State_id=alarm_off;
	Stop_Alarm();

}

STATE_DEFINE(alarm_on){
	AlarmMonitor_State_id=alarm_on;
	Start_Alarm();
	Delay(60000);

	Alarm_Monitor_State=STATE(alarm_off);
}


