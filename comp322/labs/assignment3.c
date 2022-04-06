/*
David McNeary
COMP 322L
Assignment #3
3/30/22
*/

#include <stdio.h>
#include <stdlib.h>

// Declare dynamic arrays and global variables
int *resource = NULL;
int *available = NULL;

int *maximum = NULL;
int *allocated = NULL;
int *need = NULL;

int np, nr;

//*********************************************************

void print_resources() {

    // declare local variables
    printf("Resources: \n");

    // for loop: print each resource index
    for (int i = 0; i < nr; i++) {
        printf("\tr%d", i);
    }

    printf("\n");

    // for loop: print number of total units of each resource index
    for (int i = 0; i < nr; i++) {
        printf("\t%d", resource[i]);
    }

    printf("\n");

    return;

}

//*********************************************************

void print_avaliable() {

    // declare local variables
    printf("Available: \n");

    // for loop: print each resource index
    for (int i = 0; i < nr; i++) {
        printf("\tr%d", i);
    }

    printf("\n");

    // for loop: print number of available units of each resource index
    for (int i = 0; i < nr; i++) {
        printf("\t%d", available[i]);
    }

    printf("\n");

    return;

}

//*************************************************************

void print_max() {

    // declare local variables
    printf("Maximum: \n");

    // for loop: print each resource index
    for (int i = 0; i < nr; i++) {
        printf("\tr%d", i);
    }

    printf("\n");

    for (int i = 0; i < np; i++) { // for each process:
        printf("p%d:", i);
        for (int j = 0; j < nr; j++) { //for each resource:
            // print maximum number of units each process may request from each resource
            printf("\t%d", maximum[i*nr+j]);
        }
        printf("\n");
    }

    printf("\n");

    return;

}

//*************************************************************

void print_allocated() {

    // declare local variables
    printf("Allocated: \n");

    // for loop: print each resource index
    for (int i = 0; i < nr; i++) {
        printf("\tr%d", i);
    }

    printf("\n");

    for (int i = 0; i < np; i++) { // for each process:
        printf("p%d:", i);
        for (int j = 0; j < nr; j++) { // for each resource:
            // print number of units each process is allocated from each resource
            printf("\t%d", allocated[i*nr+j]);
        }
        printf("\n");
    }

    printf("\n");

    return;

}

//*************************************************************

void print_need() {

    // declare local variables
    printf("Need: \n");

    // for loop: print each resource index
    for (int i = 0; i < nr; i++) {
        printf("\tr%d", i);
    }

    printf("\n");

    for (int i = 0; i < np; i++) { // for each process:
        printf("p%d:", i);
        for (int j = 0; j < nr; j++) { // for each resource:
            // print number of units each process needs from each resource
            printf("\t%d", need[i*nr+j]);
        }
        printf("\n");
    }

    printf("\n");

    return;

}

//**************************************************************

void enter_params() {

    printf("\n");

    // declare local variables
    int units;

    // prompt for number of processes and number of resources
    printf("Enter number of processes: \n");
    scanf("%d", &np);
    printf("Enter number of resources: \n");
    scanf("%d", &nr);

    // allocate memory for vectors and arrays: resource, available, max_claim, allocated, need
    resource = (int *)malloc(nr * sizeof(int));
    available = (int *)malloc(nr * sizeof(int));
    maximum = (int *)malloc(nr * np * sizeof(int));
    allocated = (int *)malloc(nr * np * sizeof(int));
    need = (int *)malloc(nr * np * sizeof(int));

    // prompt for number of units
    printf("Enter number of units for resources (r0 to r%d): \n", nr - 1);
    for (int j = 0; j < nr; j++) { // for each resource
        // set resource and available vectors indices
        scanf("%d", &units);
        resource[j] = units;
        available[j] = units;
    }
    
    for (int i = 0; i < np; i++) {// for each process
        // prompt for maximum number of units requested by process
        printf("Enter max units process p%d will request from each resource (r0 to r%d): \n", i, nr - 1);

        for (int j = 0; j < nr; j++) {// for each resource
            //update maxclaim and need arrays
            scanf("%d", &units);
            maximum[i*nr+j] = units;
            need[i*nr+j] += units;
            
        }
        
    }
    // for each process
    for (int i = 0; i < np; i++) {// for each process
        // prompt for number of resource units allocated to process
        printf("Enter number of units of each resource (r0 to r%d) allocated to process p%d: \n", nr - 1, i);
        // for each resource,
        for (int j = 0; j < nr; j++) {// for each resource
            // update allocated units
            scanf("%d", &units);
            allocated[i*nr+j] = units;
            need[i*nr+j] -= units;
            available[j] -= units;
        }
        
    }

    // print resource vector, available vector, maxclaim array, allocated array, need array
    printf("\nParameter entry completed.\n");
    printf("---------------------------------\n");
    print_resources();
    print_avaliable();
    print_max();
    print_allocated();
    print_need();
    printf("\n");

    return;

}

