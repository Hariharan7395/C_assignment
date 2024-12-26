all:
	gcc -o train_booking main.c train.c booking.c cancel.c file_handler.c
clean:
	rm -f .o train_booking
