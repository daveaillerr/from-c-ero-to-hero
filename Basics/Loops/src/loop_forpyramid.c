#include <stdio.h>

int main()
{
	//Variables
	int user_enter_row, row_variable, space_variable;
	
	//Used scanf to get user input.
	printf("Input number of levels of the pyramid: ");
	scanf("%d", &user_enter_row);
	
	//First for loop is for the rows.
	for (row_variable = 1; row_variable <= user_enter_row; row_variable++ )
	{
		//Second loop is for the spaces before the *.
		for (space_variable = 1; space_variable <= user_enter_row - row_variable; space_variable++)
		{
			printf(" ");
		}
		//Third loop is for printing the *.
	    for (space_variable = 1; space_variable <= (2 * row_variable - 1); space_variable++)
       	{
	      	printf("*");
    	}
    //Used to print new line.
	printf("\n");
	}
	
	//It is print everytime the pyramid is complete.
    printf("Level %d completed! The King nods in approval.", user_enter_row);
	
	//Evaluates the levels of the pyramid. If it's above 10 the King will be impressed.
	if (user_enter_row >= 10)
	{
	    printf("\nThe King is impressed by your ambition!");
	}
	//Evaluates the levels of the pyramid. If it's 3 below, the King will be disappointed.
	else if (user_enter_row <= 3)
	{	
    	printf("\nThe King sighs. Too small for my glory!");
    }	       
    //Evaluates the levels of the pyramid. If it's between 4-9, the King will encourage you to make it higher.
    else 
    {
    	printf("\nThe King encourages you to make it higher!");
	}
	return 0;
}