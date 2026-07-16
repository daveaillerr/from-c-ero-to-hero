#include <stdio.h>

int main(){
	int fnum, snum, tnum, sum, *fnum_, *snum_, *tnum_;
	
	printf("Input the first number: ");
	scanf("%d", &fnum);
	printf("Input the second number: ");
	scanf("%d", &snum);
	printf("Input the third number: ");
	scanf("%d", &tnum);
	
	fnum_ = &fnum;
	snum_ = &snum;
	tnum_ = &tnum;

	sum = *fnum_ + *snum_ + *tnum_;

	printf("The sum of the numbers entered is: %d", sum);
	
	return 0;
}