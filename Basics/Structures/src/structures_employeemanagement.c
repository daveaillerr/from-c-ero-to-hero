#include <stdio.h>

struct record{
		int id;
		char name[50];
		float salary;
}employee[50];

void add(int count){
	
		printf("\nEnter employee ID: ");
			scanf("%d", &employee[count].id);
			while(getchar() != '\n');
		printf("Enter employee name: ");
			gets(employee[count].name);
		printf("Enter employee salary: ");
			scanf("%f", &employee[count].salary);
		printf("\nEmployee added successfuly!\n");

} 

void display(int count){
	int i;
	if(count == 0){
		printf("\nNo employees\n");
	}
	else{
		printf("\nEmployee details:");
		for(i = 0; i < count ; i++){
			printf("\nID: %d", employee[i].id);
			printf("\nName: %s", employee[i].name);
			printf("\nSalary: %.2f\n", employee[i].salary);
		}
	}
}

void average(int count){
	float sum, final;
	
	for(int i = 0; i < count; i++){
		sum += employee[i].salary;
	}
	printf("\nAverage salary: %.2f\n", sum / count);
}

int main(){
	int num, count = 0;
	
	do{
		printf("\nEmployee Management System\n");
		printf("\nMenu:");
		printf("\n\t1. Add an employee");	
		printf("\n\t2. Display employee details");	
		printf("\n\t3. Calculate average salary");	
		printf("\n\t4. Exit\n");
		
		printf("\nEnter your choice: ");
		scanf("%d", &num);
		
		switch(num){
			case 1:
				add(count);
				count++;			
			break;
			case 2:
				display(count);
			break;
			case 3:
				average(count);
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