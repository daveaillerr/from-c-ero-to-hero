#include <stdio.h>
#include <stdlib.h>

int main(){
	
	struct list{
		int num;
		struct list *link;
	};
	
	int choice, duplicate, i = 1, counter = 0;
	struct list *head, *newlist, *temp, *tail;
	head = NULL;
	tail = NULL;
	
	printf("Input the number of nodes: ");
	scanf("%d", &choice);
	
	
	while (choice > counter){	
		newlist = (struct list *) malloc(sizeof(struct list));
		printf("Input data for the node %d: ", i);
		scanf("%d", &newlist->num);
		newlist->link = NULL;
		
		if (head == NULL){
			head = tail = newlist;
		}
		else {
			tail -> link = newlist;
			tail = newlist;
		}
		counter++;
		i++;
	}
	
	temp = head;
	printf("\nData entered in the list are: ");
	while(temp != NULL){
		printf("\nData: %d", temp -> num);
		temp = temp -> link;
	}
	printf("\nTotal number of nodes: %d", choice);

	return 0;
}