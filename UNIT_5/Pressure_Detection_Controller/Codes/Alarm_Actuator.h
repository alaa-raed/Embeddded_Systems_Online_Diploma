/*
 * Alarm_Actuator.h
 *
 *  Created on: Apr 27, 2024
 *      Author: Alaa
 */

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include "State.h"
#include"driver.h"
void Alarm_Actuator_Init();




STATE_DEFINE(ON);
STATE_DEFINE(OFF);
STATE_DEFINE(Waiting);
#endif /* ALARM_ACTUATOR_H_ */
