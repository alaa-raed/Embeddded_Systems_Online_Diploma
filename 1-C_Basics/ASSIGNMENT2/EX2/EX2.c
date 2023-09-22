/*
 * EX2.c
 *
 *  Created on: 16 Jul 2023
 *      Author: alaar
 */
#include<stdio.h>
void main()
{
	    char letter;
		printf("Enter an alphabet : ");
		fflush(stdin); fflush(stdout);
		scanf("%c",&letter);
		if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' )
		{
			printf("%c is a vowel",letter);
		}
		else
		{
			printf("%c is consonant",letter);
		}
}

