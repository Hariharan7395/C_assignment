#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

/*
 *This header file declares functions for handling file operations, 
 *including saving booking and cancellation details in the files.
 */

#include "booking.h"

//Fuction to save the booking to file
void save_booking_to_file(Booking *new_booking);

//Function to save the cancellation to file
void save_cancellation_to_file(Booking *canceled_booking);

#endif 

