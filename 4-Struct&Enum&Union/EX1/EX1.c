/*
 * EX1.c
 *
 *  Created on: 27 Jul 2023
 *      Author: alaar
 */

#include<stdio.h>
#include<conio.h>
struct Sstudent{

	char name[50];
	int roll;
	float marks;
};

int main(){
	struct Sstudent S1;
	printf("Enter Information of student: \n");
	printf("Enter name: ");
	fflush(stdout);
	gets(S1.name);
	printf("Enter Roll number: ");
	fflush(stdout);
	scanf("%d",&S1.roll);
    printf("Enter marks: ");
    fflush(stdout);
	scanf("%f",&S1.marks);
	printf("Displaying information: \n");
	printf("Name: %s\n",S1.name);
	printf("Roll: %d\n",S1.roll);
	printf("Marks: %.2f\n",S1.marks);
	return 0;
}
