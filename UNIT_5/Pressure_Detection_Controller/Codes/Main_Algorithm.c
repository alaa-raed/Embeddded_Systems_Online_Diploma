/*
 * Main_Algorithm.c
 *
 *  Created on: Apr 27, 2024
 *      Author: Alaa
 */

#include "Main_Algorithm.h"

enum{
	High_Pressure
}High_Pressure_State_id;




static int Pressure_val=0;
static int threshold=20;

void (*Main_Algorithm)();

void Set_Presssure_Val(int Pvalue){
	Pressure_val=Pvalue;
}

STATE_DEFINE(High_Pressure){
	High_Pressure_State_id=High_Pressure;
	if(Pressure_val>threshold)
	{
		High_Pressure_Detected();
	}
	Main_Algorithm=STATE(High_Pressure);

}
