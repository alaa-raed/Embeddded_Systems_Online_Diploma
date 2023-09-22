/*
 * ex3.c
 *
 *  Created on: 15 Jul 2023
 *      Author: alaar
 */
#include<stdio.h>
void main()
{
	int number1,number2,sum=0;
	printf("Enter two integers : ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d",&number1,&number2);
	sum=number1+number2;
	printf("You entered : %d",sum);
}
