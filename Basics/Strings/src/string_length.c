#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[100];
	
	printf("Let's calculate the length of your string!\n");
	printf("Enter any string you want!: ");
	fgets(buffer, sizeof(buffer), stdin);
	
	//Use strlen to get length
	printf("======================================================\n");
	printf("Your string is %sIt has a length of %zu!", buffer, strlen(buffer) );	
	
	return 0;
}