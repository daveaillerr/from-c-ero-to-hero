#include <stdio.h>

void even_numbers(void);

int main(){
	
	printf("Let's print the first 10 even numbers!\n");
	even_numbers();
	
	return 0;
}

void even_numbers(void){
	int i;
	
	for (i=0; i <20; i++){
		if (i % 2 == 0){
			printf("%d ", i);
		}
	}
}
