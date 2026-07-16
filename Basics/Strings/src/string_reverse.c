#include <stdio.h>
#include <string.h>

int main()
{
	char buffer[100], temp[100];
	int  i, size;
	
	printf("Let's reverse the string you just entered!\n");
	printf("Enter any string you want: ");
	fgets(buffer,sizeof(buffer), stdin);
	
	size = strlen(buffer);

	//Reverses string and assigns to new array of strings starting from last element
	for (i = size - 1; i >= 0; i--)
	{
		temp[size-i-1] = buffer[i];
	}
	
	//Removes newline on last line to prevent from having new line 
	if (temp[0] == '\n') 
	{
        temp[0] = '\0';  
    }
	
	//Display reversed string
	printf("Reversed string: ");
	//Used loop to display all elements
	for (i=0; i < size; i++)
	{
	printf("%c", temp[i]);
	}

	return 0;
}