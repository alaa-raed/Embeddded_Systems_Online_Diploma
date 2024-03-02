/*
 * state.h
 *
 *  Created on: Mar 2, 2024
 *      Author: Alaa
 */

#ifndef STATE_H_
#define STATE_H_

#include "stdio.h"
#include "stdlib.h"

//Automatic state function generate
#define state_define(_state_func_)	void st_##_state_func_()
#define state(_state_func_)			st_##_state_func_


//States Connections

void US_SET_distance(int d);
void DC_Motor(int s);

#endif /* STATE_H_ */
