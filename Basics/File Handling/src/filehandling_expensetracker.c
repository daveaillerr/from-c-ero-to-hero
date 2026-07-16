#include <stdio.h>
#include <string.h>

FILE *file_expense, *temp;

void menu(void);
void add(int);
void view(void);
void deleted(void);

int main(){
	
	int choice, count = 0;
	menu();
	
	
	while(choice < 4){
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		getchar();
		
		switch(choice){
			case 1:
				add(count);
				count++;
				break;
			case 2:
				view();
				break;
			case 3:
				deleted();
				break;
			case 4:	
				printf("Exiting...");
				break;
			default:
				printf("Invalid Input.");
				break;
		}
	}
	
	return 0;
}

void menu(void){
	
	printf("::Expense Tracker::");
	printf("\n\t1. Add Expense");
	printf("\n\t2. View Expense");
	printf("\n\t3. Delete Expense");
	printf("\n\t1. Exit\n");
	
}

void add(int count){
	char content[100], date[100], description[100];
	float amount;
	
	file_expense = fopen("expense.txt", "a");
	
	
	if (count == 0){
		fprintf(file_expense,"Date 			Description 			Amount\n");
		fprintf(file_expense,"--------------------------------------------------------------");		
	}

	printf("Enter date (YYYY-MM-DD): ");
	gets(date);
	printf("Enter description: ");
	gets(description);
	printf("Enter amount: ");
	scanf("%f", &amount);
	getchar();
	
	fprintf(file_expense, "\n%s\t\t\t%s\t\t\t%.2f", date, description, amount);	
	
	fclose(file_expense);	
	
	printf("Added Succesfully!\n");
}
		
void view(void){
	char content[100];
	
	if (file_expense == NULL){
		printf("Nothing to show here yet...");	
	}
	
	file_expense = fopen("expense.txt", "r");
	
	while(fgets(content, sizeof(content), file_expense)){
		printf("%s", content);	
	}
	
	fclose(file_expense);
	
	printf("\n");
	
}

void deleted(void){
	char content[100], delete_date[100];
	int found = 1;
	
	printf("Enter date (YYYY-MM-DD) of expense to delete: ");
	gets(delete_date);
	
	file_expense = fopen("expense.txt", "r");
	temp = fopen("temp.txt", "w");
	
	while(fgets(content, sizeof(content), file_expense)){
			if (strncmp(content, delete_date, strlen(delete_date)) != 0){
				fputs(content, temp);
			}
			else{
				found = 0;
			}
	}
	
	fclose(file_expense);
	fclose(temp);
	
	rewind(file_expense);
	file_expense = fopen("expense.txt", "w");
	temp = fopen("temp.txt", "r");
	
	while(fgets(content, sizeof(content), temp)){
			fputs(content, file_expense);
	}
	
	fclose(file_expense);
	fclose(temp);
	
	remove("temp.txt");
	if (found == 1){
		printf("Item does not exist.\n");
	}
	else{
		printf("Removed Successfully!\n");	
	}

}
