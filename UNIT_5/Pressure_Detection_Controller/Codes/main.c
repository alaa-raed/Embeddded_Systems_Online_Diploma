#include <stdint.h>
#include <stdio.h>


#include "Pressure_Sensor.h"
#include "Main_Algorithm.h"
#include "Alarm_Monitor.h"
#include "Alarm_Actuator.h"

extern void (*Pressure_Sensor_State)();
extern void (*Main_Algorithm)();
extern void (*Alarm_Monitor_State)();
extern void (*Alarm_Actuator)();

void Init(){
	Pressure_Sensor_Init();
	Alarm_Actuator_Init();
	Pressure_Sensor_State=STATE(reading);
	Main_Algorithm=STATE(High_Pressure);
	Alarm_Monitor_State=STATE(alarm_off);
	Stop_Alarm();
}
int main (){
	//Implement your Design
	Init();

	while (1)
	{
		Pressure_Sensor_State();
		Main_Algorithm();
		Alarm_Monitor_State();


	}
	return 0;
}
