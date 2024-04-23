/*
 * Student_Management.c
 *
 *  Created on: Apr 21, 2024
 *      Author: Alaa
 */

#include "Student_Management.h"
st student[55];

FIFO_Status Init(FIFO_UFFER_t* students,st* ST,uint32_t length)
{
	if(ST==NULL)
	{
		return FIFO_Null;
	}
	students->base=ST;
	students->head=ST;
	students->tail=ST;
	students->count=0;
	students->length=length;
	return FIFO_no_error;
}
FIFO_Status Enqueue(FIFO_UFFER_t* students,st ST)
{
	//check i fifo is valid
	if(!students->base||!students->head||!students->tail)
	{
		return FIFO_Null;
	}

	//check if fifo is full
	if(FIFO_IS_FULL(students)==FIFO_full)
	{
		return FIFO_full;
	}
	*(students->head)=ST;
	students->count++;

	//circular fifo

	if(students->head==(students->base+(students->length)*sizeof(st))){

		students->head=students->base;
	}
	else
	{
		students->head++;
	}

	return FIFO_no_error;
}
FIFO_Status Dequeue(FIFO_UFFER_t* students,st *ST)
{
	if(!students->base||!students->head||!students->tail)
	{
		return FIFO_Null;
	}
	if(students->count==0)
	{
		return FIFO_empty;
	}
	*ST=*(students->tail);
	students->count--;
	if(students->tail==(students->base+(students->length)*sizeof(st))){

		students->tail=students->base;
	}
	else
	{
		students->tail++;
	}


	return FIFO_no_error;
}
FIFO_Status FIFO_IS_FULL(FIFO_UFFER_t* students){

	if(!students->base||!students->head||!students->tail)
	{
		return FIFO_Null;
	}
	if(students->count==students->length)
	{
		return FIFO_full;
	}
	return FIFO_no_error;
}




void add_student_Manually(FIFO_UFFER_t* students){
	char temp_text[40];
	st new_student;
	DPRINTF("Add Roll Number: ");
	gets(temp_text);
	new_student.roll=atoi(temp_text);
	st *ST;
	ST=students->tail;
	for (int i = 0; i < students->count; i++) {
		if (ST->roll == new_student.roll) {
			printf("[INFO] Roll Number %d already exists. Student not added.\n", new_student.roll);
			return;
		}
		ST++;
	}

	DPRINTF("Add First Name: ");
	gets(new_student.fname);
	DPRINTF("Add Last Name: ");
	gets(new_student.lname);
	DPRINTF("Add GPA: ");
	gets(temp_text);
	new_student.GPA=atof(temp_text);
	DPRINTF("Add Course ID For Each Course: \n");
	for(int i=0;i<5;i++)
	{
		DPRINTF("Course ID %d: ",i+1);
		gets(temp_text);
		new_student.cid[i]=atoi(temp_text);
	}
	printf("[INFO]Roll Number %d Saved Successfully\n",new_student.roll);
	Enqueue(students,new_student);
}

void add_student_from_file(FIFO_UFFER_t* students) {

	FILE* fptr;
	int i=1;
	fptr = fopen("D:\\Project2_FirstTerm\\Sudent_Management.txt", "r");
	if (fptr == NULL) {
		printf("Error opening file\n");
		return;
	}

	st new_student;
	Init(students,student,55);
	int processedIDs[55];
	int numProcessedIDs = 0;

	while (fscanf(fptr, "%d %s %s %f %d %d %d %d %d",
			&new_student.roll, new_student.fname, new_student.lname, &new_student.GPA,
			&new_student.cid[0], &new_student.cid[1], &new_student.cid[2], &new_student.cid[3],
			&new_student.cid[4]) == 9) {
		// Check if the ID has already been processed
		int duplicate = 0;
		for (int k = 0; k < numProcessedIDs; k++) {
			if (processedIDs[k] == new_student.roll) {
				duplicate = 1;
				break;
			}
		}
		if (duplicate) {
			printf("[INFO]Roll Number %d is duplicated,Unsaved \n", new_student.roll);
			continue;  // Skip processing this student
		}

		// Add the ID to the processed list
		processedIDs[numProcessedIDs++] = new_student.roll;


		printf("[INFO]Roll Number %d Saved Successfully\n", new_student.roll);
		i++;
		Enqueue(students, new_student);
	}
	printf("============\n");
	printf("Student Information Added Successfully\n");
	printf("============\n");
	fclose(fptr);
}


void find_roll_number(FIFO_UFFER_t* students){

	char temp_text[40];
	st* ST;
	int i;
	ST=students->tail;
	DPRINTF("Enter Roll Number You Want To Find: ");
	gets(temp_text);
	if(students->count==0){
		DPRINTF("There is No Data To Show")
	}
	else{
		for(i=0;i<students->count;i++)
		{
			if(ST->roll==atoi(temp_text))
			{
				printf("Student Details are :\n");
				printf("First Name: %s\n", ST->fname);
				printf("Last Name: %s\n", ST->lname);
				printf("GPA: %.2f\n", ST->GPA);
				printf("Course IDs:");
				for (int k = 0; k < 5; k++) {
					printf(" %d", ST->cid[k]);
				}

				printf("\n\n");
				break;
			}
			ST++;
		}
		if (i == students->count) {
			printf("Roll Number Not Found\n");
		}
	}

	printf("============\n");
}
void find_first_name(FIFO_UFFER_t* students){
	char temp_text[40];
	st* ST;
	int i;
	ST=students->tail;
	DPRINTF("Enter First Name You Want To Find: ");
	gets(temp_text);
	if(students->count==0){
		DPRINTF("There is No Data To Show")
	}
	else{
		for(i=0;i<students->count;i++)
		{
			if(strcmp(ST->fname, temp_text) == 0)
			{
				printf("Student Details are :\n");
				printf("Roll Number: %d\n", ST->roll);
				printf("Last Name: %s\n", ST->lname);
				printf("GPA: %.2f\n", ST->GPA);
				printf("Course IDs:");
				for (int j = 0; j < 5; j++) {
					printf(" %d", ST->cid[j]);
				}
				printf("\n\n");
				break;
			}
			ST++;
		}
		if (i == students->count) {
			printf("First Name Not Found\n");
		}
	}
	printf("============\n");
}

