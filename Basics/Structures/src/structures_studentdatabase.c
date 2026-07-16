#include <stdio.h>

struct record{
		int id;
		char name[50];
		int age;
		char grade[50];
		int marks[5];
}student[50];

void add(int count){
	int i;
		printf("\nEnter student ID: ");
			scanf("%d", &student[count].id);
			while(getchar() != '\n');
		printf("Enter student name: ");
			gets(student[count].name);
		printf("Enter student age: ");
			scanf("%d", &student[count].age);
			while(getchar() != '\n');
		printf("Enter student grade: ");
			gets(student[count].grade);
		
		printf("Enter marks for 5 subject:\n");
		for(i = 0; i < 5; i++){
			printf("Subject %d: ", i+1);
			scanf("%d", &student[count].marks[i]);
		}
		
		printf("\nStudent added successfuly!\n");
} 

void search(int count){
	int search, i, j; 
	
	printf("\nEnter student ID to search: ");
	scanf("%d", &search);
	
	for(i= 0; i < count; i++){
		if(search == student[i].id){
			printf("\nID: %d", student[i].id);
			printf("\nName: %s", student[i].name);
			printf("\nAge: %d", student[i].age);
			printf("\nGrade: %s", student[i].grade);
			printf("\nMarks: ");
			for(j = 0; j < 5; j++){
				printf("%d ", student[i].marks[j]);
			}
			printf("\n");
			}
		}
		if (search != student[i].id){
			printf("ID not found.\n");
	}
}

void display(int count){
	int i, j;
	if(count == 0){
		printf("\nNo students\n\n");
	}
	else{
		printf("\nStudent details:");
		for(i = 0; i < count ; i++){
			printf("\nID: %d", student[i].id);
			printf("\nName: %s", student[i].name);
			printf("\nAge: %d", student[i].age);
			printf("\nGrade: %s", student[i].grade);
			printf("\nMarks: ");
			for(j = 0; j < 5; j++){
				printf("%d ", student[i].marks[j]);
			}
			printf("\n");
		}
	}
}

int main(){
	int num, count = 0;
	
	do{
		printf("\nMenu:");
		printf("\n\t1. Add a student");	
		printf("\n\t2. Search for a student");	
		printf("\n\t3. Display all student");	
		printf("\n\t4. Exit\n");
		
		printf("\nEnter your choice: ");
		scanf("%d", &num);
		
		switch(num){
			case 1:
				add(count);
				count++;			
			break;
			case 2:
				search(count);
			break;
			case 3:
				display(count);
			break;
			case 4:
				printf("Exiting the program...");
			break;
			default:
				printf("\nInvalid! Try again later.\n");
			break;
			}
			
	}while(num < 4);
	
	return 0;
}