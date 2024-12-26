#include <stdio.h>
#include <stdlib.h>
#include "train.h"
#include "booking.h"
#include "cancel.h"

/*
 *This file contains the main program for the Train Ticket Booking System. 
 *It displays a menu, handles user input, and manages booking and cancellation 
 */

//Constants for menu options
#define Booking_option 1
#define Cancellation_option 2
#define Exit_option 3

// Function to display the menu
void display_menu();

int main() {
        initialise_trains(); // Initialize train data

        while (1) {
                int option_selected;

                display_menu();
                printf("Enter your choice: ");
                scanf("%d", &option_selected);

                switch (option_selected) {
                        case Booking_option:
                                search_train(); // Search and book a train
                                break;
                        case Cancellation_option:
                                cancel_ticket(); // Cancel a ticket
                                break;
                        case Exit_option:
                                printf("Thank you for using the Booking System.\n");
                                exit(0); // Exit the program
                        default:
                                printf("Error: Invalid option.\n");
                }
        }

        return 0; // Program should never reach this point
}

//Function to display menu
void display_menu() {
        printf("\nWelcome to Train Ticket Booking System \n");
        printf("1.Search and Book a Train\n");
        printf("2.Cancel a Ticket\n");
        printf("3.Exit\n");
}

