#include <stdio.h>

int main() {
    FILE *filetest, *temp;
    char filename[100];
    char contents[100];
    char newline[100];
    int line_num, current_line = 1;

    printf("Input the file name to be opened: ");
    gets(filename);

    filetest = fopen(filename, "r");
    if(filetest == NULL) {
        printf("No file exists.");
    }

	else{
		temp = fopen("temp.txt", "w");

    	printf("Input the content of the new line: ");
   		gets(newline);

    	printf("Input the line number you want to replace: ");
    	scanf("%d", &line_num);
    	getchar(); 

    	while (fgets(contents, 100, filetest) != NULL) {
    	    if (current_line == line_num) {
    	        fprintf(temp, "%s\n", newline); 
    	    } else {
    	        fputs(contents, temp); 
    	    }
        	current_line++;
    	}

    	fclose(filetest);
    	fclose(temp);

    	filetest = fopen(filename, "w");
    	temp = fopen("temp.txt", "r");

    	while (fgets(contents, 100 , temp) != NULL) {
    	    fputs(contents, filetest);
   		}

    	fclose(filetest);
    	fclose(temp);

    	remove("temp.txt");

    	printf("Replacement did successfully...!!\n");
    	
    	filetest = fopen(filename, "r");
    	
    	while (fgets(contents, 100 , filetest) != NULL) {
    	    printf("%s", contents);
   		}
   		
   		fclose(filetest);
    	
	}

    return 0;
}