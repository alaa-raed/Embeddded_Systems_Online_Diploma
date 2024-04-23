#ifndef STUDENT_MANAGEMENT_H_
#define STUDENT_MANAGEMENT_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define DPRINTF(...) {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}
typedef struct sinfo {
    char fname[50];
    char lname[50];
    int roll;
    float GPA;
    int cid[5];
} st;

extern st student[]; // Declaration of the student array

typedef struct {
    unsigned int count;
    unsigned int length;
    st* tail;
    st* head;
    st* base;
} FIFO_UFFER_t;

typedef enum {
    FIFO_no_error,
    FIFO_empty,
    FIFO_full,
    FIFO_Null
} FIFO_Status;

FIFO_Status Init(FIFO_UFFER_t* students, st* ST, unsigned int length);
FIFO_Status Enqueue(FIFO_UFFER_t* students, st ST);
FIFO_Status Dequeue(FIFO_UFFER_t* students, st* ST);
FIFO_Status FIFO_IS_FULL(FIFO_UFFER_t* students);

void add_student_from_file(FIFO_UFFER_t* students);//semi Done
void add_student_Manually(FIFO_UFFER_t* students);//semi Done
void find_roll_number(FIFO_UFFER_t* students);//Done
void find_first_name(FIFO_UFFER_t* students);//Done
void find_c(FIFO_UFFER_t* students);
void total_student(FIFO_UFFER_t* students);//Done
void delete_student(FIFO_UFFER_t* students);//Done
void update_student(FIFO_UFFER_t* students);//Done
void show_student(FIFO_UFFER_t* students);//Done

#endif /* STUDENT_MANAGEMENT_H_ */
