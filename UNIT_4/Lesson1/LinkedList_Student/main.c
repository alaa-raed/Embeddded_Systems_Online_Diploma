/*
 * main.c
 *
 *  Created on: Feb 24, 2024
 *      Author: Alaa
 */


#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"

#define DPRINTF(...)  {fflush(stdout);\
		fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);\
		fflush(stdin);}

//effective data

struct SData{
	int ID;
	char name[40];
	float height;
};

//linkedlist node

struct SStudent{
	struct SData student;
	struct SStudent* PNextStudent;
};

struct SStudent* GPFirstStudent=NULL;


void AddStudent()
{
	struct SStudent* PNewStudent;
	struct SStudent* PLastStudent;
	char temp_text[40];

	// Allocate memory for the new student
	PNewStudent = (struct SStudent*)malloc(sizeof(struct SStudent));
	if(PNewStudent == NULL) {
		DPRINTF("Memory allocation failed\n");
		return;
	}

	// Fill new record
	DPRINTF("Enter your ID:\n");
	gets(temp_text);
	PNewStudent->student.ID = atoi(temp_text);

	DPRINTF("Enter your Name:\n");
	gets(PNewStudent->student.name);

	DPRINTF("Enter your Height:\n");
	gets(temp_text);
	PNewStudent->student.height = atof(temp_text);

	PNewStudent->PNextStudent = NULL; // Set next pointer to NULL as it will be the last node

	// If the list is empty, make the new student the first student
	if(GPFirstStudent == NULL) {
		GPFirstStudent = PNewStudent;
	} else {
		// Traverse the list to find the last student
		PLastStudent = GPFirstStudent;
		while(PLastStudent->PNextStudent != NULL) {
			PLastStudent = PLastStudent->PNextStudent;
		}

		// Set the next pointer of the last student to the new student
		PLastStudent->PNextStudent = PNewStudent;
	}
}
int DeleteStudent()
{
	struct SStudent* PSelStudent;
	struct SStudent* PLasttStudent;
	unsigned int Selected_ID;
	char temp_text[40];
	DPRINTF("Enter The ID you want to Delete\n");
	gets(temp_text);
	Selected_ID=atoi(temp_text);
	//check if list is empty
	if(GPFirstStudent){
		PSelStudent=GPFirstStudent;
		PLasttStudent=NULL;
		//Loop on all records
		while(PSelStudent){
			if(PSelStudent->student.ID==Selected_ID)
			{
				if(PLasttStudent)//if selected ID is not the first
				{
					PLasttStudent->PNextStudent=PSelStudent->PNextStudent;
				}else//if the selected ID is the first
				{
					GPFirstStudent=PSelStudent->PNextStudent;

				}
				free(PSelStudent);
				return 1;
			}
			PLasttStudent=PSelStudent;
			PSelStudent=PSelStudent->PNextStudent;
		}

	}
	DPRINTF("You Entered Wrong ID\n");
	return 0;
}

void DeleteAll(){

	struct SStudent* PCurrentStudent=GPFirstStudent;
	//check if list is empty
	if(GPFirstStudent){

		while(PCurrentStudent)
		{
			struct SStudent* PTempStudent=PCurrentStudent;
			PCurrentStudent=PCurrentStudent->PNextStudent;
			free(PTempStudent);
		}
		GPFirstStudent=NULL;
	}
	else
	{
		DPRINTF("List is Empty\n");
	}
}

