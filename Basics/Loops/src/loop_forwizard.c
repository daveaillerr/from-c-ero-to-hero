#include <stdio.h>

int main()
{
	// Variables.
	int first_num_mult, second_num_mult, product_value;
	
	//Used scanf to get user input.
	printf("Wizard! By the ancient runes and forgotten realms, I demand thee to input thy sacred magic number!: ");
	scanf("%d", &first_num_mult);
	
	//If-else statement to identify the needed condition which is 0.
	if (first_num_mult == 0)
	{
	printf("Wizard! Beware! For the villainous Mr. 0 has summoned forth a magic storm! Quick, retreat to the shadows and hide, lest the tempest consume us!");
	}
	//If zero is not the inputted value, this part will work.
	else 
	{	
	//Used for loop for another variable that holds the needed list of numbers from 1-10.
		for (second_num_mult=1; second_num_mult <=10; second_num_mult++)
		{
		//Product_value variable is used to store the equation for multiplication.
		product_value = first_num_mult * second_num_mult;
		//It is then printed out.
		printf("\u2728%d x %d = %d\n", first_num_mult, second_num_mult, product_value);
		//Thought ASCII code for sparkle emoji would work but it does'nt. It does work on programmiz though.
		}
		
	}
	return 0;
}