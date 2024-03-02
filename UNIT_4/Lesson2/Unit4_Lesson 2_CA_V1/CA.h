/*
 * CA.h
 *
 *  Created on: Mar 1, 2024
 *      Author: Alaa
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

// Define states
enum CA_State {
    waiting,
    driving
};

// Function prototypes
state_define(CA_waiting);
state_define(CA_driving);

// Global pointer to function
extern void (*CA_state)();

#endif /* CA_H_ */