void find_c(FIFO_UFFER_t* students){
	char temp_text[40];
	int count=0;
	st* ST;
	ST=students->tail;
	DPRINTF("Enter Course ID: ");
	gets(temp_text);
	if (students->count == 0) {
		DPRINTF("There is No Data\n");
	} else {
		for (int i = 0; i < students->count; i++) {
			for (int j = 0; j < 5; j++) {  // Assuming each student can have up to 10 courses
				if (ST->cid[j] == atoi(temp_text)) {
					printf("Student Details for Course ID %s:\n", temp_text);
					printf("Roll Number: %d\n", ST->roll);
					printf("First Name: %s\n", ST->fname);
					printf("Last Name: %s\n", ST->lname);
					printf("GPA: %.2f\n", ST->GPA);
					count++;
					break;  // Exit the inner loop once a match is found
				}
			}
			// Move to the next student
			ST++;
		}

		if (count == 0) {
			DPRINTF("No Students Found for Course ID %s\n", temp_text);
		} else {
			DPRINTF("Number of Students Enrolled in Course ID %s: %d\n", temp_text, count);
		}
	}
	DPRINTF("============\n");
}


void total_student(FIFO_UFFER_t* students){
	printf("Total Number Of student = %d\n",students->count);
	printf("You can add up to 55 students\n");
	printf("You can add   %d more students\n",55-(students->count));
	printf("============\n");
}
void delete_student(FIFO_UFFER_t* students){
	char temp_text[40];
	st* ST;
	int i;
	ST = students->tail;
	DPRINTF("Enter Roll Number You Want To Delete: ");
	gets(temp_text);
	if (students->count == 0) {
		DPRINTF("There is No Data\n");
	} else {
		for (i = 0; i < students->count; i++) {
			if (ST->roll == atoi(temp_text)) {
				// Dequeue the entire student record
				Dequeue(students, ST);
				DPRINTF("Information is removed successfully\n");
				break; // Exit the loop once deletion is done
			}
			ST++;
		}
		if (i == students->count) {
			DPRINTF("Roll Number Not Found\n");
		}
	}
	DPRINTF("============\n");
}
void update_student(FIFO_UFFER_t* students){
	char temp_text[40],choice[40],UP_TEMP[40];
	st* ST;
	int i;
	ST = students->tail;
	DPRINTF("Enter Roll Number You Want To Update Information: ");
	gets(temp_text);
	if (students->count == 0) {
		DPRINTF("There is No Data\n");
	} else {
		DPRINTF("Enter Number of choice you want to update\n");
		DPRINTF("1-Roll Number\n");
		DPRINTF("2-First Name\n");
		DPRINTF("3-Last Name\n");
		DPRINTF("4-GPA\n");
		DPRINTF("5-Courses\n");
		gets(choice);
		for (i = 0; i < students->count; i++) {
			if(ST->roll==atoi(temp_text))
			{
				switch(atoi(choice)) {
				case 1:
					DPRINTF("Enter Updated Roll Number\n");
					gets(UP_TEMP);
					ST->roll=atoi(UP_TEMP);
					break;
				case 2:
					DPRINTF("Enter Updated First Name\n");
					gets(ST->fname);

					break;
				case 3:
					DPRINTF("Enter Updated Last Name\n");
					gets(ST->lname);
					break;
				case 4:
					DPRINTF("Enter Updated GPA\n");
					gets(UP_TEMP);
					ST->GPA=atoi(UP_TEMP);
					break;
				case 5:
					DPRINTF("Enter Updated Courses \n");
					for(int k=0;k<5;k++)
						gets(UP_TEMP);
					ST->cid[i]=atoi(UP_TEMP);
					break;

				}
				DPRINTF("Information Is updated Successfully \n");
				break;
			}
			ST++;
		}
		if (i == students->count) {
			DPRINTF("Roll Number Not Found\n");
		}
	}
	DPRINTF("============\n");
}
void show_student(FIFO_UFFER_t* students){
	st* temp;
	int i;
	if(students->count==0)
	{
		printf("=======There is No Data To Show=======\n");
	}
	else
	{
		temp=students->tail;
		for(i=0;i<students->count;i++)
		{
			printf("Roll: %d\n", temp->roll);
			printf("First Name: %s\n", temp->fname);
			printf("Last Name: %s\n", temp->lname);
			printf("GPA: %.2f\n", temp->GPA);
			printf("Course IDs:");
			for (int i = 0; i < 5; i++) {
				printf(" %d", temp->cid[i]);
			}
			printf("\n\n");
			temp++;
		}

		printf("============\n");
		printf("Total Number Of student = %d\n",students->count);
		printf("You can add up to 55 students\n");
		printf("You can add   %d more students\n",55-(students->count));
		printf("============\n");
	}

}


