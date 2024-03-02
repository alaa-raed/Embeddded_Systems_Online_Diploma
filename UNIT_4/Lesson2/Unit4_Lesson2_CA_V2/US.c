/*
 * US.c
 *
 *  Created on: Mar 2, 2024
 *      Author: Alaa
 */

#include "US.h"

int US_get_distance_random (int l, int r, int count);

// Global variables

int US_distance = 0;


// Global pointer to function
void (*US_state)();

void init_US(){

	printf("US Init\n");
}


state_define(US_busy) {
	// State name
	enum US_State state_id = US_busy;

	// State action
	US_distance=US_get_distance_random (45,55,1);

	printf("US_busy state: distance = %d  \n", US_distance);
	US_SET_distance(US_distance);
	US_state=state(US_busy);

}



int US_get_distance_random(int l, int r, int count) {
	int i, rand_num;
	for (i = 0; i < count; i++) {
		rand_num = (rand() % (r - l - 1)) + l;
	}
	return rand_num;
}


