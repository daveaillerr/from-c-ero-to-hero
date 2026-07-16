#include <stdio.h>

int main()
{
	int i, j, first_[100], num_elements, number_of_dup=0; 
	
	printf("Enter the number of elements to be stored in a array: ");
	scanf("%d", &num_elements);
	
	// Use loop to store all elements to first_ array
	printf("Input %d elements in the array \n", num_elements);
	for (i = 0; i < num_elements; i++)
	{
		printf("Enter element - %d: ", i);
		scanf("%d", &first_[i]);
	}
	
	// Use loop to iterate elements and check for duplicates using first_[i] and first_[j] as reference 
	for (i = 0; i < num_elements; i++)
	{
		for (j=i+1; j < num_elements; j++)
		{
			if (first_[i]==first_[j])
			{
				number_of_dup++;
				break;
			}
		}
	}
	
	// Print and display
	printf("Total number of duplicate elements found in the array is: %d", number_of_dup);
	
	return 0;
}