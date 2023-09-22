/*
 * EX8.c
 *
 *  Created on: 16 Jul 2023
 *      Author: alaar
 */
#include<stdio.h>
void main()
{
	char operator;
	float number1,number2;
	printf("Enter Operator either + or - or / or * : ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&operator);
	printf("Enter two integers : ");
	fflush(stdin); fflush(stdout);
	scanf("%f %f",&number1,&number2);
	switch (operator){
	case '+':
		printf("%.2f + %.2f= %.2f",number1,number2,(number1+number2));
		break;
	case '-':
		printf("%.2f - %.2f= %.2f",number1,number2,(number1-number2));
		break;
	case '/':
		printf("%.2f / %.2f= %.2f",number1,number2,(number1/number2));
		break;
	case '*':
		printf("%.2f * %.2f= %.2f",number1,number2,(number1*number2));
		break;
	default:
		printf("Wrong Operator");
	}

}

