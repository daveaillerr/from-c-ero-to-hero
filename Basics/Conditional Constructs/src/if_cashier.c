#include <stdio.h>

int main()
{
	// Used Variables.
	int amount_spent, customer_type; 
	
	// Printed instructions and used scanf to get the needed inputs.
	printf("Enter amount spent: ");
	scanf("%d", &amount_spent);
	printf("Enter customer type (1 for Regular, 2 for Silver, 3 for Gold): ");
	scanf("%d", &customer_type);
	
	// If the user inputted 1 that is for Regular, this condition will be satisfy.
	if (customer_type == 1)
	{
		// If the amount inputted is above 1000, the discount will be identified as well as the final amount.
		if (amount_spent >= 1000)
		{
			float discounted_price = amount_spent * 0.1;
			float final_price = amount_spent - discounted_price;
			printf("Original amount: %d \nDiscount: %.2f \nFinal amount after discount: %.2f", amount_spent, discounted_price, final_price);
		}
		
		// This was added for situations like if user inputs lower than 1000 where discounts doesn't apply.
		else 
		{
			printf("Original amount: %d \nDiscount: 0.00 \nFinal amount after discount: %d", amount_spent, amount_spent);
		}
	}
	
	// If the user inputted 2 that is for Silver, this condition will be satisfy.
	else if (customer_type == 2)
	{
		// If the amount inputted is above 3000, the discount will be identified as well as the final amount.
		if (amount_spent >= 3000)
		{
			float discounted_price = amount_spent * 0.15;
			float final_price = amount_spent - discounted_price;
			printf("Original amount: %d \nDiscount: %.2f \nFinal amount after discount: %.2f", amount_spent, discounted_price, final_price);
		}
		// This was added for situations like if user inputs lower than 3000 where discounts doesn't apply.
		else 
		{
			printf("Original amount: %d \nDiscount: 0.00 \nFinal amount after discount: %d", amount_spent, amount_spent);
		}
	}
		// If the user inputted 3 that is for Gold, this condition will be satisfy.
	else if (customer_type == 3)
	{
		// If the amount inputted is above 5000, the discount will be identified as well as the final amount.
		if (amount_spent >= 5000)
		{
			float discounted_price = amount_spent * 0.2;
			float final_price = amount_spent - discounted_price;
			printf("Original amount: %d \nDiscount: %.2f \nFinal amount after discount: %.2f", amount_spent, discounted_price, final_price);
		}
		// This was added for situations like if user inputs lower than 5000 where discounts doesn't apply.
		else 
		{
			printf("Original amount: %d \nDiscount: 0.00 \nFinal amount after discount: %d", amount_spent, amount_spent);
		}
	}
	// Displays if user inputs anything besides the given information.
	else
	{
		printf("Invalid Input");
	}
	
	return 0;
}


