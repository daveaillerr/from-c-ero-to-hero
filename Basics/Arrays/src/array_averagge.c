#include <stdio.h>
void average(int*, int);

int main(){
	int i, size, elements[100], final;
	
	printf("Let's calculate the average of your array!\n");
	printf("Enter the size of your array: ");
	scanf("%d", &size);
	
	for (i=0; i<size; i++){
		printf("Enter elements for your array: ");
		scanf("%d", &elements[i]);
	}
	
	average(elements, size);

	return 0;
}

void average(int array[], int size){
	int sum,i, final;
	
	for (i = 0; i < size; i++){
		sum += array[i];
	}
	final = sum / size;
	printf("The average of the elements is %d", final);
	
}