#include <stdio.h>
#include <string.h>

int main(){
	struct movie_ticket{
		char title[50];
		int seat_no;
		float price;
	}movie;
	int accept;
	
	printf("Enter the movie name: ");
	gets(movie.title);
	printf("Enter the seat number: ");
	scanf("%d", &movie.seat_no);
	printf("Enter the ticket price: ");
	scanf("%f", &movie.price);
	
	printf("\nMovie Ticket Booking:");
	printf("\n     Movie Title: %s", movie.title);
	printf("\n     Seat Number: %d", movie.seat_no);
	printf("\n     Ticket Price: %.2f\n", movie.price);

	printf("\nDo you accept this conditions? 1 - Yes or 2 - No: ");
	scanf("%d", &accept);
	
	switch(accept){	
		case 1:
			printf("Booking Confirmed.");
		break;
		case 2:
			printf("Booking Cancelled.");
		break;
		default:
			printf("Invalid Input. Try again later.");
		break;
	}

	return 0;
}