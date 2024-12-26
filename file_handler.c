#include <stdio.h>
#include "file_handler.h"

/*
 *Function to save booking to file
 *Appends booking details to the "bookings.txt" file.
 *new_booking: Pointer to the Booking structure containing booking details.
 */
void save_booking_to_file(Booking *new_booking) {
        FILE *file = fopen("bookings.txt", "a"); // Open file in append mode
        if (file == NULL) {
                printf("Error: Unable to open 'bookings.txt' for writing.\n");
                return;
        }

        // Write booking details to the file
        fprintf(file, 
                "Booking ID: %d | Train ID: %d | Name: %s | Age: %d | Coach: %s | Price: %.2f\n",
                new_booking->booking_id, 
                new_booking->train_id, 
                new_booking->passenger_name, 
                new_booking->age, 
                (new_booking->coach_alloted == general_option) ? "General" : "Sleeper", 
                new_booking->ticket_price);
        
        fclose(file); // Close the file
}

/*
 *Function to save the cancellation to file
 *Appends cancellation details to the "cancellations.txt" file.
 *canceled_booking: Pointer to the Booking structure containing canceled booking details.
 */
void save_cancellation_to_file(Booking *canceled_booking) {
        FILE *file = fopen("cancellations.txt", "a"); // Open file in append mode
        if (file == NULL) {
                printf("Error: Unable to open 'cancellations.txt' for writing.\n");
                return;
        }

        // Write cancellation details to the file
        fprintf(file, 
                "Canceled Booking ID: %d | Train ID: %d | Name: %s | Age: %d | Coach: %s | Refund: %.2f\n",
                canceled_booking->booking_id, 
                canceled_booking->train_id, 
                canceled_booking->passenger_name, 
                canceled_booking->age, 
                (canceled_booking->coach_alloted == general_option) ? "General" : "Sleeper", 
                canceled_booking->ticket_price);
        
        fclose(file); // Close the file
}

