/*
 * EX2.c
 *
 *  Created on: 3 Aug 2023
 *      Author: alaar
 */
#include<stdio.h>

int main()
{
	char arr[27];
	char *ptr;
	ptr=arr;
	printf("The Alphabets are: \n");
	for(int i=0;i<26;i++)
	{
		*ptr=i+'A';
		ptr++;
	}
	ptr=arr;
	for(int i=0;i<26;i++)
	{
	printf("%c  ",*ptr);
	ptr++;
	}
	return 0;
}

