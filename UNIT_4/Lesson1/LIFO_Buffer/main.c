/*
 * main.c
 *
 *  Created on: Feb 23, 2024
 *      Author: Alaa
 */


#include "Lifo.h"
unsigned int buffer1[5];

int main(){
	unsigned int temp=0;
	int i;


	LIFO__BUFFER_t UART,I2C;
	//Lifo Static allocation
	Init_Item(&UART,buffer1,5);
	//Lifo Dynamic allocation
	unsigned int* buffer2=(unsigned int*)malloc(5*sizeof(int));
	Init_Item(&I2C,buffer2,5);
	for(i=0;i<5;i++)
	{
		if(Add_Item(&UART,i)==LIFO_no_error){
		printf("UART_LIFO add : %d\n",i);
		}
	}
	for(i=0;i<5;i++)
		{
			if(Get_Item(&UART,&temp)==LIFO_no_error)
			{
			printf("UART_LIFO get : %d\n",temp);
		}
		}
	return 0;
}
