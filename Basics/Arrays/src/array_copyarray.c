#include <stdio.h>

int main()
{
	int i, first_[100], second_[100], num_elements ; 
	
	printf("Enter the number of elements to be stored in a array: ");
	scanf("%d", &num_elements);
	
	// Iterates and store value to first_ array
	for (i = 0; i < num_elements; i++)
	{
		printf("Enter element - %d: ", i);
		scanf("%d", &first_[i]);
	}
	
	// Iterates and print value of first_ array
	printf("The elements stored in the first array are: \n");
	for (i = 0; i < num_elements; i++)
	{
		printf("%d ", first_[i]);
	}	
	
	// Use loop to iterate value of first_ array and copy it to second_ array
	for (i=0; i<num_elements; i++)
	{
		second_[i] = first_[i];
	}
	
	// Use loop to print all elements
	printf("\nThe elements copied into the second array are: \n");
	for (i = 0; i < num_elements; i++)
	{
		printf("%d ", second_[i]);
	}	
	
	return 0;
}