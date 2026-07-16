#include <stdio.h>

int main()
{
	int enter_num[11], print_sum[10], i;
		
		printf("Enter eleven numbers: ");
		// Iterates elements and store to enter_num
		for (i = 0; i < 11 ; i++)
		{
			scanf("%d", &enter_num[i]);
		}
		// Iterates elements and store print_sum assigned to add pairs 
		for (i = 0; i < 10 ; i++)
		{
			print_sum[i] = enter_num[i] + enter_num[i+1];
		}
		// Use loop to iterate element and print it
		printf("Sum of two succeeding pairs: ");
		for (i = 0; i < 10; i++)
		{
			printf("%d ", print_sum[i]);
		}
		
	return 0;
}