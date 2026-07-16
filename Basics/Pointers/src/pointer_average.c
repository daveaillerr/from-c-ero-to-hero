#include <stdio.h>

int main(){
	int array[10], *arr_point[10], i, average = 0;
	
	printf("Enter 10 integer to store in the array: \n");
	
	for (i = 0; i < 10; i++){
		printf("Enter %d - ", i);
		scanf("%d", &array[i]);
		arr_point[i] = &array[i]; 
		average += *arr_point[i];
	}
	
	printf("The average of the your 10 integer is: %d", average/10);
	
	
	
	return 0; 
}