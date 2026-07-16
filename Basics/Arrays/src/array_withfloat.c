#include <stdio.h>

int main(){
	float floating_array[100];
	int number_array, i;
	
	printf("Input the number of elements to store in the array: ");
	scanf("%d", &number_array);
	
	for (i = 0; i <= number_array; i++){
		printf("Input %d number of elements in the array: ", i);
		scanf("%f", &floating_array[i]);
	}
	
	printf("\nThe floating-point values stored into the array are: \n");
	for (i = 0; i <= number_array; i++){
		printf("%.1f	", floating_array[i]);
	}
	
	printf("\nThe floating-point values stored into the array in reverse are: \n");
	for (i = number_array; i >= 0; i--){
		printf("%.1f	", floating_array[i]);
	}
	
	return 0;
}