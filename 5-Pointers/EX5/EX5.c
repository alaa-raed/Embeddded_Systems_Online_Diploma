/*
 * EX5.c
 *
 *  Created on: 4 Aug 2023
 *      Author: alaar
 */
#include<stdio.h>
struct SEmpolyee{
	char name[50];
	int ID;
};

int main(){
	struct SEmpolyee emp[]={{"Alaa",1001},{"Alex",1002},{"Mohamed",1003}};
	struct SEmpolyee *ptr;
	ptr=emp;
	ptr++;
	printf("Empolyee name: %s\nEmpolyee ID : %d",ptr->name,ptr->ID);

	return 0;
}


