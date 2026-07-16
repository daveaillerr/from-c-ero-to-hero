#include <stdio.h>

int main(){
	int size, i, j, a, b;
	int first_matrix[5][5], second_matrix[5][5], sum_matrix[5][5];

	printf("Input the size of the square matrix (less than 5): ");
	scanf("%d", &size);

	if (size > 5){
		printf("Size of the square matrix exceeded.");
	}
	
	else {
	printf("Input elements in the first matrix: \n");
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			printf("Element [%d][%d]: ", i, j);
			scanf("%d", &first_matrix[i][j]);
		}
	}
	printf("Input elements in the second matrix: \n");
	for (a = 0; a < size; a++){
		for (b = 0; b < size; b++){
			printf("Element [%d][%d]: ", a, b);
			scanf("%d", &second_matrix[a][b]);
		}
	}
	
	printf("The First matrix is: \n");
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			printf("%d	", first_matrix[i][j]);
		}
		printf("\n");
	}

	printf("The Second matrix is: \n");
	for (a = 0; a < size; a++){
		for (b = 0; b < size; b++){
			printf("%d	", second_matrix[a][b]);
		}
		printf("\n");
	}
	
	printf("The Addition of two matrix is: \n");
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			sum_matrix[i][j] = first_matrix[i][j] + second_matrix[i][j];
			printf("%d	", sum_matrix[i][j]);
		}
		printf("\n");
	}
	}

	return 0;
}
