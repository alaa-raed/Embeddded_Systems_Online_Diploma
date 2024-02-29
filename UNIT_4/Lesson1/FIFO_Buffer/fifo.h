/*
 * fifo.h
 *
 *  Created on: Feb 23, 2024
 *      Author: Alaa
 */

#ifndef FIFO_H_
#define FIFO_H_


#include "stdio.h"
#include "stdint.h"

//User Configuration
//choose elment type(uint8_t,uint32_t,...)

#define element_type uint8_t
//create buffer
#define width 5
extern element_type uart_buff[width];

//fifo data types

typedef struct{
	unsigned int count;
    unsigned int length;
    element_type* tail;
    element_type* head;
    element_type* base;
}FIFO_UFFER_t;

typedef enum{
	FIFO_no_error,
	FIFO_empty,
	FIFO_full,
	FIFO_Null

}FIFO_Status;

//fifo APIs

FIFO_Status Init(FIFO_UFFER_t* fifo,element_type* buf,uint32_t length);
FIFO_Status Enqueue(FIFO_UFFER_t* fifo,element_type item);
FIFO_Status Dequeue(FIFO_UFFER_t* fifo,element_type *item);
FIFO_Status FIFO_IS_FULL(FIFO_UFFER_t* fifo);
void print(FIFO_UFFER_t* fifo);

#endif /* FIFO_H_ */
