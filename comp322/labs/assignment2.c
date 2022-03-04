#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// declare global variables including a table structure to hold scheduling information
int n;

struct node { //table

    int id, arrival_time, cycles, start_time, end_time, turnaround_time, done;

} * table_ptr = NULL;

typedef struct node table_type;

// optional: define a function that finds the maximum of two integers
#define max(a,b) (a>b ? a : b)

//***************************************************************

void print_table() {

    // declare local variables
	// print table header 	
	printf("ID\tStart\tEnd\n...");
	// for each process i from 0 up to but not including num_processes
		// print the contents (id, arrival time, total_cycles) of each field of the table's index
		printf("%d\t%d\t%d\t...", table_ptr[i].id, ...);
		// if process has been scheduled ("done" field is 1, print other contents (start time, end time, turnaround time)
		if(table_ptr[i].done == 1)
		{
		    printf("%d\t%d\t%d\n", ...);
		}
	return;

}

//*************************************************************

void input_params() {

    // declare local variables 
	
	// prompt for total number of processes 
	printf("...");
	scanf("%d", &n);
	
	// allocate memory for table to hold process parameters
	table_ptr = (table_type*)malloc(n * sizeof(table_type));
	
	// for each process i from 0 up to but not including num_processes 
		// prompt for process id, arrival time, and total cycle/cpu time 
		    
	// print contents of table
	print_table();

	return;	

}

//*************************************************************

void fifo() {

    // declare (and initilize when appropriate) local variables
	int num_done = 0;
	int earliest_arrival;
	int earliest_index;
	int current_cyle = 0;

	// for each process, reset "done" field to 0
	    table_ptr[i].done = 0;
	    
	// while there are still processes to schedule
	while(num_done < n) {

		// initilize the earliest arrival time to INT_MAX (largest integer value)
		earliest_arrival = INT_MAX;

		// for each process not yet scheduled 
		for(int i = 0; i < n; i++)
		{
		    if(table_ptr[i].done == 0)
		    {
			    // check if process has earlier arrival time than current earliest and update
			    if(table_ptr[i].arrival_time < earliest_arrival)
			    {
			        ... = ...
			        earliest_index = i;
			    } //if earlier process
		    } //if not already scheduled
		} //for-loop
		
		// set start time, end time, turnaround time, done fields for unscheduled process with earliest arrival time
		table_ptr[earliest_index].start_time = ...;
		table_ptr[earliest_index].end_time = ...;
		table_ptr[earliest_index].turnaround_time = ...;
		table_ptr[earliest_index].done = 1;
		
		// update current cycle time and increment number of processes scheduled
		
		
	} //while-loop

	// print contents of table
    print_table();

	return;

}

//*************************************************************

void sjf() {
// declare (and initilize when appropriate) local variables
// for each process, reset "done" field to 0
// while there are still processes to schedule 
// initilize the lowest total cycle time to INT_MAX (largest integer value)
// for each process not yet scheduled
// check if process has lower total cycle time than current lowest and has arrival time less than current cycle time and update 
// set start time, end time, turnaround time, done fields for unscheduled process with lowest (and available) total cycle time        
// update current cycle time and increment number of processes scheduled
// print contents of table
return;

}

//*************************************************************

void srt() {
// declare (and initilize when appropriate) local variables
// for each process, reset "done", "total_remaining" and "already_started" fields to 0
// while there are still processes to schedule 
// initilize the lowest total remaining time to INT_MAX (largest integer value)
// for each process not yet scheduled
// check if process has lower total remaining time than current lowest and has arrival time less than current cycle time and update 
// check if process already partially-scheduled
// if so, set "start time", "already_started" fields of process with lowest (and available) total remaining cycle time        
// set end time, turnaround time of process with lowest (and available) total remaining cycle time
// decrement total remaining time of process with lowest (and available) total remaining cycle time
// if remaining time is 0, set done field to 1, increment cycle time and number of scheduled processes
// print contents of table
return;
}

//*************************************************************

void exit_program() {
// free the schedule table if not NULL
return;
}

//*************************************************************

int main() {
    /* declare local vars */
    int input = 0;

    /* while user has not chosen to quit */
    while (input != 4) {
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
            default: printf("Invalid entry, please try again...");
        }
    } // while loop
 return 1; // indicates success

} // end of procedure