#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[100], buffer_copy[100];
	
	printf("Let me copy the string you just entered!\n");
	printf("Enter any string you want: ");
	fgets(buffer,sizeof(buffer), stdin);
	
	//Use strcpy to copy string to another
	strcpy(buffer_copy, buffer);
	
	printf("======================================================\n");
	printf("You entered: %s", buffer);
	printf("Copy of string you just entered: %s", buffer_copy);
	
	return 0;
}