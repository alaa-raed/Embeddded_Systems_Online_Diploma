/*
 * EX5.c
 *
 *  Created on: 18 Jul 2023
 *      Author: alaar
 */
#include<stdio.h>
int main()
{
	int arr[30],number,searched_number,location;
	printf("Enter no of elements : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&number);
	for(int i=0;i<number;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the elements to be searched: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&searched_number);
	for(int i=0;i<number;i++)
	{
		if(arr[i]==searched_number)
		{
			location=i;
			break;
		}
		else
		{
			location=number;
		}

	}
	if(location==number)
	{
		printf("Not Found\n");
	}
	else
	{
		printf("Number found at the location = %d",location+1);
	}
	return 0;
}

