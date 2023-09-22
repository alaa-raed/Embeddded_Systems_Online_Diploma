/*
 * EX2.c
 *
 *  Created on: 18 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
#include<string.h>
int main(){
	int i=0;
	char string[200];
	printf("Enter string : ");
	fflush(stdin); fflush(stdout);
	gets(string);
	for(i=0;string[i]!='\0';++i);
	printf("Length of string: %d",i);
	return 0;
}
