/*
 * EX4.c
 *
 *  Created on: 18 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
int main()
{
	int arr[30],number,inserted_number,location;
	printf("Enter no of elements: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	for(int i=0;i<number;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be inserted: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&inserted_number);
	printf("Enter the location: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&location);
		for(int i=number;i>=location;i--)
		{
			arr[i]=arr[i-1];
		}
		number++;
		arr[location-1]=inserted_number;
		for(int i=0;i<number;i++)
		{
			printf("%d  ",arr[i]);
		}
	return 0;
}
