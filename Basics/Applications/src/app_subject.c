#include <stdio.h>
void calculateAverageGrade(float*, int);

int main(){
	int number, i; 
	float subject[100];

	
	printf("Calculate your average grade! ");
	printf("\nEnter the number of your subjects: ");
	scanf("%d", &number);
	
	printf("Enter your scores in all of your %d subjects:\n", number);
	for (i = 0; i < number; i++){
	printf("Enter %d subject: ", i+1);
	scanf("%f", &subject[i]);
	}
	
	calculateAverageGrade(subject, number);
	
	return 0;
}

void calculateAverageGrade(float subject[], int number){
	int i;
	float final, sum = 0;
	
	for (i = 0; i < number; i++){
		sum += subject[i];
	} 
	
	final = sum / number;
	
	printf("The average of your grade is: %.2f", final);
}