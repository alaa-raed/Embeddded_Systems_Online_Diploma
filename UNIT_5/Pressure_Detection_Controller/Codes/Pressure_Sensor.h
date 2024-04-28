/*
 * Pressure_Sensor.h
 *
 *  Created on: Apr 27, 2024
 *      Author: Alaa
 */

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include"driver.h"

#include"State.h"


void Pressure_Sensor_Init();

STATE_DEFINE(reading);



#endif /* PRESSURE_SENSOR_H_ */