void Reverse(){
	struct SStudent* PCurrentStudent=GPFirstStudent;
	struct SStudent* PPrevtStudent=NULL;
	struct SStudent* PNextStudent;


	//check if list is empty
	if(GPFirstStudent==NULL)
	{
		DPRINTF("List is Empty\n");

	}
	else

	{

		while(PCurrentStudent)
		{
			PNextStudent=PCurrentStudent->PNextStudent;//SAVE NODE
			PCurrentStudent->PNextStudent=PPrevtStudent;//REVERSE POINTER
			//Move Forward
			PPrevtStudent=PCurrentStudent;
			PCurrentStudent=PNextStudent;





		}
		GPFirstStudent=PPrevtStudent;
	}
	DPRINTF("Reverse is Done\n");
}
int GET_NTH()
{

	int count=1;
	struct SStudent* PCurrentStudent=GPFirstStudent;

	char temp_text[40];
	int Slected_Node;
	if(GPFirstStudent==NULL)
	{
		DPRINTF("List is Empty\n");
	}
	else
	{
		DPRINTF("Enter Index Of Student \n");
		gets(temp_text);
		Slected_Node=atoi(temp_text);
		while(PCurrentStudent)
		{
			if(Slected_Node==count)
			{
				DPRINTF("\n Index Number : %d",count);
				DPRINTF("\n \t ID: %d",PCurrentStudent->student.ID);
				DPRINTF("\n \t Name: %s",PCurrentStudent->student.name);
				DPRINTF("\n \t Height: %f",PCurrentStudent->student.height);
				return 1;
			}
			count++;
			PCurrentStudent=PCurrentStudent->PNextStudent;
		}
	}
	printf("Index Exceeds List\n");
	return 0;
}
int LengthOfLinkedList(){
	struct SStudent* PCurrentStudent=GPFirstStudent;
	int Length=0;

	//check if list is empty
	if(GPFirstStudent==NULL)
	{
		DPRINTF("List is Empty\n");

	}
	else
	{
		while(PCurrentStudent)
		{
			Length++;
			PCurrentStudent=PCurrentStudent->PNextStudent;

		}

	}
	return Length;
}
void MiddleOfLinkedList()
{
	struct SStudent* PCurrentStudent=GPFirstStudent;
	struct SStudent* PNEXTNEXTStudent=GPFirstStudent;


	//check if list is empty
	if(GPFirstStudent==NULL)
	{
		DPRINTF("List is Empty\n");

	}
	else
	{

		while(PNEXTNEXTStudent && PNEXTNEXTStudent->PNextStudent) {
			PCurrentStudent = PCurrentStudent->PNextStudent;
			PNEXTNEXTStudent = PNEXTNEXTStudent->PNextStudent->PNextStudent;
		}

		DPRINTF("\n \t ID: %d",PCurrentStudent->student.ID);
		DPRINTF("\n \t Name: %s",PCurrentStudent->student.name);
		DPRINTF("\n \t Height: %f",PCurrentStudent->student.height);
	}

}
int GetNTHNodeFromEnd() {
    struct SStudent* PCurrentStudent = GPFirstStudent;
    int Length = LengthOfLinkedList();
    int count = 0;
    char temp_text[40];
    int Selected_Node;

    // Check if list is empty
    if (GPFirstStudent == NULL) {
        DPRINTF("List is Empty\n");
        return 0;
    }

    DPRINTF("Enter Index Of Student \n");
    gets(temp_text);
    Selected_Node = atoi(temp_text);

    // Calculate the index from the end
    int indexFromEnd = Length - Selected_Node + 1;

    // Traverse the list to find the node at the calculated index from the end
    while (PCurrentStudent) {
        count++;
        if (count == indexFromEnd) {
            DPRINTF("\n Index Number From End: %d", Selected_Node);
            DPRINTF("\n \t ID: %d", PCurrentStudent->student.ID);
            DPRINTF("\n \t Name: %s", PCurrentStudent->student.name);
            DPRINTF("\n \t Height: %f", PCurrentStudent->student.height);
            return 1;
        }
        PCurrentStudent = PCurrentStudent->PNextStudent;
    }

    // If the selected index is out of range
    printf("Index Exceeds List\n");
    return 0;
}


void Display(){
	struct SStudent* PCurrentStudent=GPFirstStudent;
	int count=0;
	//check if list is empty
	if(GPFirstStudent==NULL)
	{
		DPRINTF("List is Empty\n");

	}
	else
	{
		while(PCurrentStudent)
		{
			DPRINTF("\n Record Number : %d",count+1);
			DPRINTF("\n \t ID: %d",PCurrentStudent->student.ID);
			DPRINTF("\n \t Name: %s",PCurrentStudent->student.name);
			DPRINTF("\n \t Height: %f",PCurrentStudent->student.height);
			count++;
			PCurrentStudent=PCurrentStudent->PNextStudent;

		}
	}
}
int main(){
	char temp_text[40];
	while(1){
		DPRINTF("\n=======================");
		DPRINTF("\n \t choose one of the following options : \n");
		DPRINTF("1- Add Students \n");
		DPRINTF("2- Delete Student \n");
		DPRINTF("3- Delete All \n");
		DPRINTF("4- Display Students\n");
		DPRINTF("5- Reverse Students\n");
		DPRINTF("6- Get Index Of Students\n");
		DPRINTF("7- Get Number Of Students\n");
		DPRINTF("8- Get Middle Student Of List\n");
		DPRINTF("9- Get Index Of Students From End\n");


		DPRINTF("Enter Option Number\n");
		gets(temp_text);
		DPRINTF("=======================\n");

		switch(atoi(temp_text)){
		case 1:
			AddStudent();
			break;
		case 2:
			DeleteStudent();
			break;
		case 3:
			DeleteAll();

			break;
		case 4:
			Display();
			break;
		case 5:
			Reverse();
			break;
		case 6:
			GET_NTH();
			break;
		case 7:
			DPRINTF("Number of Student : %d\n",LengthOfLinkedList());
			break;
		case 8:
			MiddleOfLinkedList();
			break;
		case 9:
			GetNTHNodeFromEnd();
			break;
		default:
			DPRINTF("wrong Option\n");
		}
	}

	return 0;
}



