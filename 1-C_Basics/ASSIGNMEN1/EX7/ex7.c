/*
 * ex7.c
 *
 *  Created on: 16 Jul 2023
 *      Author: alaar
 */
#include<stdio.h>
int main()
{
	float a,b;
	printf("Enter value of a:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&b);
	a=a+b;
	b=a-b;
	a=a-b;
	printf("After swapping, value of a = %0.2f\nAfter swapping, value of b = %0.2f",a,b);
}

