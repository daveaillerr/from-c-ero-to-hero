#include <stdio.h>
#include <string.h>

int main()
{
	char fbuffer[100], sbuffer[100];
	int answer_;
	
	printf("Let's compare the string you just entered!\n");
	//Get values
	printf("Enter your first string: ");
	fgets(fbuffer, sizeof(fbuffer), stdin);
	
	printf("Enter your second string: ");
	fgets(sbuffer, sizeof(sbuffer), stdin);
	
	//Assign the value of the compared strings
	answer_ = strcmp(fbuffer, sbuffer);
	
	//Used if-else statement to print result of the comparison
	if (answer_ == 0)
	{
		printf("Your first string is equal to your second string!");
	}
	else 
	{
		printf("Your first string is not equal to your second string!");
	}
	
	
	return 0;
}