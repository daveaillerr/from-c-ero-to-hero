#include <stdio.h>
void add(void);
void subtract(void);
void multiply(void);
void divide(void);

int main(){
	int user; 
	
    printf("Choose an operation:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
	
	while (user != 5){
    	printf("\nEnter choice: ");
    	scanf("%d", &user);

    	switch (user){
       	 	case 1:
        		add();  
       	 		break;
       	 		
        	case 2:
            	subtract(); 
            	break;
            	
       	 	case 3:
            	multiply();  
            	break;
            	
        	case 4:
            	divide();  
            	break;
            	
        	case 5:
            	printf("Exit");
            	break;
            	
        	default:
            	printf("Invalid!");
    }
}
	return 0;
}

void add(void){
    int first, second;
    printf("\nEnter first number: ");
    scanf("%d", &first);
    printf("Enter second number: ");
    scanf("%d", &second);
    printf("Result: %d\n", first + second);
}

void subtract(void){
    int first, second;
    printf("\nEnter first number: ");
    scanf("%d", &first);
    printf("Enter second number: ");
    scanf("%d", &second);
    printf("Result: %d\n", first - second);
}

void multiply(void){
    int first, second;
    printf("\nEnter first number: ");
    scanf("%d", &first);
    printf("Enter second number: ");
    scanf("%d", &second);
    printf("Result: %d\n", first * second);
}

void divide(void) {
    float first, second;
    printf("\nEnter first number: ");
    scanf("%f", &first);
    printf("Enter second number: ");
    scanf("%f", &second);
    printf("Result: %.2f\n", first / second);
}