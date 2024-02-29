/*
 * Lifo.h
 *
 *  Created on: Feb 23, 2024
 *      Author: Alaa
 */

#ifndef LIFO_H_
#define LIFO_H_

#include <stdio.h>
#include <stdlib.h>

//Type Definitions

typedef struct{
	unsigned int length;
	unsigned int count;
	unsigned int* base;
	unsigned int* head;
}LIFO__BUFFER_t;

typedef enum{
	LIFO_no_error,
	LIFO_full,
	LIFO_empty,
	LIFO_Null
}LIFO_status;

//APIs

LIFO_status Add_Item(LIFO__BUFFER_t* lifo_buf,unsigned int item);
LIFO_status Get_Item(LIFO__BUFFER_t* lifo_buf,unsigned int* item);
LIFO_status Init_Item(LIFO__BUFFER_t* lifo_buf,unsigned int* buf,int length);

#endif /* LIFO_H_ */
