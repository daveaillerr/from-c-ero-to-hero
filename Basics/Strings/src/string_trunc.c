#include <stdio.h>
#include <string.h>

int main(){
	char word[100],_trnc, trnc_copy, result[100];
	int trunc, i;
	
	printf("Enter a String: ");
	gets(word);
	printf("Enter the desired length: ");
	scanf("%d", &trunc);
	
	_trnc = strlen(word);
	result[i] = _trnc - trunc;
	
	printf("%s", result[i]);
	
	
	
	
	return 0;
}