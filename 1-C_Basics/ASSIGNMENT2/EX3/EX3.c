/*
 * EX3.c
 *
 *  Created on: 16 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
void main()
{
	float number1,number2,number3;
	printf("Enter three numbers : ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f %f",&number1,&number2,&number3);
	if(number1>number2 && number1>number3 )
	{
		printf("Largest number = %.2f",number1);
	}
	else if(number2>number1 && number2>number3 )
	{
		printf("Largest number = %.2f",number2);
	}
	else
	{
		printf("Largest number = %.2f",number3);
	}
}
