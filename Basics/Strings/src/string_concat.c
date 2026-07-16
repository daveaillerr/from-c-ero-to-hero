#include <stdio.h>
#include <string.h>

int main()
{
	char fbuffer[100], sbuffer[100], string_length1;

	printf("Let's combine the string you just entered!\n");
	
	//Used to get the values of the strings
	printf("Enter your first string: ");
	fgets(fbuffer, sizeof(fbuffer), stdin);
	
	printf("Enter your second string: ");
	fgets(sbuffer, sizeof(sbuffer), stdin);
	
	
	string_length1 = strlen(fbuffer);
	
	//Removes unwanted new line by replacing newline with null terminator
    if (string_length1 > 0 && fbuffer[string_length1 - 1] == '\n') 
	{
        fbuffer[string_length1 - 1] = '\0';  
    }
    
    //Ensures that the concatenated line has space after first string by replacing null with space
    if (string_length1 > 0 && fbuffer[string_length1 - 1] == '\0') 
	{
        fbuffer[string_length1 - 1] = ' ';  
    }
    
    //Concatenates the first and second string
    strcat(fbuffer,sbuffer);
	
	//Display
	printf("This is the combination of your strings: ");
	printf("%s", fbuffer);
	
	return 0;
}