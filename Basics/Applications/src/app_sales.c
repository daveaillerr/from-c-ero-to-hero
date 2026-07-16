#include <stdio.h>
#include <string.h>

int main(){
	char daily[100], temp[100];
	int result, i,max, j;
	
	printf("Enter Daily Sales for a Week\n");
	for(i=0; i<7; i++){
		printf("Enter Sales: ");
		scanf("%d", &daily[i]);
	}
	
	for (i=0; i<7; i++){
		for (j=0+1; j<7; j++){
			if (i>j){
				temp[i] = daily[i];
			}
		}
	}
	
	for (i=0; i<7; i++){
		result += daily[i];
	} 
	
	printf("Highest - %d\n", temp[0]);
	
	printf("Total Sales - %d", result);
	
	
	
	return 0;
}