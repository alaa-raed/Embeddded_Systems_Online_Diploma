/*
 * main.c
 *
 *  Created on: Mar 1, 2024
 *      Author: Alaa
 */

#include "CA.h"
void setup ()
{
	//initialize all drivers
	//initialize IRQ
	//initialize HAL US_DRIVER DC_DRIVER
	//set states pointers for each block
	CA_state = state(CA_waiting);
}
int main(){
	volatile int i;
	setup();
	while(1){
		//call state for each block
		CA_state();

		//delay
		for(i=0;i<1000;i++);

	}

	return 0;
}
