/*
David McNeary
COMP 322L Section 7799
Assignment #2
3/14/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// declare global variables including a table structure to hold scheduling information
int n;
int initialized = 0;

struct node { //table

    int id, arrival_time, cycles, total_remaining, start_time, end_time, turnaround_time, started, done;

} * table_ptr = NULL;

typedef struct node table_type;

// optional: define a function that finds the maximum of two integers
#define max(a,b) (a>b ? a : b)

//***************************************************************

int check_init() {

    if (initialized == 0) {
        printf("Program not initialized - please choose option 1 on main menu\n");
        return 0;
    } else return 1;

}

void print_table() {

    // declare local variables
	// print table header 	
	printf("ID\tArrival\tTotal\tStart\tEnd\tTurnaround\n");
	printf("--------------------------------------------------");
	// for each process i from 0 up to but not including num_processes
	for (int i = 0; i < n; i++) {
		// print the contents (id, arrival time, total_cycles) of each field of the table's index
		printf("\n%d\t%d\t%d\t", table_ptr[i].id, table_ptr[i].arrival_time, table_ptr[i].cycles);
		// if process has been scheduled ("done" field is 1, print other contents (start time, end time, turnaround time)
		if (table_ptr[i].done == 1) {
		    printf("%d\t%d\t%d", table_ptr[i].start_time, table_ptr[i].end_time, table_ptr[i].turnaround_time);
		}
	}

	printf("\n");
	return;

}

//*************************************************************

void input_params() {

    // declare local variables 
	
	// prompt for total number of processes 
	printf("Enter total number of processes: ");
    scanf("%d", &n);
	
	// allocate memory for table to hold process parameters
	table_ptr = (table_type*)malloc(n * sizeof(table_type));
	
	// for each process i from 0 up to but not including num_processes
	for (int i = 0; i < n; i++) {
		// prompt for process id, arrival time, and total cycle/cpu time 
		printf("Enter process ID: ");
		scanf("%d", &table_ptr[i].id);
		printf("Enter arrival time for Process %d: ", table_ptr[i].id);
		scanf("%d", &table_ptr[i].arrival_time);
		printf("Enter CPU time (cycles) for Process %d: ", table_ptr[i].id);
		scanf("%d", &table_ptr[i].cycles);
		table_ptr[i].done = 0;
	}
	
	initialized = 1;

	// print contents of table
	printf("\n");
	print_table();

	return;	

}

//*************************************************************

void fifo() {

	if (check_init() == 0) return; 

    // declare (and initilize when appropriate) local variables
	int num_done = 0;
	int earliest_arrival;
	int earliest_index;
	int current_cycle = 0;

	// for each process, reset "done" field to 0
	for (int i = 0; i < n; i++) {
		table_ptr[i].done = 0;
	}

	// while there are still processes to schedule
	while (num_done < n) {

		// initilize the earliest arrival time to INT_MAX (largest integer value)
		earliest_arrival = INT_MAX;

		// for each process not yet scheduled 
		for (int i = 0; i < n; i++) {
		    if (table_ptr[i].done == 0) {
			    // check if process has earlier arrival time than current earliest and update
			    if (table_ptr[i].arrival_time < earliest_arrival) {
			        earliest_arrival = table_ptr[i].arrival_time;
			        earliest_index = i;
			    } //if earlier process
		    } //if not already scheduled
		} //for-loop
		
		// set start time, end time, turnaround time, done fields for unscheduled process with earliest arrival time
		table_ptr[earliest_index].start_time = current_cycle;
		table_ptr[earliest_index].end_time = current_cycle + table_ptr[earliest_index].cycles;
		table_ptr[earliest_index].turnaround_time = table_ptr[earliest_index].end_time - table_ptr[earliest_index].arrival_time;
		table_ptr[earliest_index].done = 1;
		
		// update current cycle time and increment number of processes scheduled
		current_cycle += table_ptr[earliest_index].cycles;
		num_done++;
		
	} //while-loop

	// print contents of table
    print_table();

	return;

}

//*************************************************************

void sjf() {

	if (check_init() == 0) return; 

	// declare (and initilize when appropriate) local variables
	int num_done = 0;
	int shortest_time;
	int shortest_arrival;
	int shortest_index;
	int current_cycle = 0;

	// for each process, reset "done" field to 0
	for (int i = 0; i < n; i++) {
		table_ptr[i].done = 0;
	}

	// while there are still processes to schedule
	while (num_done < n) {

		// initilize the lowest total cycle time to INT_MAX (largest integer value)
		shortest_time = INT_MAX;

		// for each process not yet scheduled
		for (int i = 0; i < n; i++) {
		    if (table_ptr[i].done == 0) {
				// check if process has lower total cycle time than current lowest and has arrival time less than current cycle time and update 
				if ( (table_ptr[i].cycles < shortest_time)
				&& (table_ptr[i].arrival_time <= current_cycle) ) {
					shortest_time = table_ptr[i].cycles;
			        shortest_arrival = table_ptr[i].arrival_time;
			        shortest_index = i;
				}
			}
		}

		// set start time, end time, turnaround time, done fields for unscheduled process with lowest (and available) total cycle time
		table_ptr[shortest_index].start_time = current_cycle;
		table_ptr[shortest_index].end_time = current_cycle + table_ptr[shortest_index].cycles;
		table_ptr[shortest_index].turnaround_time = table_ptr[shortest_index].end_time - table_ptr[shortest_index].arrival_time;
		table_ptr[shortest_index].done = 1;

		// update current cycle time and increment number of processes scheduled
		current_cycle += table_ptr[shortest_index].cycles;
		num_done++;
	}

	// print contents of table
	print_table();
	return;

}

//*************************************************************

void srt() {

	if (check_init() == 0) return;

	// declare (and initilize when appropriate) local variables
	int num_done = 0;
	int lowest_time;
	int lowest_arrival;
	int lowest_index;
	int current_cycle = 0;
	//printf("\nCycle: %d\n", current_cycle);

	// for each process, reset "done", "total_remaining" and "already_started" fields to 0
	for (int i = 0; i < n; i++) {
		table_ptr[i].done = 0;
		table_ptr[i].total_remaining = table_ptr[i].cycles;
		table_ptr[i].started = 0;
	}

	// while there are still processes to schedule 
	while (num_done < n) {

		// initilize the lowest total remaining time to INT_MAX (largest integer value)
		lowest_time = INT_MAX;

		// for each process not yet scheduled
		for (int i = 0; i < n; i++) {
		    if (table_ptr[i].done == 0) {
				// check if process has lower total remaining time than current lowest and has arrival time less than current cycle time and update 
				if ( (table_ptr[i].total_remaining < lowest_time)
				&& (table_ptr[i].arrival_time <= current_cycle) ) {
					lowest_time = table_ptr[i].total_remaining;
					lowest_arrival = table_ptr[i].arrival_time;
					lowest_index = i;
				}
			}
		}

		// check if process already partially-scheduled
		if (table_ptr[lowest_index].started == 0) {
			// if so, set "start time", "already_started" fields of process with lowest (and available) total remaining cycle time
			table_ptr[lowest_index].start_time = current_cycle;
			table_ptr[lowest_index].started = 1;
		}
		
		     
		// set end time, turnaround time of process with lowest (and available) total remaining cycle time
		table_ptr[lowest_index].end_time = current_cycle + table_ptr[lowest_index].total_remaining;
		table_ptr[lowest_index].turnaround_time = table_ptr[lowest_index].end_time - table_ptr[lowest_index].arrival_time;

		// decrement total remaining time of process with lowest (and available) total remaining cycle time
		table_ptr[lowest_index].total_remaining--;
		//printf("Remaining time for Process %d: %d\n", table_ptr[lowest_index].id, table_ptr[lowest_index].total_remaining);

		// if remaining time is 0, set done field to 1, increment cycle time and number of scheduled processes
		if (table_ptr[lowest_index].total_remaining == 0) {
			table_ptr[lowest_index].done = 1;
			//printf("Process %d complete!\n", table_ptr[lowest_index].id);
			num_done++;
			//printf("Remaining processes: %d\n", n - num_done);
		}

		current_cycle++;

	}

	// print contents of table
	print_table();

	return;
}

//*************************************************************

void exit_program() {
	// free the schedule table if not NULL
	if (table_ptr != NULL) free(table_ptr);
	printf("Quitting program...");
	return;
}

//*************************************************************

int main() {
    /* declare local vars */
    int input = 0;

    /* while user has not chosen to quit */
	printf("Batch Scheduling\n");
	printf("------------------\n");
    while (input != 5) {
        /* print menu of options */
        printf("\nPlease choose from the following:\n");
        printf("1) Enter parameters\n");
        printf("2) Schedule processes with FIFO algorithm\n");
        printf("3) Schedule processes with SJF algorithm\n");
        printf("4) Schedule processes with SRT algorithm\n");
        printf("5) Quit program and free memory\n");
        /* prompt for menu selection */
        printf("Enter selection: ");
        scanf("%d", &input);
        printf("\n");
        /* call appropriate procedure based on choice--use switch 
        statement or series of if, else if, else statements */
        switch (input) {
            case 1: input_params(); break;
            case 2: fifo(); break;
            case 3: sjf(); break;
            case 4: srt(); break;
            case 5: exit_program(); break;
            default: printf("Invalid entry, please try again...\n");
        }
    } // while loop

 return 1; // indicates success

} // end of procedure