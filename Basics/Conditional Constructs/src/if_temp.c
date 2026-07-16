#include <stdio.h>

int main()
{
	// Variables is used.
	int temperature_celsius;
	char user_response;
	
	// Printed instructions and used scanf to get the needed inputs.
	printf("Enter temperature in Celsius: ");
	scanf("%d", &temperature_celsius);	
	printf("Is it raining? (y/n): ");
	scanf(" %c", &user_response);
	
	// If inputed temperature is below 10c, this condition will be satified.
	if (temperature_celsius < 10)
	{
		// This condition will be satisfied regardless of what the user answered.
		if (user_response == 'n','y')
		{
			printf("Wear a heavy coat and bring an umbrella.");
		}
		// This prevents other input besides n and y for yes or no question.
		else 
		{
			printf("Invalid Syntax");
		}
	}
	// This will be satisfied if temperature inputted is between 10 and 20.
	else if (temperature_celsius >=10 && temperature_celsius <=20)
	{
		// If user responded y, a specific message will be printed.
		if (user_response == 'y')
		{
			printf("Wear a sweater and bring an umbrella.");
		}
		// On the other hand if user responded n, a specific message will be printed as well.
		else if (user_response == 'n')
		{
			printf("Wear a sweater.");
		}
		// It again prevents other answers.
		else 
		{
			printf("Invalid Syntax");
		}
	}
	// Above 20c will satisfy this condition.
	else
	{
		// If user responded y, a specific message will be printed.
			if (user_response == 'y')
		{
			printf("Wear light clothes and bring an umbrella.");
		}
		// If user responded n, a specific message will be printed.
		else if (user_response == 'n')
		{
			printf("Wear light clothes");
		}
		// Prevents other answers.
		else 
		{
			printf("Invalid Syntax");
		}
	}
	return 0;
}