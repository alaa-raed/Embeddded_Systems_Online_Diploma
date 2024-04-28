/*
 * State.h
 *
 *  Created on: Apr 27, 2024
 *      Author: Alaa
 */

#ifndef STATE_H_
#define STATE_H_

#define STATE_DEFINE(_StatFunc_) void st_##_StatFunc_()

#define STATE(_StatFunc_) st_##_StatFunc_

void Set_Presssure_Val(int Pval);

void High_Pressure_Detected();

void Start_Alarm();

void Stop_Alarm();

#endif /* STATE_H_ */
