#include <stdio.h>
#include <stdlib.h>

int main(){
	
	struct list{
		int num;
		struct list *link;
	};
	
	int choice, duplicate;
	struct list *head, *newlist, *temp, *tail;
	head = NULL;
	tail = NULL;
	
	printf("Start listing your integers!\nPress 1 to start, press 0 to cancel: ");
	scanf("%d", &choice);
	
	
	while (choice){	
		if (choice > 1){
		printf("Invalid!");
		break;
		}
		
		newlist = (struct list *) malloc(sizeof(struct list));
		printf("Enter number: ");
		scanf("%d", &newlist->num);
		newlist->link = NULL;
		
		if (head == NULL){
			head = tail = newlist;
		}
		else {
			tail -> link = newlist;
			tail = newlist;
		}
		
	printf("Do you want to continue? (1 to continue, 0 if not): ");
	scanf("%d", &choice);
	}
	
	printf("\nEven number: \n");
	temp = head;
	while (temp != NULL){
		if (temp -> num % 2 == 0){
			printf("%d ", temp -> num);
		}
		temp = temp -> link;
	}
	
	printf("\nOdd number: \n");
	temp = head;
	while (temp != NULL){
		if (temp -> num % 2 != 0){
			printf("%d ", temp -> num);
		}
		temp = temp -> link;
	}
	

	return 0;
}