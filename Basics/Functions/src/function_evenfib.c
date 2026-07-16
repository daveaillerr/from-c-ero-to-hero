#include <stdio.h>

void fibonacci(void);

int main(){
	
	fibonacci();
	
	return 0;
}

void fibonacci(void)
{
	int i, fibo[100]; 
	fibo[0] = 0;
	fibo[1] = 1;
	
	printf("Even fibonacci series up to 10th term: \n");
	printf("0 ");
	for (i=2; i<=27; i++){
		fibo[i] = fibo[i - 1] + fibo[i-2];
		if (fibo[i] % 2 == 0){
			printf("%d ", fibo[i]);
		}
	}
}