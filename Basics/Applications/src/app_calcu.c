#include <stdio.h>
float addition(float, float);
float subtraction(float, float);
float multiplication(float, float);
float division(float, float);

int main(){
	float operand_1, operand_2, sum, difference, product, quotient;
	char operation;
	
	printf("Welcome to the Simple Calculator!\n");
	printf("Enter your first operand: ");
	scanf("%f", &operand_1);
	printf("Enter your second operand: ");
	scanf("%f", &operand_2);
	
	printf("Enter your operation (+, -, *, /): ");
	scanf(" %c", &operation);
	
	if (operation == '+'){
		sum = addition(operand_1, operand_2);
	}
	else if (operation == '-'){
		difference = subtraction(operand_1, operand_2);
	}
	else if (operation == '*'){
		product = multiplication(operand_1, operand_2);
	}
	else if (operation == '/'){
		quotient = division(operand_1, operand_2);
	}
	else {
		printf("Invalid Input!");
	}
}

float addition(float a, float b){
	float sum;
	sum = a + b;
	printf("Result: %.2f", sum);
}
float subtraction(float a, float b){
	float diff;
	diff = a - b;
	printf("Result: %.2f", diff);
}
float multiplication(float a, float b){
	float prod;
	prod = a * b;
	printf("Result: %.2f", prod);
}
float division(float a, float b){
	float quot;
	quot = a / b;
	printf("Result: %.2f", quot);
}