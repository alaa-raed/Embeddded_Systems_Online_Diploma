/*
 * EX5.c
 *
 *  Created on: 27 Jul 2023
 *      Author: alaar
 */

#include <stdio.h>
#define pi 3.1415
#define Area(r) pi*r*r
int main(){
	float radius;
	printf("Enter the radius: ");
	fflush(stdout);
	scanf("%f",&radius);
	printf("Area = %.2f",Area(radius));
	return 0;
}
