#include <stdio.h>

void fibonacci(void);

int main(){
	
	fibonacci();
	
	return 0;
}

void fibonacci(void)
{
	int i, fibo[11]; 
	
	printf("Fibonacci series up to 10th term: \n");
	printf("0 ");
	for (i=2; i<=10; i++){
		fibo[i] = fibo[i - 1] + fibo[i-2];
		printf("%d ", fibo[i]);
	}
}