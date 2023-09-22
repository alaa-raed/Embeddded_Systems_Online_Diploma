/*
 * EX6.c
 *
 *  Created on: 27 Jul 2023
 *      Author: alaar
 */
#include<stdio.h>
union job{
char name[32];
float salary;
int worker_no;
}u;
struct job1{
	char name[32];
	float salary;
	int worker_no;
}s;
int main(){
	printf("Size of union=%d\n",sizeof(u));
	printf("Size of structure=%d\n",sizeof(s));
	return 0;
}
