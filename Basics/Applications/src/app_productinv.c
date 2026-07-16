#include <stdio.h>

int main(){
	int max_prod, user_choice, i, first_choice;
	
	printf("Enter the maximum number of products in the inventory: ");
	scanf("%d", &max_prod);
	
	for (i = 0; i < 4; i++){
	
	printf(" Menu: \n\t1. Add a new product \n\t2. Update product quantity \n\t3. Display inventory \n\t4. Exit\n");
	
	printf("\nEnter your choice: ");
	scanf("%d", &user_choice);
	
	if (user_choice == 1){
		printf("Enter the name of the product: ");
		scanf("%d", &first_choice);
	}
	
	}
}