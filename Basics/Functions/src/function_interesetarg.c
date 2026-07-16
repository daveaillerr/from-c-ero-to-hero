#include <stdio.h>
float simple_interest(float, float, float);

int main(){
	float principal, rate_int, time_per, simple;
	
	printf("Let's Calculate your simple interest!\n");
	printf("Enter you principal: ");
	scanf("%f", &principal);
	printf("Enter you rate of interest: ");
	scanf("%f", &rate_int);
	printf("Enter you rate of interest: ");
	scanf("%f", &time_per);
	
	simple = simple_interest(principal, rate_int, time_per);
	
	printf("%.2f", simple);
	
	return 0;
}

float simple_interest(float principal, float rate_int, float time_per){
	
	return principal * rate_int * time_per;
	
}