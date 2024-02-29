/*
 * Lifo.c
 *
 *  Created on: Feb 23, 2024
 *      Author: Alaa
 */

#include "Lifo.h"

LIFO_status Add_Item(LIFO__BUFFER_t* lifo_buf,unsigned int item){
	//check if lifo is valid
	if(!lifo_buf->base||!lifo_buf->head){
		return LIFO_Null;
	}
	//check if lifo is full
	if(lifo_buf->count==lifo_buf->length)
	{
		return LIFO_full;
	}

	//Add value
	*(lifo_buf->head)=item;
	lifo_buf->head++;
	lifo_buf->count++;
	return LIFO_no_error;

}
LIFO_status Get_Item(LIFO__BUFFER_t* lifo_buf,unsigned int* item){

	//check if lifo is valid
		if(!lifo_buf->base||!lifo_buf->head){
			return LIFO_Null;
		}

	//check if lifo is empty
	if(lifo_buf->count==0)
	{
		return LIFO_empty;
	}

		lifo_buf->head--;
		*item=*(lifo_buf->head);
		lifo_buf->count--;
		return LIFO_no_error;
}
LIFO_status Init_Item(LIFO__BUFFER_t* lifo_buf,unsigned int* buf,int length){

	if(buf==NULL)
	{
		return LIFO_Null;
	}
	lifo_buf->base=buf;
	lifo_buf->head=buf;
	lifo_buf->length=length;
	lifo_buf->count=0;
	return LIFO_no_error;
}
