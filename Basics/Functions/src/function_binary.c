#include <stdio.h>
int binary_convert(int, int);

int main(){
	int user_decimal, Final_conversion;
	
	printf("Input any decimal number: ");
	scanf("%d", &user_decimal);
	
	printf("The Binary value is: ");
	
	binary_convert(user_decimal, Final_conversion);
	
}

int binary_convert(int a, int b){
	int temp[100], i, count=0;
	
	while (a > 0){
		temp[i]= a % 2;
		a = a/2; 
		count++;
		i++;
	}	
	
	for (i = count - 1; i >= 0; i--){
		b = temp[i];
		printf("%d", b);
	}
	
}
	