//******************************************************************

void bankers_algo() {

    printf("\n");

    // declare local variables, including vector to indicate if process is safely sequenced and "num_sequenced" count
    int *done = (int *)calloc(np, sizeof(int));
    int ns = 0;
    int res_avail;
    int not_dead = 1;
    
    // while not all processes are processed
    while ((ns < np) && not_dead) {
        //put not_dead here?
        not_dead = 0; //not working!!
        
        for (int i = 0; i < np; i++) { // for each process
            // reset flags
            res_avail = 1;

            // if process has not been processed yet
            if (done[i] == 0) {
                // print message comparing need vector with available vector
                printf("Comparing: <");
                for (int j = 0; j < nr; j++) {
                    printf(" %d ", need[i*nr+j]);
                }
                printf("> <= <");
                for (int j = 0; j < nr; j++) {
                    printf(" %d ", available[j]);
                }
                printf("> : ");

                // for each resource
                for (int j = 0; j < nr; j++) {
                    // check for safe processing by comparing process' need vector to available vector
                    res_avail &= need[i*nr+j] <= available[j];
                }
                
                // if each resource is available
                if (res_avail) {
                    not_dead = 1;

                    // print message that process can be processed
                    printf("Yes --> p%d can be processed.\n", i);
                    
                    // for each resource
                    for (int j = 0; j < nr; j++) {
                        // update number of available units of resource
                        available[j] += allocated[i*nr+j];

                        // free all resources allocated to process
                        allocated[i*nr+j] = 0;
                    }
                        
                    // increment number of sequenced processes
                    ns++;
                } else {
                    // else print message that process cannot be processed
                    printf("No --> p%d can not be processed.\n", i);
                }    
            }
        }
    }

    //if (no process was processed in the final round of the for-loop)
    if (ns < np) {
        // print message of deadlock among processes not processed
        printf("Deadlock among processes:");
        for (int i = 0; i < np; i++) {
            if (!done[i]) {
                printf(" p%d ", i);
            }
        }
        printf("\n");
    }

    printf("\n");
    
    return;
}
//******************************************************************
void quit_program() {

    printf("\nQuitting program...\n");

    // check if vectors/array are not NULL--if so, free each vector/array );
    if (resource != NULL) {
        free(resource);
    }

    free(available);
    
    return;

}
//*************************************************************
int main() {

    // declare local vars
    int input = 0;

    while (input != 3) { // while user has not chosen to quit
        // print menu of options
        printf("---------------------------------\n");
        printf("Banker's Algorithm\n");
        printf("---------------------------------\n");
        printf("Please choose from the following:\n");
        printf("1) Enter parameters\n");
        printf("2) Determine safe sequence\n");
        printf("3) Quit program and free memory\n");
        /* prompt for menu selection */
        printf("\nEnter selection: ");
        scanf("%d", &input);

        // call appropriate procedure based on choice
        //use switch statement or series of if, else if, else statements
        switch (input) {
            case 1: enter_params(); break;
            case 2: bankers_algo(); break;
            case 3: quit_program(); break;
            default: printf("Invalid entry, please try again...\n");
        }

    } // while loop

    return 1; // indicates success

} // end of procedure