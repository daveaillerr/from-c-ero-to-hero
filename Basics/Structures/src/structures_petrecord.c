#include <stdio.h>

int main(){
	struct record{ 
		char name[50];
		char type[50];
		int age;
	}pet;
	
	printf("Pet Recording System: \n");
	printf("Enter the name of your pet: ");
	gets(pet.name);
	printf("Enter the type of your pet (dog, cat, etc.): ");
	gets(pet.type);
	printf("Enter the age of your pet: ");
	scanf("%d", &pet.age);
	
	printf("Pet Report: \n");
	printf("	Pet name: %s\n", pet.name);
	printf("	Pet type: %s\n", pet.type);
	printf("	Pet age: %d\n", pet.age);
	
	return 0;
}