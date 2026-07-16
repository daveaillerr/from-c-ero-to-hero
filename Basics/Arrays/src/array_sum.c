#include <stdio.h>

int main(){
	
	int Numbers[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, sum, i;
	
	for (i=0; i <= 9; i++){
		if (Numbers[i] % 2 == 0){
			sum += Numbers[i];
		}
	}
	printf("The sum of all even elements in the Number array is %d.", sum);
	
	return 0;
}
