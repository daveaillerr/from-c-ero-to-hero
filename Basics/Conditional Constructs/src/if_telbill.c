#include <stdio.h>

int main()
{
	// Variables is used to store the values.
	int day_made, hour_start, call_duration;
	
	printf("Welcome to Telepono ng Pilipino's Computing Telephone Bill! \nPlease Follow The Instructions Bellow. \n");
	
	// User is then instructed to type the integer that represents the day the user made the call, integer of time started, and duration. Scanf was used to get the value.
	printf("Please refer to this:\n1 - Monday \n2 - Tuesday \n3 - Wednesday \n4 - Thursday \n5 - Friday \n6 - Saturday \n7 - Sunday \nType the integer that represents the day that you made your call: ");
	scanf("%d", &day_made);
	printf("Type the integer of the time you started the call (using the 24-hour format): ");
	scanf("%d", &hour_start);
	printf("Type the duration of your call in minutes: ");
	scanf("%d", &call_duration);
	
	// Nested if else is used to identify the needed conditions. The use of range was used to make it easier.
	// To satisfy this, day_made should be in the range of 1 to 5 (Monday - Friday or Weekday)
	if (day_made <= 5 && day_made > 0) 
	{
		// After satisfying the 1 to 5 range of day, another if else statement is used to identify what time of the weekday was the call made. 
		// If 6 to 18 (6am to 6pm in 12-hour format) range is satisfied, fee_minute variable is assigned to a calculation that corresponds to the charge fee needed. Output is also printed.
		if (hour_start >= 6 && hour_start <= 18)
		{
			float fee_minute = call_duration * 2.50;
			printf("Your fee is %.2f Pesos", fee_minute);
		}
		
		// For the remaining time of the day, another condition should be met. A range of 1 to 5 and 19 to 24 hours (1am to 5am and 7pm to 12am in 12-hour format) must be satisfied.
		// Again if this condition is satisfied fee_minute variable is assigned to a calculation that corresponds to the charge fee needed. Output is also printed.
		else if ((hour_start >=0 && hour_start <=5) || (hour_start >=19 && hour_start <=23))
		{
			float fee_minute = call_duration * 2.00;
			printf("Your fee is %.2f Pesos", fee_minute);
		}
		
		// Below and beyond 24 is considered invalid.
		else
		{
			printf("Invalid Time Input");
		}
	}
	
	// For Saturday and Sunday, a range was used. 
	else if (day_made >=6 && day_made <=7)
	{
		// Another range for 1 to 24 (1am to 12am in 12-hour format) is used. 
		// Once again if this condition is satisfied fee_minute variable is assigned to a calculation that corresponds to the charge fee needed. Output is also printed.
		if (hour_start >= 0 && hour_start <=23 )
		{	
		float fee_minute = call_duration * 1.50;
		printf("Your fee is %.2f Pesos", fee_minute);
		}   
		
		// Again, below and beyond 24 is considered invalid.
		else
		{
			printf("Invalid Time Input");
		}
	}
	// It is used if it exceeds the seven days a week system.
	else 
	{
		printf("Invalid Day Input");
	}
	return 0;
}