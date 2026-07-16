#include <stdio.h>

int main()
{
	//Variables. 
	int integer_N, start_num=1, sum_integer=0;
	
	//Used scanf to get user input.
	printf("Input a total number of treasure markers: ");
	scanf("%d", &integer_N);
	
	//If user inputs 666, it will activate.
	if (integer_N == 666)
	{
		printf("Beware! You've summoned the Ghostly Accountant.");
	}
	//If user inputs positive integers, it will activate.
	else if (integer_N > 0 )
	{
		//While loop is used. This will activate until the user input value is achieved.
		while (start_num <= integer_N)
	{
		//sum_integer will store all of the added values of start_num with it being incremented.
	    sum_integer += start_num;  
		start_num++;
	}
		printf("You've unlocked the next clue! The Golden Sum is %d", sum_integer);
	}
	//Activates if user inputs negative.
	else
	{
		printf("You can't turn back right now!");
	}
	return 0;
}
