/*
 * ex4.c
 *
 *  Created on: 16 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
void main()
{
	float x,y;
	printf("Enter two numbers : ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&x,&y);

	printf("Product: %f",x*y);
}


