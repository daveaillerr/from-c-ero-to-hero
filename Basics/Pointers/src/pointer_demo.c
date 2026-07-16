#include <stdio.h>

int main(){
	int m = 300, *mp;
	float fx = 300.600006, *fxm;
	char cht = 'z', *chtm;
	
	mp = &m;
	fxm = &fx;
	chtm = &cht; 
	
	printf("Pointer: Demonstrate the use of & and * operator:\n");
	printf("-------------------------------------------------\n");
	printf("m = %d\n", m);
	printf("fx = %f\n", fx);
	printf("cht = %c\n", cht);
	
	printf("\nUsing & operator:\n");
	printf("-----------------\n");
	printf("address of m = %p\n", mp);
	printf("address of fx = %p\n", fxm);
	printf("address of cht = %p\n", chtm);
	
	printf("\nUsing & and * operator:\n");
	printf("-----------------------\n");
	printf("value at address of m = %d\n", *mp);
	printf("value at address of fx = %f\n", *fxm);
	printf("value at address of cht = %c\n", *chtm);
	
	printf("\nUsing only pointer variable:\n");
	printf("----------------------------\n");
	printf("address of m = %p\n", mp);
	printf("address of fx = %p\n", fxm);
	printf("address of cht = %p\n", chtm);
	
	printf("\nUsing only pointer operator:\n");
	printf("----------------------------\n");
	printf("value at address of m = %d\n", *mp);
	printf("value at address of fx = %f\n", *fxm);
	printf("value at address of cht = %c\n", *chtm);
	
	return 0;
}