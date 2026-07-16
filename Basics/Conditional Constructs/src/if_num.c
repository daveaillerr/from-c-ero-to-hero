#include <stdio.h>

int main()
{
	// Variable is used to store both numOne for the first number and numTwo for second. 
	int numOne, numTwo;
	
	// User is then instructed to input two integers that is used to be compared. Scanf is then use to get the value.
	printf("Let's compare your number! \nPlease input your first number: ");
	scanf("%d", &numOne);
	printf("Now Type Your Second Number: ");
	scanf("%d", &numTwo);
	
	// If statements is used to compare the values of the variable.
	// A simple greater than (>) and less than (<) symbol is used to compare. == when both values are equal
	if (numOne > numTwo)
	{
		printf("Your second number %d is smaller than your first number %d", numTwo, numOne);
	}
	if (numOne < numTwo)
	{
		printf("Your first number %d is smaller than your second number %d", numOne, numTwo);
	}
	if (numOne == numTwo)
	{
		printf("Both of your first and second number are equal");
	}
	return 0;
}
