#include <stdio.h>
void sum_nat(void){
	int i, sum = 0, natural[100];
	
	for (i = 0; i <= 100; i++){
		sum += i;
	}
	
	printf("The sum of the first 100 natural numbers: %d", sum);
}

int main(){
	
	sum_nat();
	
	return 0;
}