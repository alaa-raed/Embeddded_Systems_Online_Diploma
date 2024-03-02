/*
 * CA.h
 *
 *  Created on: Mar 2, 2024
 *      Author: Alaa
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

//define states
enum  CA_State{
    CA_waiting,
    CA_driving
};

// Function prototypes
state_define(CA_waiting);
state_define(CA_driving);

extern void (*CA_state)();

#endif /* CA_H_ */
