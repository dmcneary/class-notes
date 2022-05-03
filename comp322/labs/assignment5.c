/*
David McNeary
COMP 322/L
Assignment 5
4/28/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Declare global variables, including dynamic array to store sequence of traversed tracks
int* sequence = NULL;
int seq_size;

/*********************************************************/

void enter_params() {

    int i;

	// prompt for the sequence size
    printf("Enter size of sequence: \n");
    scanf("%d", seq_size);

	// allocate memory for the sequence of traversed tracks
    sequence = (int *)malloc(seq_size * sizeof(int));

	// prompt for starting track, store in index 0
    printf("Enter starting track: \n");
    scanf("%d", &sequence[0]);

	// prompt for sequence of tracks to seek, store in index 1 to "sequence size-1"
    printf("Enter sequence of tracks to seek: \n");
    for (i = 1; i < seq_size; i++) {
        scanf("%d", &sequence[i]);
    }

	return;

} // "OPTION #1"


/*********************************************************/

void fifo() {

	// declare local variables
    int i, count = sequence[0];
	
	// calculate total distance of traversed tracks
    for (i = 1; i < seq_size; i++) {
        count += abs(sequence[i] - sequence[i - 1]);
    }

    printf("Traversed sequence: ");
	// print sequence of traversal
    for (i = 0; i < seq_size; i++) {
        printf("%d ", &sequence[i]);
    }

	// print total distance of tracks traversed
    printf("\nThe distance of the traversed tracks is: %d\n", count);
    
	return;

} // "OPTION #2"	

/*********************************************************/

void sstf() {

	// declare local variables
    int num_done = 0;
    int shortest, shortest_i;
    int* done = (int *)calloc(seq_size, sizeof(int));

	// initialize current track and distance traversed to starting track
    int count = sequence[0], current = count;;

	// begin printing sequence of traversal 
    printf("Traversed sequence: %d", current);

	// until every track is traversed
    while (num_done < seq_size) {
		// initilize shortest distance to INT_MAX
        shortest = INT_MAX;

		// for each track in sequence
        int i;
        for (i = 1; i < seq_size; i++) {
			// if not already traversed
            if (done[i] == 0) {
				//if distance to traverse is shorter than current shortest distance
                if ( abs(sequence[i] - current) < shortest ) {
			        // set current shortest distance and index of the track	w/ shortest distance
                    shortest = abs(sequence[i] - current);
                    shortest_i = i;
                }
            }
        }

		// set "done" value for track w/shortest distance to 1 (mark as traversed)
        done[shortest_i] = 1;

		// increment number of tracks that have been traversed
        num_done++;

		// update total distance traversed
        count += shortest;

		//set current track to new position, print position
        current = sequence[shortest_i];
        printf("%d", current);
    }

  	// print total distance traversed
	printf("\nThe distance of the traversed tracks is: %d\n", count);

	return;

} // "OPTION #3" 

/*********************************************************/

void reg_scan() {

	// declare local variables

	//prompt for initial direction (0=descreasing, 1=increasing)
	
	// initialize current track and distance traversed to starting track

	// begin printing sequence of traversal 

	// until every track is traversed

		// initilize shortest distance to INT_MAX

		// for each track in sequence

			// if not already traversed

				//if distance to traverse is shorter than current shortest distance in the current direction

					// set current shortest distance and index of the track	w/ shortest distance

     					// set flag that at least one track was traversed

		// if at least one track was traversed

    			// set "done" value for track w/shortest distance to 1 (mark as traversed)

			// increment number of traversed tracks

			// update total distance traversed

			//set current track to new position, print position

		// else change direction

 	// print total distance traversed

	return;

} // "OPTION #4"

/*********************************************************/

void c_scan() {

	// declare local variables

	// initialize current track and number traversed to starting track

	// begin printing sequence of traversal 

	// until every track is traversed

		// initilize shortest distance to INT_MAX

		// for each track in sequence

			// if not already traversed

				//if distance to traverse is shorter than current shortest distance and a positive value (only increasing direction)

					// set current shortest distance and index of the track	w/ shortest distance

     					// set flag that at least one track was traversed

		// if at least one track was traversed

    			// set "done" value for track w/shortest distance to 1 (mark as traversed)

			// increment number of tracks that have been traversed

			// if largest track was reached

				// update total distance traversed by derementing by distance to track (subtracts distance from 0 to track)

				// reset "largest track" flag

			// else
	
				// update total distance traversed by distance to track

			//set current track to new position, print position

		// else (no track was traversed)

			// update total distance by current track (adds remaining distance before going back to 0)
		
			// reset current track to 0 (loop back around)

			// set "end reached" flag to 1

 	// print total distance traversed

	return;    

} // "OPTION #5

/***************************************************************/

void quit_program() {

	// if sequence is not NULL, free sequence
    if (sequence != NULL) {
        free(sequence);
    }

	return;

} // "OPTION #6


/***************************************************************/

int main() {

	/* declare local vars */
	int input = 0;

    while (input != 6) { // while user has not chosen to quit
        // print menu of options
        printf("---------------------------------\n");
        printf("Disk Scheduling\n");
        printf("---------------------------------\n");
        printf("Please choose from the following:\n");
        printf("1) Enter parameters\n");
		printf("2) Calculate distance to traverse tracks using FIFO\n"); 
		printf("3) Calculate distance to traverse tracks using SSTF\n");
		printf("4) Calculate distance to traverse tracks using Scan\n");
		printf("5) Calculate distance to traverse tracks using C-Scan \n");
		printf("6) Quit program and free memory\n");
        
        // prompt for menu selection
        printf("\nEnter selection: \n");
        scanf("%d", &input);

        // call appropriate procedure based on choice
        // use switch statement or series of if, else if, else statements
        switch (input) {
            case 1: enter_params(); break;
            case 2: fifo(); break;
            case 3: sstf(); break;
			case 4: reg_scan(); break;
			case 5: c_scan(); break;
			case 6: printf("\nQuitting program...\n"); quit_program(); break;
            default: printf("Invalid entry, please try again...\n");
        }

    } // while loop

	return 1; // indicates success 

} // main	