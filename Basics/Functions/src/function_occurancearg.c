#include <stdio.h>
#include <string.h>

void num_occu(char*, char);

int main(){
	char string[100], user_char;
	
	printf("Let's count the occurances of your chosen character in your string!\n");
	printf("Enter your string: ");
	gets(string);
	
	printf("Enter your chosen character: ");
	user_char = getchar();
	
	num_occu(string, user_char);
}

void num_occu(char a[], char b){
	int length, i, count = 0;
	
	length = strlen(a);
	
	for (i = 0; i < length; i++){
		if (a[i] == b){
			count++;
		}
	}
	printf("\nYour character %c in your string occured %d times.", b, count);
}