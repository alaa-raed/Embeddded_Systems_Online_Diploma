/*
 * EX7.c
 *
 *  Created on: 16 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
void main()
{
	int number,factorial=1;
	printf("Enter an integer : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&number);
	if(number ==0)
	{
		printf("Factorial = 1");
	}
	if(number<0)
	{
		printf("Error!!! Factorial of negative number doesn't exist ");
	}
	else
	{
		for(int i=1;i<=number;i++)
		{
			factorial*=i;
		}
		printf("Factorial = %d",factorial);
	}
}
