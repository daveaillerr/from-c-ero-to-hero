#include <stdio.h>
int comparator(int);

int main(){
	int user_input, result;
	
	printf("Input any number: ");
	scanf("%d", &user_input);
	
	result = comparator(user_input);
	
	switch(result){
		case 1: printf("The entered number is even.");
		break;
		case 2: printf("The entered number is odd.");
		break;
	}
}

int comparator(int x){
	if (x % 2 == 0){
		return(1);
	}	
	
	else {
		return(2);
	}
}