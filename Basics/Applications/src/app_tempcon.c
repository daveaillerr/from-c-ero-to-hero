#include <stdio.h>
float celsius_convert(float);
float farenheit_convert(float);

int main(){
	int c_or_f, cel_con, far_con;
	
	printf("Let's convert your given temperature!");
	printf("\n=====================================");
	printf("\nType 1 to convert to Celsius. \nType 2 to convert to Farenheit. \nEnter: ");
	scanf("%d", &c_or_f);
	
	switch(c_or_f){
		case 1: cel_con = celsius_convert(c_or_f);
		break;
		case 2: far_con = farenheit_convert(c_or_f);
		break;
		default: 
			printf("Invalid Input!");
	}
}

float celsius_convert(float a){
	float user_farenheit, result;
	
	printf("Enter your temperature in Farenheit: ");
	scanf("%f", &user_farenheit);
	
	result = (user_farenheit - 32) * 5/9;
	
	printf("%.2f Fahrenheit is %.2f Celsius", user_farenheit, result);
}

float farenheit_convert(float b){
	float user_celsius, result;
	
	printf("Enter your temperature in Celsius: ");
	scanf("%f", &user_celsius);
	
	result = (user_celsius * 9/5) + 32;
	
	printf("%.2f Celsius is %.2f Fahrenheit", user_celsius, result);
}