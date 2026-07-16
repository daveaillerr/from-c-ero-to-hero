#include <stdio.h>
#include <string.h>

int main(){
	int i;
	float average = 0;
	struct student_record{	
	char name[100], course[100];
	float quiz_scores[50];
	}student;

	printf("Enter your name: ");
	gets(student.name);
	printf("Enter your course: ");
	gets(student.course);
	
	for (i = 0; i < 3; i++){
		printf("Enter your score in your %d subject: ", i+1);
		scanf("%f", &student.quiz_scores[i]);
		average += student.quiz_scores[i];
	}
	printf("-------------------------------------------------------------\n");
	printf("Your name is: %s\n", student.name);
	printf("Your course is: %s\n", student.course);
	
	printf("Your quiz scores:\n");
	for (i = 0; i < 3; i++){
	printf("%.2f\n", student.quiz_scores[i]);
	}
	printf("Your average score of your quizzes: \n%.2f\n", average / 3);
	
	return 0;
}