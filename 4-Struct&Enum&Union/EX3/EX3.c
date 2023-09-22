/*
 * EX3.c
 *
 *  Created on: 27 Jul 2023
 *      Author: alaar
 */
#include<stdio.h>
struct complex{
		float real;
		float img;
	};
	float addcomplex(float v1,float v2)
	{
		return v1+v2;
	}
int main(){
	struct complex num1,num2;
	printf("For 1st complex number\nEnter real and imaginary respectively : ");
	fflush(stdout);
	scanf("%f %f",&num1.real,&num1.img);
	printf("For 2nd complex number\nEnter real and imaginary respectively : ");
	fflush(stdout);
	scanf("%f %f",&num2.real,&num2.img);
	printf("Sum =%.1f+%.1fi",addcomplex(num1.real,num2.real),addcomplex(num1.img,num2.img));
	return 0;
}


