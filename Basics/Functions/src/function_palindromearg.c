#include <stdio.h>
void palindrome(int*, int);

int main(){
	int pal[100], i, size;
	
	printf("Let's analyze if your given number is a Palindrom or not!\n");
	printf("Enter number of elements: ");
	scanf("%d", &size);
	
	for (i=0; i<size; i++){
		printf("Enter your elements: ");
		scanf("%d", &pal[i]);
	}
	
	printf("This is your given number: ");
	for (i = 0; i < size; i++){
		printf("%d", pal[i]);
	}
	printf("\n");
		
	palindrome(pal, size);
	
	return 0;
}

void palindrome(int a[], int b){
	int i, j;
	
	for (i = 0; i < b/2; i--){
			if (a[i] == a[b - i - 1]){
				printf("1 = Palindrome");
				break;
			}
			else {
				printf("0 = Not Palindrome");
				break;
			}
		}
}