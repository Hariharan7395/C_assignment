#include <stdio.h>
#include "cancel.h"
#include "train.h"
#include "file_handler.h"

/*
 *Function to cancel the ticket
 *Cancels a train ticket by booking ID, restores the seat count for the respective coach, 
 *and logs the cancellation.
 */
void cancel_ticket() {
        int booking_id;
        int found = 0;

        printf("Enter Booking ID to Cancel: ");
        scanf("%d", &booking_id);

        // Search for the booking with the given ID
        for (int i = 0; i < booking_count; i++) {
                if (bookings[i].booking_id == booking_id) {
                        found = 1;

                        // Restore seat count in the corresponding train
                        for (int j = 0; j < TRAIN_COUNT; j++) { // Assuming TRAIN_COUNT is defined in train.h
                                if (bookings[i].train_id == trains[j].train_id) {
                                        if (bookings[i].coach_alloted == general_option) {
                                                trains[j].general_seat++;
                                        } else if (bookings[i].coach_alloted == sleeper_option) {
                                                trains[j].sleeper_seat++;
                                        }
                                        break;
                                }
                        }

                        printf("Booking ID %d has been successfully canceled.\n", booking_id);

                        // Save cancellation details to the file
                        save_cancellation_to_file(&bookings[i]);
                        return;
                }
        }

        if (!found) {
                printf("Booking ID not found!\n");
        }
}

