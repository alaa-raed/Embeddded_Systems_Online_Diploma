/*
 * EX3.c
 *
 *  Created on: 19 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
#include<string.h>
int main(){
	char s1[100];
	int length=0;
	printf("Enter the string : ");
	fflush(stdin);fflush(stdout);
	gets(s1);
	length=strlen(s1)-1;
	printf("Reverse String: ");
	for(int i=length;i>=0;i--)
	{
		printf("%c",s1[i]);
	}
	return 0;
}
