#include <stdio.h>

int main()
{

	FILE *filetest;
	char sentence[100];

	filetest = fopen("file test.txt", "w");

	printf("Input a sentence for the file: ");
	gets(sentence);

	fprintf(filetest, "%s", sentence);
	printf("The file test.txt was created successfully...!!");

	fclose(filetest);

	return 0;
}