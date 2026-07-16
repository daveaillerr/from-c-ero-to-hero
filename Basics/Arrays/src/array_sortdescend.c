#include <stdio.h>

int main()
{
	int i, j=0, temp, num_elements;
	int first_[100], second_[100], third_[100]; 
	
	printf("Enter the number of elements to be stored in the first array: ");
	scanf("%d", &num_elements);
	
	// Store elements to array first_
	printf("Enter elements for the first array\n");
	for (i = 0; i < num_elements; i++)
	{
		printf("Enter element - %d: ", i);
		scanf("%d", &first_[i]);
	}
	
	//Store elements to array second_
	printf("Enter elements for the second array\n");
	for (i = 0; i < num_elements; i++)
	{
		printf("Enter element - %d: ", i);
		scanf("%d", &second_[i]);
	}
	
	// Merge both first_ and second_ arrays by assigning it to third_ array
	for (i = 0; i < num_elements; i++)
	{
		third_[j++] = first_[i];
	}
	for (i = 0; i < num_elements; i++)
	{
		third_[j++] = second_[i]; 
	}
	
	// Sorting to descending order by storing to temporary variable and moving the lower integer to right
	for (i = 0; i < num_elements * 2 - 1; i++)
	{
		for (j=0; j < num_elements * 2 - 1; j++)
		{
			if (third_[j] < third_[j+1])
			{
				temp = third_[j];
				third_[j] = third_[j+1];
				third_[j+1] = temp; 
			}	
		}	
	}	
	
	// Displays the result using loop
	printf("The merged array in descending order is: \n");
	for (i=0; i < num_elements * 2; i++)
	printf("%d ", third_[i]);
	
	
    return 0;
}
    