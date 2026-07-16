#include <stdio.h>

int main()
{
	// input_text_message as variable to store the value of the number of the user's messages. Scanf is used to get the value.
	int input_text_message;
	printf("Welcome to Send Fail Telecomes! Your number one telecommunication company!\nTo calculate your charge please refer below. \nInput the number of your messages: ");
	scanf("%d",&input_text_message);
	
	// If the message is beyond 200, the condition will calculate the input_text_message - 200 so that the remaining value will be multiplied by 0.5.
	if (input_text_message > 200)
	{
		int sub_zero_charge = input_text_message - 200;
		float final_charge = sub_zero_charge * 0.5;
		printf("You have a charge of %.2f Pesos.", final_charge);
	}
	
	// If input_text_message is equal to 0 or lower than 201, there is no charge will be given.
	else if (input_text_message >= 0)
	{
		float no_charge = input_text_message = 0;
		printf("You have a charge of %.2f Pesos", no_charge);
	}
	// If negative integers are inputted, it is considered invalid input.
	else
	{
		printf("Invalid Input");
	}
	
	return 0;
}

