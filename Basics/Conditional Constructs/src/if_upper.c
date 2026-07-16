#include <stdio.h>

int main()
{
	// Char variable is used to store the value that the user will input. 
	char letter_input;
	
	// This allows user to input value or letter
	printf("Let's identify if a letter is in lowercase or uppercase \nInput a letter: ");
	scanf("%c", &letter_input);
	
	// If else is used. isupper is used to check if the letter is uppercase. If the letter is in uppercase, it will display UPPERCASE. Otherwise, it will display LOWERCASE.
	if (isupper(letter_input))
	{
		printf("UPPERCASE");
	}
	else
	{
		printf("LOWERCASE");
	}
	return 0;
}
