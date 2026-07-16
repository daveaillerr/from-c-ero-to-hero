#include <stdio.h>
int swapPointers(int **ptrA, int **ptrB){
	int *temp;
	
	temp = *ptrA;
	*ptrA = *ptrB; 
	*ptrB = temp;
	
}


int main(){
	
	int first_var, second_var, *ptrA, *ptrB;
	
	printf("Enter first value: ");
	scanf("%d", &first_var);
	printf("Enter second value: ");
	scanf("%d", &second_var);
		
	
	ptrA = &first_var;
	ptrB = &second_var;
	
	
	printf("Here's the initial value of ptrA and ptrB: \n");
	printf("ptrA: %d\nptrB: %d", *ptrA, *ptrB);
	
	swapPointers(&ptrA, &ptrB);
	
	printf("\nHere's the modified value of ptrA and ptrB: \n");
	printf("ptrA: %d \nptrB: %d", *ptrA, *ptrB);
	
	return 0;
}