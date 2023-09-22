/*
 * ex6.c
 *
 *  Created on: 16 Jul 2023
 *      Author: alaar
 */
#include<stdio.h>
void main()
{
	float a,b,temp;
	printf("Enter value of a:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&a);
	printf("Enter value of b:");
	fflush(stdin); fflush(stdout);
	scanf("%f",&b);
	temp=a;
	a=b;
	b=temp;
	printf("After swapping, value of a = %0.2f\nAfter swapping, value of b = %0.2f",a,b);
}
