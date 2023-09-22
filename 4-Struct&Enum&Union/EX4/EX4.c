/*
 * EX4.c
 *
 *  Created on: 27 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>

struct Sstudent{
	int roll;
	char name[50];
	float marks;
};
int main(){
	struct Sstudent s[2];
	printf("Enter information of students:\n");
	for(int i=0;i<2;i++)
	{
		s[i].roll=i+1;
		printf("For roll number %d \n",s[i].roll);
		printf("Enter name: ");
		fflush(stdout);
		scanf("%s",s[i].name);
		printf("Enter marks: ");
		fflush(stdout);
		scanf("%f",&s[i].marks);
	}
	printf("Displaying information of students:");
	for(int i=0;i<2;i++)
		{
			printf("Information for roll number %d:\n",s[i].roll);
			printf("Name: %s\n",s[i].name);
			printf("Marks: %.1f\n",s[i].marks);
		}
	return 0;
}
