#include <stdio.h>

int main(){
	int array[] = {3, 8, 20, 24, 6};
	int *var_arr; 
	
	var_arr = &array[0];
	
	printf("~~~ Pointer Arithmetic ~~~	\n");
	printf("The third element of the array: %d\n", var_arr[2]);
	printf("The position where the pointer was incremented by 2: %d\n", var_arr[4]);
	printf("The value of the pointer was subtracted by 1: %d\n", var_arr[4] - 1);
	printf("The first element of the array: %d\n", var_arr[0]); 
	
	
	return 0;
}