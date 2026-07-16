#include <stdio.h>

int main(){
	
	FILE *filetest;
	char filename[100];
	char sentence[100];
	
	printf("Input the file name to be opened: ");
	gets(filename);
	
	filetest = fopen(filename, "r");
	
	if(filetest == NULL){
		printf("No file exist.");
	}
	else{
	printf("The content of the %s is: \n\n", filename);
	while(!feof(filetest)){
		fgets(sentence, 100, filetest);
		printf("%s",sentence);
	}
	printf("\n\nThis is the content of the %s.", filename);
	}
	
	fclose(filetest);

	return 0;
}