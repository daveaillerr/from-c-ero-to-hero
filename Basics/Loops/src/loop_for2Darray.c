#include <stdio.h>
#define row 3
#define col 4

int main(){
	int i, j, matrix[row][col];
	
	printf("Input elements in the matrix: \n");
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			printf("Element [%d][%d]: ", i, j);
			scanf("%d", &matrix[i][j]);
		}
	}
	
	printf("The matrix is: \n");
	for (i = 0; i < row; i++){
		for (j = 0; j < col; j++){
			printf("%d	", matrix[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}