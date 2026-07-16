#include <stdio.h>

int main()
{
	// Variables is used to store the values. This way the final_salary can be calculated by just using variables.
	int number_years, years_sample;
	float user_salary, final_salary;
	
	printf("Greetings! The company would like to give you a bonus! \nPlease follow the instructions below.\n");
	// User is instructed to type the number of years and salary, and scanf was used to get the value.
	printf("Type the number of years in the company: ");
	scanf("%d", &number_years);
	printf("Type your salary here: ");
	scanf("%f",&user_salary);
	
	// Else if ladder is used to make the ranges of years easier to identify and for the switch case to identify what case to use.
	// If a condition is satisfied, year_sample variable will be assigned to a value to satisfy the switch case condition.
	if (number_years >=0 && number_years <=5)
	{
		years_sample = 1;
	}
	else if (number_years >=6 && number_years <=10)
	{
		years_sample = 2;
	}
	else if (number_years >=11 && number_years <=15)
	{
		years_sample = 3;
	}
	else if (number_years >=16 && number_years <=20)
	{
		years_sample = 4;
	}
	else 
	{
		years_sample = 5;
	}
	
	// After the years_sample variable was assigned a value, switch case will search a case that will satisfy the value.
	// Calculations are also made here as well as printing. Percentage is converted to decimal to make calculation easier.
	switch (years_sample)
	{
	case 1:
		final_salary = user_salary * 0.20;
		printf("Your bonus is %.2f Pesos", final_salary);
	break;
	case 2:
		final_salary = user_salary * 0.25;
		printf("Your bonus is %.2f Pesos", final_salary);
	break;
	case 3:
		final_salary = user_salary * 0.30;
		printf("Your bonus is %.2f Pesos", final_salary);
	break;
	case 4:
		final_salary = user_salary * 0.35;
		printf("Your bonus is %.2f Pesos", final_salary);
	break;
	case 5:
		final_salary = user_salary * 0.50;
		printf("Your bonus is %.2f Pesos", final_salary);
	break;	
	default:
		printf("Invalid");
	}
	
	return 0;
}