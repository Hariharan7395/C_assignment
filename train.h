#ifndef TRAIN_H
#define TRAIN_H

/*
 *This header file defines the Train structure, the Option enumeration,
 *and declares constants, functions, and external variables for train operations.
 */

#define TRAIN_COUNT 4

//Structure representing the details of a train
typedef struct {
    int train_id;                    //Unique identifier for the train
    char train_name[50];             //Name of the train
    char source_station[50];         //Train's source station
    char destination_station[50];    //Train's destination station
    int general_seat;                //Available general seats 
    int sleeper_seat;                //Available sleeper seats
    float general_price;             //Price for general seats
    float sleeper_price;             //Price for sleeper seats
} Train;

//enum for booking or cancellation or exit option
typedef enum {
    BOOKING_OPTION = 1,              //Option for booking a ticket
    CANCELLATION_OPTION = 2,         //Option for cancelling a ticket
    EXIT_OPTION = 3                  //Option to exit the program 
} Option;

//Declaration for train array
extern Train trains[TRAIN_COUNT];

//Function declarations to initiatlise the train and search the train
void initialise_trains(void);
void search_train(void);

#endif
