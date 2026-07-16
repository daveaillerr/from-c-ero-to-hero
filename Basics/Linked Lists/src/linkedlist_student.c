#include <stdio.h>
#include <string.h>

int main(){
	
	struct record{
		char name[50];
		int score;
		struct record *next;
	};
	
	struct record stud1, stud2, stud3, *current, *top;
	strcpy(stud1.name, "John Doe");
	strcpy(stud2.name, "Mark John");
	strcpy(stud3.name, "William Billy");
	
	stud1.score = 87;
	stud2.score = 98;
	stud3.score = 89;
	
	stud1.next = &stud2;
	stud2.next = &stud3;
	stud3.next = NULL;
	
	current = &stud1;
	top = current;
	
	while (current != NULL) {
        if (current->score > top->score) {
            top = current;
        }
        current = current->next;
    }
	
	printf("Class record:\n");
    printf("Name: %s\n", stud1.name);
    printf("Score: %d\n", stud1.score);
    
    printf("Name: %s\n", stud2.name);
    printf("Score: %d\n", stud2.score);
    
    printf("Name: %s\n", stud3.name);
    printf("Score: %d\n", stud3.score);
	
    printf("\nHighest score in class:\n");
    printf("Name: %s\n", top->name);
    printf("Score: %d\n", top->score);
	

	return 0;
}