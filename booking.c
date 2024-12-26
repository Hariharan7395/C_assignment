#include <stdio.h>
#include <string.h>
#include "booking.h"
#include "file_handler.h"

/*
 *This file provides functionalities to book train tickets, 
 *manage the booking data, and display receipts for booked tickets.
 */

// Global booking variables
int booking_count = 0;          // Total number of bookings 
Booking bookings[100];         // Array to store booking details 

/*
 *Function to Books a ticket for a train and assigns the chosen coach.
 *train: Pointer to the train structure containing train details.
 */
void book_ticket(Train *train) {
        char name[50];
        int age;
        int coach_prefered;
        float ticket_price;

        printf("\nSELECT THE Preferred Coach\nOPTIONS:\n1. General Coach\n2. Sleeper Coach\n");
        scanf("%d", &coach_prefered);

        switch (coach_prefered) {
                case general_option:
                        if (train->general_seat <= 0) {
                                printf("No seats available in General Coach.\n");
                                return;
                        }
                        ticket_price = train->general_price;
                        train->general_seat--;
                        break;

                case sleeper_option:
                        if (train->sleeper_seat <= 0) {
                                printf("No seats available in Sleeper Coach.\n");
                                return;
                        }
                        ticket_price = train->sleeper_price;
                        train->sleeper_seat--;
                        break;

                default:
                        printf("Invalid Choice! Please try again.\n");
                        return;
        }

        printf("Enter Passenger Name: ");
        scanf("%s", name);
        printf("Enter Passenger Age: ");
        scanf("%d", &age);

        Booking new_booking = {
                .booking_id = ++booking_count,
                .train_id = train->train_id,
                .age = age,
                .coach_alloted = coach_prefered,
                .ticket_price = ticket_price
        };

        strcpy(new_booking.passenger_name, name);

        bookings[booking_count - 1] = new_booking;

        save_booking_to_file(&new_booking);
        view_receipt(&new_booking);
}


// Function Displays a receipt for the given booking.
void view_receipt(Booking *new_booking) {
        printf("\nYour Ticket is Booked Successfully!\n");
        printf("Booking ID: %d\n", new_booking->booking_id);
        printf("Passenger Name: %s\n", new_booking->passenger_name);
        printf("Ticket Price: Rs. %.2f\n", new_booking->ticket_price);
        printf("Coach: %s\n", 
                (new_booking->coach_alloted == general_option) ? "General" : "Sleeper");
}

