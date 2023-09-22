/*
 * EX6.c
 *
 *  Created on: 16 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
void main()
{
	int sum=0,integer;
	printf("Enter an integer : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&integer);
	for(int i=1;i<=integer;i++)
	{
		sum+=i;
	}
	printf("Sum = %d",sum);
}
