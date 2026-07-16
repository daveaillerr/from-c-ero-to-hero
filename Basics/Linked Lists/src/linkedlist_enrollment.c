#include <stdio.h>
#include <stdlib.h>

void menu();
void addstudent();
void displaystudent();
void searchstudent();

struct record{
	int rollnumber;
	char name[50];
	int age;
	float gpa;
	struct record *link;
}*head, *newnode, *tail, *temp;

int main(){
	int choice;
	
	menu();
	
	do{
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch (choice){
			case 1:
				addstudent();
			break;
			case 2:
				displaystudent();
			break;
			case 3:
				searchstudent();
			break;
			case 4:
				printf("\nThank you for using the Student Enrollment System!");
			break;
			default:
				printf("\nInvalid.");
			break;
		}
		
	}while(choice < 4);
	
	return 0;
}


void menu(){
	printf("---STUDENT ENROLLMENT SYSTEM---\n");
	printf("\n1. Add a new student\n");
	printf("2. Display enrolled students\n");
	printf("3. Search for a student by roll number\n");
	printf("4. Exit\n");
}

void addstudent(){
	newnode = (struct record *) malloc(sizeof(struct record));
	
	printf("\nEnter Roll Number: ");
	scanf("%d", &newnode->rollnumber);
	getchar();
	printf("Enter Name: ");
	gets(newnode->name);
	printf("Enter Age: ");
	scanf("%d", &newnode->age);
	printf("Enter GPA: ");
	scanf("%f", &newnode->gpa);
	newnode -> link = NULL;
	
	if (head == NULL){
		head = tail = newnode;
		}
	else {
		tail -> link = newnode;
		tail = newnode;
	}
	
	printf("\nStudent added successfully!\n");
}
void displaystudent(){
	temp = head;
	printf("\nEnrolled Students:\n");
	while(temp != NULL){
		printf("Roll Number: %d | Name: %s | Age: %d | GPA: %.2f\n", temp -> rollnumber, temp -> name, temp -> age, temp -> gpa);
		temp = temp -> link;
	}
}

void searchstudent(){
	int search, found = 0;
	
	printf("\nEnter Roll Number to search: ");
	scanf("%d", &search);
	
	temp = head;
	while(temp != NULL){
		if (search == temp -> rollnumber){
			printf("\nStudent Found: \n");
			printf("Roll Number: %d | Name: %s | Age: %d | GPA: %.2f\n", temp -> rollnumber, temp -> name, temp -> age, temp -> gpa);
			found = 1;
			break;
		}
		temp = temp -> link;
	} 
	if (found == 0){
		printf("\nStudent not found.\n");
	}
}