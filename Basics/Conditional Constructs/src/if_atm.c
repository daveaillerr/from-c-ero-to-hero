#include <stdio.h>

int main()
{
	// Variable is used. I added savings_balance to check the balance condition later at savings account.
	int withdrawal_amount, user_select, savings_balance = 10900;
	
	// Printed instructions and used scanf to get the needed inputs.
	printf("Enter account type (1 for Savings, 2 for Current): ");
	scanf("%d", &user_select);
	printf("Enter withdrawal amount: ");
	scanf("%d", &withdrawal_amount);
	
	// If user selects 1 for savings, this condition will be satisfied.
	if (user_select == 1)
	{
		// If withdrawal_amount is greater than 10,000, then it won't allow it for withdrawal.
		if (withdrawal_amount > 10000) 
		{
			printf("Withdrawal Denied: Maximum limit for Savings account is 10,000.");
		}
		// This checks if there is 1000 remains inside the balance.
		else if (savings_balance - withdrawal_amount < 1000)
		{
			printf("Withdrawal Denied: Minimum balance limit is 1000.");
		}
		// Approval is achieved if all of the conditions were satisfied.
		else 
		{
			printf("Withdrawal Approved.");
		}
	}
	// If user selects 2 for current account, this condition will be satisfied.
	else if (user_select == 2)
	{
		// If withdrawal_amount is greater than 25,000, then it won't allow it for withdrawal.
		if (withdrawal_amount > 25000)
		{
			printf("Withdrawal Denied: Maximum limit for Current account is 25,000.");
		}
		// Approval is achieved if all of the conditions were satisfied. This ensures that negative integers aren't allowed.
		else if (withdrawal_amount > 0)
		{
			printf("Withdrawal Approved.");
		}
	}
	
	return 0;
}