/*
 * CA.c
 *
 *  Created on: Mar 2, 2024
 *      Author: Alaa
 */

#include "CA.h"

int US_get_distance_random (int l, int r, int count);



// Global variables
 int CA_speed = 0;
 int CA_distance = 0;
 int CA_threshold = 50;

// Global pointer to function
void (*CA_state)();
void US_SET_distance(int d){
	CA_distance=d;
	(CA_distance <= CA_threshold) ? (CA_state = state(CA_waiting)) : (CA_state = state(CA_driving));
	printf("US--------distance=%d-------->CA\n",CA_distance);
}

state_define(CA_waiting) {
    // State name
    enum CA_State state_id = CA_waiting;
    printf("Waiting state: distance = %d speed = %d\n", CA_distance, CA_speed);
    // State action
    CA_speed = 0;
    DC_Motor(CA_speed);
   // Check event

}

state_define(CA_driving) {
    // State name
    enum CA_State state_id = CA_driving;
    printf("Driving state: distance = %d speed = %d\n", CA_distance, CA_speed);
    // State action
    CA_speed = 30;
    DC_Motor(CA_speed);

    // Check event


}


