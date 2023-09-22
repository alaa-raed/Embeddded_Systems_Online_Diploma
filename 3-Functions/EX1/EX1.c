/*
 * EX1.c
 *
 *  Created on: 21 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
int prime(int number);

int main(){
	int a,res,b;
	printf("Enter two numbers\n");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&a,&b);
	printf("Prime numbers between %d and %d are :",a,b);

	for(int i=a;i<=b;i++)
	{
		res=prime(i);
		if(res==1)
		    printf("%d  ",i);
		else
			continue;
	}
	return 0;
}
int prime(int number){
	int i;
	for(i=2;i<=number-1;i++)
	{
		if(number%i==0)
			return 0;

	}
	return 1;
}
