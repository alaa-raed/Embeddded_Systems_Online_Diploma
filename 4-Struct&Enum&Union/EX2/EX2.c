/*
 * EX2.c
 *
 *  Created on: 27 Jul 2023
 *      Author: alaar
 */
#include<stdio.h>
struct Sdistance{
	int feet;
	float inch;
};
int main(){
	struct Sdistance d1,d2,sum;

	printf("Enter information of 1st distance \n");
	printf("Enter Feet: ");
	fflush(stdout);
	scanf("%d",&d1.feet);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&d1.inch);
	printf("Enter information of 2nd distance \n");
	printf("Enter Feet: ");
	fflush(stdout);
	scanf("%d",&d2.feet);
	printf("Enter inch: ");
	fflush(stdout);
	scanf("%f",&d2.inch);
	sum.feet=d1.feet+d2.feet;
	sum.inch=d1.inch+d2.inch;
	if(sum.inch>12)
	{
		sum.inch-=12;
		++sum.feet;
	}
	printf("Sum of distances=%d'\- %.1f\"",sum.feet,sum.inch);
	return 0;
}

