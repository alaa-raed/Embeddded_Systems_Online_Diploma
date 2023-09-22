/*
 * EX3.c
 *
 *  Created on: 18 Jul 2023
 *      Author: alaar
 */
#include<stdio.h>
int main(){
	int arr1[10][10],arr2[10][10],row,column;
	printf("Enter rows and column of matrix: ");
	fflush(stdin);fflush(stdout);
	scanf("%d  %d",&row,&column);
	printf("Enter elements of matrix:");
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			printf("Enter elements a%d%d : ",i+1,j+1);
			fflush(stdin);fflush(stdout);
			scanf("%d",&arr1[i][j]);
		}
	}
	printf("Entered matrix:\n");
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<column;j++)
			{

				printf("%d   ",arr1[i][j]);
			}
			printf("\n");
		}

				for(int i=0;i<row;i++)
				{
					for(int j=0;j<column;j++)
					{

						arr2[j][i]=arr1[i][j];
					}

				}
		printf("Transpose of Matrix:\n");
				for(int i=0;i<column;i++)
				{
					for(int j=0;j<row;j++)
					{

						printf("%d   ",arr2[i][j]);
					}
					printf("\n");
				}
	return 0;
}

