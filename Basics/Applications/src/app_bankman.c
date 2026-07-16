#include <stdio.h>
void updateAccountBalance(float, float , char);

int main(){
	float current, amount;
	char type;
	
	printf("======BANK ACCOUNT MANAGEMENT======\n");
	printf("Enter your initial balance: ");
	scanf("%f", &current);
	
	printf("\nEnter your transaction type: \n");
	printf("	1. Deposit (Type 'D')\n	2. Withdrawal (Type 'W')\n");
    printf("\nEnter choice: ");
    scanf(" %c", &type);

    while (type != 'D' && type != 'W' && type != 'X') { 
        printf("Invalid. Enter 'D' for Deposit, 'W' for Withdrawal, or 'X' for Exit: ");
        scanf(" %c", &type); 
    if (type == 'D') {
        printf("You selected Deposit.\n");
    } 
	else if (type == 'W') {
        printf("You selected Withdrawal.\n");
    } 
	}
	printf("\nEnter the amount for transaction: ");
	scanf("%f", &amount);
	
	updateAccountBalance(current, amount, type);

	return 0;
}

void updateAccountBalance(float current, float amount, char type){
	float deposit, withdrawal;
	
	
	if (type == 'D') {
        deposit = current + amount;
        printf("\nDeposit Successful. New Balance: %.2f", deposit);
    } 
	else if (type == 'W') {
    	if (current >= amount){
    		withdrawal = current - amount; 
    		current = withdrawal;
    		printf("\nWithdrawal Successful. New Balance: %.2f", current);
		}
		else {
			printf("Transaction failed. Insufficient current balance.");
		}   
    }
	
		
}