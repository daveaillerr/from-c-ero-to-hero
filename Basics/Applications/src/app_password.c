#include <stdio.h>
#include <string.h>

int main(){
	char password[100], username[100], true_password[] = {'Secure123'}, 
	true_username[] = {'string_101'}, result1;
	
	printf("Enter username: ");
	get(username);
	printf("Enter password: ");
	get(password);
	
	result1 = strcmp(password, true_password);
	
	if (result1 == 0){
		printf("Incorrect Password. Try Again");
	}
	else {
		printf("Incorrect Password. Try Again");
	}
	return 0;
}