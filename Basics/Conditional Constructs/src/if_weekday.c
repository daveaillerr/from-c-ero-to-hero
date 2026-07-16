#include <stdio.h>

int main()
{
	// Variable is used to store the user input value. The days and it's number is displayed for user to have reference.
	int dayInt;
	printf("Let's identify if it's WEEKDAY or WEEKEND! \nPick from number 1 - 7 \nType a number here: ");
	scanf("%d", &dayInt);
	
	// If statement states that if dayInt is 1 to 5, it will display WEEKDAY. Otherwise, it will display WEEKEND.
	if (dayInt <=5 && dayInt > 0)
	{
		printf("WEEKDAY");
	}
	else
	{
		printf("WEEKEND");
	}
	return 0;
}
