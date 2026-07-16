#include <stdio.h>
#include <stdlib.h>

int main(){
	
	struct list{
		int num;
		struct list *link;
	};
	
	int choice, duplicate;
	struct list *head, *newlist, *temp, *check;
	head = NULL;
	
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
			head = temp = newlist;
		}
		else {
			temp -> link = newlist;
			temp = newlist;
		}
		
	printf("Do you want to continue? (1 to continue, 0 if not): ");
	scanf("%d", &choice);
	}
	
	temp = head;
	check = head;
	
	while(check -> link != NULL){
		temp = temp -> link;
		check = check -> link -> link;
	}
	
	if (temp != NULL){
		printf("\nThe middle number: %d", temp->num);
	}
	else {
		printf("List is empty.");
	}
	return 0;
}