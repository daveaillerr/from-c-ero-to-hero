#include <stdio.h>

int main(){
	struct grocery_record{
		char item_name[50];
		int quantity;
		float price;
	}item;
	
	printf("Enter the item name: ");
	gets(item.item_name);
	printf("Enter the quantity of the item: ");
	scanf("%d", &item.quantity);
	printf("Enter the price of the item: ");
	scanf("%f", &item.price);
	
	printf("\nGrocery Item Record:");
	printf("\n     Item Name: %s", item.item_name);
	printf("\n     Item Quantity: %d", item.quantity);
	printf("\n     Item Price Per Piece: %.2f", item.price);
	printf("\n     Item Total Cost: %.2f", item.quantity * item.price);
	
	
	return 0;
}