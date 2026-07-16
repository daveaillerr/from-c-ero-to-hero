#include <stdio.h>

int main(){
	
	int student_no, i, j, subject_no;
	float average[100], final_average[100], student_rating[100][100];
	
	// Get Info Stage
	
	printf("Enter the number of students: ");
	scanf("%d", &student_no);
	
	printf("Enter the number of subjects: ");
	scanf("%d", &subject_no);
	
	for (i = 0; i < student_no; i++){
		printf("\nStudent %d:\n", i+1);
		for (j = 0; j < subject_no; j++){
			printf("Enter grade for subject %d: ", j+1);
			scanf("%f", &student_rating[i][j]);
		}
	}
	
	// Printing Stage
	
	printf("\nStudent Grades: \n");
	for (i=0; i<student_no;i++){
			printf("Student %d: ", i+1);
		for (j=0; j < subject_no; j++){
			printf("%.f ", student_rating[i][j]);
		}
			printf("\n");
	}
	
	printf("\nAverage Grades: \n");
	for (i=0; i < student_no; i++){
			printf("Student %d: ", i+1);
			for (j = 0; j < subject_no; j++){
				average[i] += student_rating[i][j];
				final_average[i] = average[i] / subject_no;
			}
			printf("%.2f ", final_average[i]);
			printf("\n");
		}
}