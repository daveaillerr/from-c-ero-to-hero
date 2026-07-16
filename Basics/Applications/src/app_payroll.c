#include <stdio.h>

float net_salary(float a, float b, float c){
	float final;
	final = (a + b) - c;
}

int main(){
	float basic_salary, allowances, deductions, salary_result;
	
	printf("Let's find your net salary!\n");
	
	printf("Enter your basic salary: ");
	scanf("%f", &basic_salary);
	printf("Enter your allowances: ");
	scanf("%f", &allowances);
	printf("Enter your deductions: ");
	scanf("%f", &deductions);
	
	salary_result = net_salary(basic_salary, allowances, deductions);
	
	printf("Net Salary: %.2f", salary_result);
}