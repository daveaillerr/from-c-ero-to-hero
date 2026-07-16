#include <stdio.h>

int main(){
	
	int movie_no, i, j, rating_no;
	float average[100], final_average[100], movie_rating[100][100];
	
	// Get Info Stage
	
	printf("Enter the number of movies: ");
	scanf("%d", &movie_no);
	
	printf("Enter the number of ratings per movie: ");
	scanf("%d", &rating_no);
	
	for (i = 0; i < movie_no; i++){
		printf("\nMovie %d:\n", i+1);
		for (j = 0; j < rating_no; j++){
			printf("Enter rating %d: ", j+1);
			scanf("%f", &movie_rating[i][j]);
		}
	}
	
	// Printing Stage
	
	printf("\nMovie Ratings: \n");
	for (i=0; i<movie_no;i++){
			printf("Movie %d: ", i+1);
		for (j=0; j<rating_no; j++){
			printf("%.f ", movie_rating[i][j]);
		}
			printf("\n");
	}
	
	printf("\nAverage Ratings: \n");
	for (i=0; i<movie_no;i++){
			printf("Movie %d: ", i+1);
			for (j = 0; j < rating_no; j++){
				average[i] += movie_rating[i][j];
				final_average[i] = average[i] / rating_no;
			}
			printf("%.2f ", final_average[i]);
			printf("\n");
		}
}




