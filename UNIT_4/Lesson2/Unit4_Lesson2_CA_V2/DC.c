/*
 * DC.c
 *
 *  Created on: Mar 2, 2024
 *      Author: Alaa
 */


#include "DC.h"

// Global variables

int DC_speed = 0;


// Global pointer to function
void (*DC_state)();



void init_DC(){
	//init PWM

	printf("DC Init\n");
}

DC_Motor(int s)
{
	DC_speed=s;
	DC_state=state(DC_busy);
	printf("CA--------speed=%d-------->DC\n",DC_speed);
}
state_define(DC_idle) {
    // State name
    enum DC_State state_id = DC_idle;

    // State action
    //call PWM to make speed=DC_speed
    printf("DC_idle state: speed = %d  \n", DC_speed);



}

state_define(DC_busy) {
    // State name
    enum DC_State state_id = DC_busy;

    // State action
    DC_state=state(DC_idle);
    printf("DC_Busy state: speed = %d  \n", DC_speed);


}






