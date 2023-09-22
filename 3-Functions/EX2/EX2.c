/*
 * EX2.c
 *
 *  Created on: 21 Jul 2023
 *      Author: alaar
 */
#include<stdio.h>
int fact(int num);
int main(){
	int x;
	printf("Enter a positive number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);
	if(x>0)
	{
		printf("Factorial of %d = %d",x,fact(x));
	}
	else
	{
		printf("Negative number doesn't exist");
	}
	return 0;
}
int fact(int num){

	if(num==0)
	{
		return 1;
	}
	else
	{
		return (num*fact(num-1));
	}
}

