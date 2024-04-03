#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Movie structure to hold movie details
struct Movie {
    char title[50];
    char genre[20];
    int duration;
    float indices;
};

// Booking structure to hold booking details
struct Booking {
    int bookingID;
    char movieTitle[50];
    char customerName[30];
    int numTickets;
    float totalCost;
};

// Global variables
int numMovies = 0;
int numBookings = 0;
struct Movie movies[5];
struct Booking bookings[20];

// Function to display the current movie
void displayCurrentMovie() {
    printf("Current movie: %s\n", movies[numMovies-1].title);
}

// Function to register a new movie
void registerMovie() {
    struct Movie movie;

    printf("Enter movie title: ");
    scanf("%s", movie.title);
    printf("Enter movie genre: ");
    scanf("%s", movie.genre);
    printf("Enter movie duration (in minutes): ");
    scanf("%d", &movie.duration);
    printf("Enter movie rating (out of 10): ");
    scanf("%f", &movie.indices);

    movies[numMovies++] = movie;



    printf("Movie added successfully.\n");
}

// Function to book a ticket
void bookTicket() {
    int movieIndex, numTickets;
    char customerName[30];

    printf("Enter movie index: ");
    scanf("%d", &movieIndex);
    printf("Enter number of tickets: ");
    scanf("%d", &numTickets);
    printf("Enter customer name: ");
    scanf("%s", customerName);

    // Check if movie index is valid
    if (movieIndex >= 0 && movieIndex < numMovies) {
        struct Booking booking;

        booking.bookingID = ++numBookings;
        strcpy(booking.movieTitle, movies[movieIndex].title);
   
        strcpy(booking.customerName, customerName);
        booking.numTickets = numTickets;
        booking.totalCost = numTickets * 10.0;

        bookings[numBookings-1] = booking;

        printf("Booking successful. Your booking ID is %d.\n", numBookings);
    } else {
        printf("Invalid movie index.\n");
    }
}

// Function to cancel a ticket
void cancelTicket() {
    int bookingID;

    printf("Enter booking ID: ");
    scanf("%d", &bookingID);

    // Check if booking ID is valid
    if (bookingID >= 1 && bookingID <= numBookings) {
        for (int i = bookingID - 1; i < numBookings - 1; i++) {
            bookings[i] = bookings[i+1];
        }
        numBookings--;

        printf("Booking cancelled successfully.\n");
    } else {
        printf("Invalid booking ID.\n");
    }
}

// Function to display all booking records
void viewAllBookings() {
    printf("Booking ID\tMovie\tCustomer Name\tNo. of Tickets\tTotal Cost\n");
    for (int i = 0; i < numBookings; i++) {
        printf("%d\t\t%s\t%s\t\t%d\t\t%.2f\n", bookings[i].bookingID, bookings[i].movieTitle, bookings[i].customerName, bookings[i].numTickets, bookings[i].totalCost);
    }
}

// Function to display payment options
void displayPaymentOptions() {
    printf("Payment options:\n1. Credit card\n2. Debit card\n3. Cash\n");
}

int main() {
    int choice;

    do {
        printf("\n--------------------------\n");
        printf("Cinema Booking System\n");
        printf("--------------------------\n");
        printf("1. Register Movie\n");
        printf("2. Book Ticket\n");
        printf("3. Cancel Ticket\n");
        printf("4. View All Bookings\n");
        printf("5. Display Current Movie\n");
        printf("6. Exit\n");
        printf("7. display Payment Options\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                registerMovie();
                break;
            case 2:
                bookTicket();
                break;
            case 3:
                cancelTicket();
                break;
            case 4:
                viewAllBookings();
                break;
            case 5:
                displayCurrentMovie();
                break;
            case 6:
                printf("Goodbye!\n");
                break;
            case 7:
                displayPaymentOptions();
                break;
            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 7);

    return 0;
}

