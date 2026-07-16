#include <stdio.h>
#include <string.h>

int main(){
	struct storage{ 
	char brand[50];
	char model[50];
	int year;
	float price;
	}car_info;
	
	printf("Enter the brand of the car: ");
	gets(car_info.brand);
	printf("Enter the model of the car: ");
	gets(car_info.model);
	printf("Enter the year of the car: ");
	scanf("%d", &car_info.year);
	printf("Enter the price of the car: ");
	scanf("%f", &car_info.price);
	
	printf("--------------------------------\n");
	printf("Car Information:\n	Brand Name: %s\n	Car Model: %s\n	Car Year: %d\n	Car Price: %.2f", car_info.brand, car_info.model, car_info.year, car_info.price);
	
	return 0;
}