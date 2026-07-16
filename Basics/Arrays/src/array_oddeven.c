#include <stdio.h>

int main(){
	int number_elements, temp[100], odd[100], even[100], i, evencount = 0, oddcount = 0;
	
	printf("Input the number of elements to be stored in the array: ");
	scanf("%d", &number_elements);
	
	for (i = 0; i <= number_elements; i++){
		printf("Input %d elements in the array: ", i);
		scanf("%d", &temp[i]);
	}
	
	for (i=0; i < number_elements + 1; i++){
		if (temp[i] % 2 == 0){
			even[evencount] = temp[i];
			evencount++;
		}
		else {
			odd[oddcount] = temp[i];
			oddcount++;
		}
	}
	
	printf("\nThe even elements are: \n");
	for (i = 0; i < evencount; i++){
		printf("%d	", even[i]);
	}
	
	printf("\nThe Odd elements are: \n");
	for (i = 0; i < oddcount; i++){
		printf("%d	", odd[i]);
	}

	
	return 0;
}

//Comments for review:
//Indexing issues: using count var to properly track the elements in even and odd array
//Array logic end condition issue: sensitivity towards <= and < to properly end a function
//Added + 1 to the number_elements to account for the extra element because of the 0 indexing rule