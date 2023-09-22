/*
 * EX2.c
 *
 *  Created on: 18 Jul 2023
 *      Author: alaar
 */
#include<stdio.h>
int main(){
	float arr[20],sum=0.0,average=0.0;
	int number;
	printf("Enter the numbers of data: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	for(int i=0;i<number;i++)
	{
		printf("Enter number: ");
		fflush(stdin);fflush(stdout);
		scanf("%f",&arr[i]);
		sum+=arr[i];
	}
	average=sum/number;
	printf("Average = %.2f",average);
	return 0;
}

