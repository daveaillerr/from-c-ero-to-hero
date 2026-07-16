#include <stdio.h>
void leap(void);

int main(){
	
	leap();
	
	return 0;
}

void leap(void){
	int year;
	
	printf("Enter your year: ");
	scanf("%d", &year);
	
	if (year % 4 == 0 && year % 100 != 0){
		printf("Leap Year");
	}
	else if(year % 400 == 0 ){
		printf("Leap Year");
	}
	else {
		printf("Not Leap Year");
	}
}