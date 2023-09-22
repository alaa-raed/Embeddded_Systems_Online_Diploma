/*
 * EX1.c
 *
 *  Created on: 16 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
void main()
{
	int number;
	printf("Enter a integer you want to check : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&number);
	if(number%2==0)
	{
		printf("%d is even",number);
	}
	else
	{
		printf("%d is odd",number);
	}
}
