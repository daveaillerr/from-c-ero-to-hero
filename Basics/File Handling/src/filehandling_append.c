#include <stdio.h>

int main() {
    FILE *filetest;
    char filename[100], newline[100];
    char contents[100];
	int lines_write, i;

    printf("Input the file name to be opened: ");
    gets(filename);
	
   	filetest = fopen(filename, "a+");
		
	if(filetest == NULL){
		printf("No file exist.");
	}
	
	else{
		printf("Input the number of lines to be written: ");
    	scanf("%d", &lines_write);
    	getchar();
    		
    		printf("The lines are:\n");
    			for (i = 0; i < lines_write; i++){
    				gets(newline);
    				fputc('\n', filetest);
    				fputs(newline, filetest);
				}
				
			rewind(filetest);
   			printf("The content of the file %s are:\n", filename);
				while (fgets(contents, 100, filetest) != NULL){
					fputs(contents, stdout);	
				}
    
			fclose(filetest);
		}
    
    return 0;
}