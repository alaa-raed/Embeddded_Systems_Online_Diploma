/*
 * mani.c
 *
 *  Created on: Apr 21, 2024
 *      Author: Alaa
 */

#include<stdio.h>
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"
#include "Student_Management.h"


int main(){
	FIFO_UFFER_t students;
	char Choice[40];
	DPRINTF("**********Welcome To Student Management System**********\n");
	while(1){
		DPRINTF("Choose The Task You want to do\n");
		DPRINTF("1-Add Student Details From File\n");
		DPRINTF("2-Add Student Details Manually\n");
		DPRINTF("3-Find Student Details By Roll Number\n");
		DPRINTF("4-Find Student Details By First Name\n");
		DPRINTF("5-Find Student Details By Course ID\n");
		DPRINTF("6-Find Total Number of Students\n");
		DPRINTF("7-Delete Student Details By Roll Number\n");
		DPRINTF("8-Update Student Details By Roll Number\n");
		DPRINTF("9-Show All Information\n");
		DPRINTF("10-Exit\n");
		DPRINTF("Enter our Choice To perform The Task\n");
		gets(Choice);
		switch(atoi(Choice)){
		case 1:
			add_student_from_file(&students);
			break;
		case 2:
			add_student_Manually(&students);
			break;
		case 3:
			find_roll_number(&students);
			break;
		case 4:
			find_first_name(&students);
			break;
		case 5:
			find_c(&students);
			break;
		case 6:
			total_student(&students);
			break;
		case 7:
			delete_student(&students);
			break;
		case 8:
			update_student(&students);
			break;
		case 9:
			show_student(&students);
			break;
		case 10:
			DPRINTF("***Good Bye***");
			return 1;
			break;
		default:
			DPRINTF("wrong Choice\n");
		}

	}
	return 0;
}

