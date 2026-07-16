#include <stdio.h>

int main(){
	int i, n[100], size, *nm[100];
	
	printf("Input the number of elements to store in the array: ");
	scanf("%d", &size);
	
	printf("Input %d number of elements in the array: \n", size);
	
	for (i = 0; i < size; i++){
		printf("elements - %d: ", i);
		scanf("%d", &n[i]);
		nm[i] = &n[i];
	}
	
	printf("\nThe elements you entered are:\n");
	for (i = 0; i < size; i++){
		printf("element - %d: %d\n", i, *nm[i]);
	}
	
	return 0;
}
