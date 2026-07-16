#include <stdio.h>

void area_square(void);

int main(){
	
	printf("Calculate the area of square \n");
	area_square();
	
	return 0;
}

void area_square(void)
{
	int side;
		printf("Enter a side of square: ");
		scanf("%d", &side);
		printf("The area of your square is: %d square cm", side * side);
}

