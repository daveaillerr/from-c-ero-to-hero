#include <stdio.h>

int main(){
	int i, j, n[100], size, *temp, *nm[100];
	
	printf("Input the number of elements to store in the array: ");
	scanf("%d", &size);
	
	printf("Input %d number of elements in the array: \n", size);
	
	for (i = 0; i < size; i++){
		printf("elements - %d: ", i);
		scanf("%d", &n[i]);
		nm[i] = &n[i];
	}

	for (i = 0; i < size - 1; i++){
		for (j = 0; j < size - 1; j++){
			if (*nm[j] > *nm[j+1]){
				temp = nm[j];
				nm[j] = nm[j+1];
				nm[j+1] = temp;
			}
		}
	}
	
	printf("\nThe elements you entered are:\n");
	for (i = 0; i < size; i++){
		printf("element - %d: %d\n", i, *nm[i]);
	}
	return 0;
}
