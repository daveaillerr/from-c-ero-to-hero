#include <stdio.h>
int add(void){
	int n1, n2;
    printf("First number: ");
    scanf("%d", &n1);
    printf("Second number: ");
    scanf("%d", &n2);
    printf("The result of %d and %d: %d\n", n1, n2, n1 + n2);
}

int subtract(void){
	int n1, n2;
    printf("First number: ");
    scanf("%d", &n1);
    printf("Second number: ");
    scanf("%d", &n2);
    printf("The result of %d and %d: %d\n", n1, n2, n1 - n2);
}

int multiply(void){
	int n1, n2;
    printf("First number: ");
    scanf("%d", &n1);
    printf("Second number: ");
    scanf("%d", &n2);
    printf("The result of %d and %d: %d\n", n1, n2, n1 * n2);
}
int divide(void){
	float n1, n2;
    printf("First number: ");
    scanf("%f", &n1);
    printf("Second number: ");
    scanf("%f", &n2);
    printf("The result of %.2f and %.2f: %.2f\n", n1, n2, n1 / n2);
}

int main(){
	int input, *tem, i; 
	
    printf("Let's calculate your number!\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Exit\n");
	
   		printf("Enter the operation: ");
   		 scanf("%d", &input);
		tem = &input;

    	switch (*tem){
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
       	 	   	printf("Exiting Program...");
        	   	break;
           	
        	default:
         	  	printf("Invalid Input!\n");
   	 	}
   	 	
	return 0;
}
