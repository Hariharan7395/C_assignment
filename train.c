#include <stdio.h>
#include <string.h>
#include "train.h"
#include "booking.h"

/*
 *This file provides functions to initialize train details, search for trains based on routes, 
 *and facilitate booking operations.
 */

// Global array to store train details
Train trains[TRAIN_COUNT]; 

//Function to initialise the trains
void initialise_trains() {
        trains[0] = (Train){1, "TN Express", "Chennai", "Bangalore", 10, 10, 500, 1000};
        trains[1] = (Train){2, "KL Express", "Cochin", "Bangalore", 5, 2, 600, 900};
        trains[2] = (Train){3, "KA Express", "Kuppam", "Bangalore", 20, 10, 400, 800};
        trains[3] = (Train){4, "AP Express", "Tirupathi", "Bangalore", 5, 20, 600, 1100};
}

//Function to search the trains
void search_train() {
        char source[50];
        char destination[50];
        int train_found = 0;

        printf("Enter the Source Railway Station: ");
        scanf("%s", source);
        printf("Enter the Destination Railway Station: ");
        scanf("%s", destination);

        // Iterate through the list of trains to find a match
        for (int i = 0; i < TRAIN_COUNT; i++) {
                if (strcmp(trains[i].source_station, source) == 0 &&
                    strcmp(trains[i].destination_station, destination) == 0) {
                        train_found = 1;

                        // Display train details
                        printf("\nAvailable Train Information:\n");
                        printf("Train ID: %d\n", trains[i].train_id);
                        printf("Train Name: %s\n", trains[i].train_name);
                        printf("Available General Seats: %d\n", trains[i].general_seat);
                        printf("Available Sleeper Seats: %d\n", trains[i].sleeper_seat);
                        printf("Price of General Seat: Rs. %f\n", trains[i].general_price);
                        printf("Price of Sleeper Seat: Rs. %f\n", trains[i].sleeper_price);

                        // Proceed to book a ticket for the found train
                        book_ticket(&trains[i]);
                        return;
                }
        }

        if (!train_found) {
                printf("Error: No train available for this route.\n");
        }
}

