#include <stdio.h>

int main() {
    FILE *filetest;
    char filename[100];
    char contents;
    int char_count = 0, word_count = 0, inside = 0;

    printf("Input the file name to be opened: ");
    gets(filename);

   	filetest = fopen(filename, "r");
		
	if(filetest == NULL){
		printf("No file exist.");
	}
	
	else{
    printf("The content of the file %s are:\n", filename);

    while ((contents = fgetc(filetest)) != EOF) {
        putchar(contents); 
        
        if(contents != ' ' && contents != '\n' && contents != '\t'){
        char_count++;
		}
		
		
        if (contents == ' ' || contents == '\n' || contents == '\t'){
            if (inside) {
                word_count++;
                inside = 0;
            }
        } 
		else {
            inside = 1;
        }
    }

    if (inside){
        word_count++;
    }

    fclose(filetest);

    printf("\nThe number of words in the file %s are: %d", filename, word_count);
    printf("\nThe number of characters in the file %s are: %d\n", filename, char_count);
	}
	
    return 0;
}