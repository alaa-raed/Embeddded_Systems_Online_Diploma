/*
 * DC.h
 *
 *  Created on: Mar 2, 2024
 *      Author: Alaa
 */

#ifndef DC_H_
#define DC_H_

#include "state.h"
//define states
enum  DC_State{
    DC_idle,
    DC_busy
};

// Function prototypes
state_define(DC_idle);
state_define(DC_busy);

extern void (*DC_state)();


#endif /* DC_H_ */
