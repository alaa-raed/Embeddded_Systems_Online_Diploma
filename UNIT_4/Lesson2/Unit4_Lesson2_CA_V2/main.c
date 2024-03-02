/*
 * main.c
 *
 *  Created on: Mar 2, 2024
 *      Author: Alaa
 */

#include "CA.h"
#include "US.h"
#include "DC.h"
void setup ()
{
	//initialize all drivers
	//initialize IRQ
	//initialize HAL US_DRIVER DC_DRIVER
	//Init blocks
	init_US();
	init_DC();
	//set states pointers for each block

	CA_state = state(CA_waiting);
	US_state = state(US_busy);
	DC_state = state(DC_idle);
}
int main(){
	volatile int i;
	setup();
	while(1){
		//call state for each block
		US_state();
		CA_state();
		DC_state();

		//delay
		for(i=0;i<1000;i++);

	}

	return 0;
}

