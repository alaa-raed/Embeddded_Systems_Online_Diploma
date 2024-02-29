/*
 * fifo.c
 *
 *  Created on: Feb 23, 2024
 *      Author: Alaa
 */

#include "fifo.h"


FIFO_Status Init(FIFO_UFFER_t* fifo,element_type* buf,uint32_t length)
{
	if(buf==NULL)
	{
		return FIFO_Null;
	}
	fifo->base=buf;
	fifo->head=buf;
	fifo->tail=buf;
	fifo->count=0;
	fifo->length=length;

	return FIFO_no_error;
}
FIFO_Status Enqueue(FIFO_UFFER_t* fifo,element_type item)
{
	//check i fifo is valid
	if(!fifo->base||!fifo->head||!fifo->tail)
	{
		return FIFO_Null;
	}

	//check if fifo is full
	if(FIFO_IS_FULL(fifo)==FIFO_full)
	{
		return FIFO_full;
	}
	*(fifo->head)=item;
	fifo->count++;

	//circular fifo

	if(fifo->head==(fifo->base+(fifo->length)*sizeof(element_type))){

		fifo->head=fifo->base;
	}
	else
	{
		fifo->head++;
	}

	return FIFO_no_error;
}
FIFO_Status Dequeue(FIFO_UFFER_t* fifo,element_type *item)
{
	if(!fifo->base||!fifo->head||!fifo->tail)
	{
		return FIFO_Null;
	}
	if(fifo->count==0)
	{
		return FIFO_empty;
	}
	*item=*(fifo->tail);
	fifo->count--;
	if(fifo->tail==(fifo->base+(fifo->length)*sizeof(element_type))){

		fifo->tail=fifo->base;
	}
	else
	{
		fifo->tail++;
	}


	return FIFO_no_error;
}
FIFO_Status FIFO_IS_FULL(FIFO_UFFER_t* fifo){

	if(!fifo->base||!fifo->head||!fifo->tail)
	{
		return FIFO_Null;
	}
	if(fifo->count==fifo->length)
	{
		return FIFO_full;
	}
	return FIFO_no_error;
}
void print(FIFO_UFFER_t* fifo){
	element_type* temp;
	int i;
	if(fifo->count==0)
	{
		printf("=======FIFO is empty=======\n");
	}
	else
	{
		temp=fifo->tail;
		printf("=======FIFO  print=======\n");
		for(i=0;i<fifo->count;i++)
		{
			printf("\t %X \n",*temp);
			temp++;
		}
		printf("============\n");
	}
}

