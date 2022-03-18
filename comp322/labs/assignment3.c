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
        printf("\tr%d", resource[i]);
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
        printf("\tr%d", resource[i]);
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
        for (int j = 0; j < nr; j++) { //for each resource:
            // print maximum number of units each process may request from each resource
            printf("\t%d", maximum[i*nr+j]);
        }
    }

    printf("\n");

    return;

}

//*************************************************************

void print_allocated() {

    // declare local variables
    // for loop: print each resource index
    // for each process:
    // for each resource:
    // print number of units each process is allocated from each resource
    return;

}

//*************************************************************

void print_need() {

    // declare local variables
    // for loop: print each resource index
    // for each process:
    // for each resource:
    // print number of units each process needs from each resource
    return;

}

//**************************************************************

void enter_params() {

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
    printf("Enter number of units for resources (r0 to r%d): \n", nr);
    for (int j = 0; j < nr; j++) { // for each resource
        // set resource and available vectors indices
        scanf("%d", &units);
        resource[j] = units;
        available[j] = units;
    }
    
    for (int i = 0; i < np; i++) {// for each process
        // prompt for maximum number of units requested by process
        printf("Enter max units process p%d will request from each resource (r0 to r%d)", i, nr);

        for (int j = 0; j < nr; j++) {// for each resource
            //update maxclaim and need arrays
            scanf("%d", &units);
            maximum[i*nr+j] = units;
            need[i*nr+j] = units;
        }
        
    }
    // for each process, for each resource, prompt for number of resource units allocated to process
    for (int i = 0; i < np; i++) {// for each process
        // prompt for maximum number of units requested by process
        printf("Enter max units process p%d will request from each resource (r0 to r%d)", i, nr);
        for (int j = 0; j < nr; j++) {// for each resource
            //update maxclaim and need arrays
            scanf("%d", &units);
            allocated[i*nr+j] = units;
            [i*nr+j] = units;
        }
        
    }
    // print resource vector, available vector, maxclaim array, allocated array, need array
    return;
}
//******************************************************************
void bankers_algo() {
    // declare local variables, including vector to indicate if process is safely sequenced and "num_sequenced" count
    // while not all processes are processed
    // for each process
    // if process has not been processed yet 
    // print message comparing need vector with available vector
    // for each resource
    // check for safe processing by comparing process' need vector to available vector
        // if each resource is available
    // print message that process can be processed
    // update number of available units of resource
    // for each resourcefree all resources allocated to process
    // increment number of sequenced processes
    // else print message that process cannot be processed
    //if (no process was processed in the final round of the for-loop)
    // print message of deadlock among processes not processed
    return;
}
//******************************************************************
void quit_program() {
    // check if vectors/array are not NULL--if so, free each vector/array );
return;
}
//*************************************************************
int main() {
    // declare local vars
    while(0){// while user has not chosen to quit
        // print menu of options
        // prompt for menu selection
        // call appropriate procedure based on choice--use switch statement or series of if, else if, else statements 
    } // while loop
    return 1; // indicates success
} // end of procedure