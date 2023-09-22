/*
 * EX5.c
 *
 *  Created on: 16 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
void main()
{
	char c;
	printf("Enter a character : ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&c);
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		printf(" %c is alphabet",c);
	}

	else
	{
		printf("%c is not an alphabet",c);
	}
}
