#include <stdio.h>
void multiplyByTwo(int* array){
	int i;

	for (i = 0; i < 5; i++){
		array[i] *= 2; 
	}
	
}

 	
int main(){
	int array[] = {3, 8, 20, 24, 6}, i;
	
	printf("Initial Values: \n");
	for (i = 0; i < 5; i++){
		printf("%d	", array[i]);
	}
	
	multiplyByTwo(array);
		
	printf("\nModified Values: \n");
	for (i = 0; i < 5; i++){
		printf("%d	", array[i]);
	}
	
	return 0;
}