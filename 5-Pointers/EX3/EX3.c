/*
 * EX3.c
 *
 *  Created on: 3 Aug 2023
 *      Author: alaar
 */

#include<stdio.h>
#include<string.h>
int main()
{
	char arr[100];
	char *ptr;
	int length;
	printf("Input a string : ");
	fflush(stdout);
	scanf("%s",arr);
	length=strlen(arr);


    ptr=&arr[0];
	for(int i=0;i<length;i++)
	{
		*ptr=arr[i];
		ptr++;
	}
	ptr=&arr[length-1];
	printf("Reverse of string : ");


	for(int i=length-1;i>=0;i--)
		{
			printf("%c",*ptr);
			ptr--;
		}
	return 0;
}
