#include <stdio.h>
int power(int base, int exponent){
	if (exponent == 0){
		return 1;
	}
	else{
		return base * power(base, exponent -1);
	}
} 

int main(){
	int base, exponent, main;
	
	printf("Let's calculate the power of your number!\n");
	printf("Enter your base number: ");
	scanf("%d", &base);
	printf("Enter the exponent of your number: ");
	scanf("%d", &exponent);
	
	main = power(base, exponent);
	
	printf("The power of your number is %d", main);
	
	return 0; 
}