#include <stdio.h>
int largest(int);

int main(){
	int number_elements, result;
	
	printf("Input the number of elements to be stored in the array: ");
	scanf("%d", &number_elements);

	printf("Input %d elements in the array:\n", number_elements);

	result = largest(number_elements);
	
}
int largest(int x){
	int i, j, user_array[100], temp;
	
	for(i=0; i<x; i++){
		printf("Element - %d: ", i);
		scanf("%d", &user_array[i]);
	}
	
	for (i = 0; i < x - 1; i++)
	{
		for (j=0; j < x - 1; j++)
		{
			if (user_array[j] < user_array[j+1])
			{
				temp = user_array[j];
				user_array[j] = user_array[j+1];
				user_array[j+1] = temp; 
			}	
		}	
	}
	
	printf("The largest element in the array is: %d", user_array[0]);
		
}