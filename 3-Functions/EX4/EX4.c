/*
 * EX4.c
 *
 *  Created on: 22 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
int power(int base,int number);
int main(){
	int base,number;
	printf("Enter base number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&base);
	printf("Enter power number(positive integer): ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	printf("%d^%d= %d",base,number,power(base,number));
	return 0;
}
int power(int base,int number){
	if(number!=0)
	{
		return (base*power(base,number-1));
	}
	else
		return 1;
}
