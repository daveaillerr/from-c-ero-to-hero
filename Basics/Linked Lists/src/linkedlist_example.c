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
	
	printf("\nList of numbers you've entered: \n");
	
	temp = head;
	while (temp != NULL) {
		duplicate = 0;
		check = head; 
		
		while(check != temp){
			if (check -> num == temp -> num){
				duplicate = 1;
				break;
			}
			check = check -> link;
		}
			if (duplicate == 0){
				printf("%d ", temp -> num);
			}
			temp = temp -> link;
		}

	return 0;
}