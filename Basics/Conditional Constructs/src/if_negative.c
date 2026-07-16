#include <stdio.h>

int main()
{
	// Variable to store the double float.
	double numVariable;
	
	// Allows user to input number
	printf("Let's Identify if your number is POSITIVE or NEGATIVE! \nPlease input any number: "); 
	scanf("%lf", &numVariable);
	
	// If the input number is higher than zero, the output would be POSITIVE.
	if (numVariable > 0)
	{
		printf("POSITIVE");
	}
	// If the input number is lower than zero, the output would be NEGATIVE.
	if (numVariable < 0)
	{
		printf("NEGATIVE");
	}
	// If the input number is zero, the output would be ZERO.
	if (numVariable == 0)
	{
		printf("ZERO");
	}
	
return 0;
}
