#include <stdio.h>
float calculateTotalPrice(float, float , float);

int main(){
	float sub, tax, discount, final;
	
	printf("=====ONLINE SHOPPING SYSTEM=====\n");
	printf("Calculate total price of an order\n");
	printf("Enter subtotal: ");
	scanf("%f", &sub);
	printf("Enter tax rate as percentage: ");
	scanf("%f", &tax);
	printf("Enter discount rate as percentage: ");
	scanf("%f", &discount);
	
	final = calculateTotalPrice(sub, tax, discount);
	printf("The total price of an order is: %.2f", final);
	
	return 0;
}

float calculateTotalPrice(float  a, float b, float c){
	float total, final_tax, final_discount;
	
	final_tax = (b / 100) * a;
	final_discount = (c / 100) * a;
	total = a + final_tax - final_discount;
    
    return total;  
}