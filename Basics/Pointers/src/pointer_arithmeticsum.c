#include <stdio.h>
int add(int *fnum, int *snum){
	int sum;
	sum = *fnum + *snum;
	return sum;
}

int main(){
	int fnum, snum;
	
	printf("Input the first number: ");
	scanf("%d", &fnum);
	printf("Input the second number: ");
	scanf("%d", &snum);

	printf("The sum of %d and %d is %d", fnum, snum, add(&fnum, &snum));
	
	return 0;
}
