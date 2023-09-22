/*
 * EX4.c
 *
 *  Created on: 4 Aug 2023
 *      Author: alaar
 */

#include<stdio.h>
#include<string.h>
int main()
{
	int arr[15];
	int *ptr;
	int size;
	printf("Input the number of elements to store in array(max15) : ");
	fflush(stdout);
	scanf("%d",&size);
	ptr=&arr[0];
	for(int i=0;i<size;i++)
		{
			printf("element - %d :",i+1);
			fflush(stdout);
			scanf("%d",ptr);
			ptr++;
		}



	ptr=&arr[size-1];
	printf("The elements of array in reverse order : \n");


	for(int i=size-1;i>=0;i--)
		{
			printf("element - %d:%d\n",i+1,*ptr);
			ptr--;
		}
	return 0;
}
