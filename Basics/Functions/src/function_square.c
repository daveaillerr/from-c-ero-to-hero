#include <stdio.h>
float square(float);

int main(){
	float user_input, result;	
	
	printf("Input any number for square: ");
	scanf("%f", &user_input);
	
	result = square(user_input);
	
	printf("The square of %.f is %.2f", user_input, result);
}

float square(float a){
	return(a * a);
}