#include <stdio.h>
int sum(int,int);

int main(){
	int first_int, second_int, sum_1;
	
	printf("Let's add your integers and multiply them by 2!\n");
	printf("Enter your first number: ");
	scanf("%d", &first_int);
	
	printf("Enter your second number: ");
	scanf("%d", &second_int);
	
	sum_1 = sum(first_int, second_int);
	
	printf("The total is: %d", sum_1);
	
	return 0;
}

int sum(int a, int b){
	int result;
	result = (a + b) * 2;
}
