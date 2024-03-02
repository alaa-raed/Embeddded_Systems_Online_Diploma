/*
 * US.h
 *
 *  Created on: Mar 2, 2024
 *      Author: Alaa
 */

#ifndef US_H_
#define US_H_

#include "state.h"

//define states
enum  US_State{
    US_waiting,
    US_busy
};

// Function prototypes
state_define(US_waiting);
state_define(US_busy);

extern void (*US_state)();

#endif /* US_H_ */
