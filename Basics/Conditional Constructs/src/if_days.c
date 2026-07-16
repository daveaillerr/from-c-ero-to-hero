#include <stdio.h>

int main()
{
	// day_week to store user input value that will be evaluated by else-if ladder later.
	int day_week;
	printf("Let's identify what day your number is! \nInput a day in numeric form: ");
	scanf("%d", &day_week);
	
	// Else-if ladder is used. Each day is evaluated individually to print different days. 
	if (day_week == 1)
	{
		printf("That day is Monday!");
	}
	else if (day_week == 2)
	{
		printf("That day is Tuesday!");
	}
	else if (day_week == 3)
	{
		printf("That day is Wednesday!");
	}
	else if (day_week == 4)
	{
		printf("That day is Thursday!");
	}
	else if (day_week == 5)
	{
		printf("That day is Friday!");
	}
	else if (day_week == 6)
	{
		printf("That day is Saturday!");
	}
	else if (day_week == 7)
	{
		printf("That day is Sunday!");
	}
	// Bellow or beyond of the intended range will display invalid input.
	else 
	{
		printf("Invalid input");
	}
	
	// It is displayed after the else-if ladder displayed the intended message.
	printf("\nHave a nice day!");
	
	return 0;
}
