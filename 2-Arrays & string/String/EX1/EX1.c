/*
 * EX1.c
 *
 *  Created on: 18 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
#include<string.h>
int main()
{
	char string[200],character;
	int frequency=0;
	printf("Enter a string: ");
	fflush(stdin);fflush(stdout);
	gets(string);
	printf("Enter a character to find frequency : ");
	fflush(stdin);fflush(stdout);
	scanf("%c",&character);
	for(int i=0;string[i]!='\0';i++)
	{
		if(character==string[i])
		{
			frequency++;
		}
	}
	printf("frequency of %c = %d",character,frequency);
	return 0;
}
