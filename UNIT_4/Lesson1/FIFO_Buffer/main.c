/*
 * main.c
 *
 *  Created on: Feb 23, 2024
 *      Author: Alaa
 */

#include "fifo.h"
element_type uart_buff[width];
int main(){
	FIFO_UFFER_t UART;
	element_type i,temp=0;
	if(Init(&UART,uart_buff,5)==FIFO_no_error)
	{
		printf("=======FIFO is initialized=======\n");
	}
	for(i=0;i<7;i++)
	{
		printf("FIFO Enqueue (%X)\n",i);
		if(Enqueue(&UART,i)==FIFO_no_error)
		{
			printf("FIFO enqueue is-----------Done\n");
		}
		else
		{
			printf("FIFO enqueue is-----------Failed\n");
		}
	}

	print(&UART);

	if(Dequeue(&UART,&temp)==FIFO_no_error)
	{
		printf("=======FIFO Dequeue %X is Done=======\n",temp);
	}
	if(Dequeue(&UART,&temp)==FIFO_no_error)
	{
		printf("=======FIFO Dequeue %X is Done=======\n",temp);
	}
	print(&UART);
	return 0;
}
