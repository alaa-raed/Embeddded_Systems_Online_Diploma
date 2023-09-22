/*
 * EX4.c
 *
 *  Created on: 16 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
void main()
{
	float number;
	printf("Enter a number : ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&number);
	if(number>0 )
	{
		printf(" %.2f is positive",number);
	}
	else if(number<0 )
	{
		printf(" %.2f is negative",number);
	}
	else
	{
		printf("You entered Zero");
	}
}
