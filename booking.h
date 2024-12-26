#ifndef BOOKING_H
#define BOOKING_H

/*
 *This header file defines the data structures and functions 
 *for managing train ticket bookings, including booking details 
 *and receipt generation.
 */

#include "train.h"

//Enumeration for coach options 
typedef enum {
        general_option = 1,  // General Coach 
        sleeper_option = 2   //Sleeper Coach
} coach_option;

//Structure to store booking details 
typedef struct {
        int booking_id;           // Unique ID for the booking 
        int train_id;             // ID of the booked train 
        char passenger_name[50];  // Name of the passenger 
        int age;                  // Age of the passenger 
        coach_option coach_alloted; // Allocated coach type 
        float ticket_price;       // Price of the ticket 
} Booking;

//Global variables 
extern int booking_count;         //Total number of bookings 
extern Booking bookings[100];     // Array to store bookings 

/*Function declarations to Book a ticket for a train.
 *Parameters:
 *train: Pointer to the train structure containing train details.
 */
void book_ticket(Train *train);

/*Displays the booking receipt.
 *Parameters:
 *new_booking: Pointer to the Booking structure containing booking details.
 */
void view_receipt(Booking *new_booking);

#endif 

