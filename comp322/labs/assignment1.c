#include <stdio.h>
#include <stdlib.h>
/*
David McNeary
COMP 322L Section 7799
Assignment #1
2/21/2022

The program creates/destroys child processes based on choosing from a menu of choices, where
each choice calls the appropriate procedure, where the choices are:
1) Enter parameters
2) Create a new child process
3) Destroy all descendants of a process
4) Quit program and free memory 
*/

/***************************************************************/

/* Define structures and global variables */
int n;
int initialized = 0;

struct node {
    int process_id;
    struct node* link;
};

typedef struct node list_type;

//pcb_array points to the first element in an array of PCBs
struct pcb {
    int parent;
    list_type* children;
}*pcb_array = NULL;

typedef struct pcb pcb_type;

/***************************************************************/

int check_init() {

    if (initialized == 0) {
        printf("Program not initialized - please choose option 1 on main menu\n");
        return 0;
    } else return 1;

}

void print_pcbs() {

    /* declare local vars */
    int i;
    list_type* child;

    /* for each PCB index i from 0 up to (but not including) maximum number*/
    for (i = 0; i < n; i++) {
        /* check if PCB[i] has a parent and children */
        if ( (pcb_array[i].parent > -1) && (&pcb_array[i] != NULL) ) {
            /* print message about children of the current PCB[i] */
            /* initialize variable to head of list of children */
            child = pcb_array[i].children;
            printf("Process %d\n", i);
            printf("--Children:\n");
            /* while the end of the linked list of children is not reached */ 
            while (child != NULL) { 
                /* print message about current child process index */
                printf("\tProcess %d", child->process_id);
                /* move to next node in linked list */
                child = child->link;
            } /* while */

            /* print newline */
            printf("\n");
        }/* if */
    } /* for */

    return;

} /* end of procedure */

/***************************************************************/

void input_params() {

    /* declare local vars */
    int i;

    /* prompt for maximum number of processes */
    printf("Enter maximum number of processes: ");
    scanf("%d", &n);

    /* allocate memory for dynamic array of PCBs */
    pcb_array = (pcb_type*)malloc(n * sizeof(pcb_type));

    /* Define PCB[0] */
    pcb_array[0].parent = 0;
    pcb_array[0].children = NULL;
    initialized = 1;

    /* for-loop to intitialize all other indices' parent to -1 */
    for (i = 1; i < n; i++) {
        pcb_array[i].parent = -1;
        pcb_array[i].children = NULL;
    }

    printf("New 1st ancestor created - process 0\n");
    printf("Memory remaining: %d\n", n - 1);

    return;

} /* end of procedure */

/***************************************************************/

void create_child() {

    if (check_init() == 0) return; 

    /* define local vars */
    int p;
    int i = 1;
    list_type* child;
    list_type* curr;

    /* prompt for parent process index p */
    printf("Enter the parent process ID: ");
    scanf("%d", &p);

    /* search for first available index q without a parent in a while 
    loop */
    while ( (i < n) && (pcb_array[i].parent != -1) ) {
        i++;
    }
    if (i == n) {
        printf("Memory limit: process cannot be created.\n");
        printf("Destroy an existing process to create a new process.\n");
        return;
    }
    /* allocate memory for new child process, initilize fields */
    child = (list_type*)malloc(sizeof(list_type));
    child->process_id = i;
    child->link = NULL;

    /* record the parent's index p in PCB[q] */
    pcb_array[i].parent = p;

    /* initialize the list of children of PCB[q] as empty */
    /* create a new link containing the child's index q and append the 
    link to the end of the linked list of PCB[p] */
    if (pcb_array[p].children == NULL) {
        pcb_array[p].children = child;
    } else {
        curr = pcb_array[p].children;

        while(curr->link != NULL) {
            curr = curr->link;
        }
        curr->link = child;
    }
    /* call procedure to print current hierachy of processes */
    printf("New process created: Process %d (parent: Process %d)\n", i, p);
    printf("Memory remaining: %d\n", n - i - 1);
    print_pcbs();
    return;
} /* end of procedure */

/***************************************************************/

void kill_process(list_type* node) {

    /* declare local vars */
    int q;

    /* check if end of linked list--if so return */
    if (node == NULL) {
        return;
    } else {
        /* else call self on next node in linked list */
        kill_process(node->link);

        /* set variable q to current node's process index field */
        q = node->process_id;
        
        /* call self on children of PCB[q] */
        kill_process(pcb_array[q].children);
        printf("Destroying process %d\n", q);

        /* free memory of parameter */
        free(node);

        /* reset parent of PCB[q] to -1 */
        pcb_array[q].parent = -1;

        /* set parameter to NULL */
        node = NULL;
    } /* end of else */

    return;

} /* end of procedure */

/***************************************************************/

void destroy_descendants() {

    if (check_init() == 0) return; 
    
    /* declare local vars */
    int p;

    /* prompt for parent process index p */
    printf("Enter the parent process ID: ");
    scanf("%d", &p);

    if (p < 0 || p > n) {
        printf("Invalid process ID!");
        return;
    }

    /* call recursive procedure to destroy children of PCB[p] */
    kill_process(pcb_array[p].children);

    /* reset children of PCB[p] to NULL */
    pcb_array[p].children = NULL;

    /* call procedure to print current hierarchy of processes */
    print_pcbs();

    printf("Finished destroying processes.\n");
    return;

} /* end of procedure */

/***************************************************************/

void exit_program() {

    /* check if PCB is non null) */
    if (pcb_array == NULL) {
        return;
    } else {
        /* check if children of PCB[0] is not null */
        /* call recursive procedure to destroy children of PCB[0] */
        kill_process(pcb_array[0].children);
        /* free memory of PCB */
        free(pcb_array);
        printf("Process 0 destroyed.\n");
    } /* if */
    
    printf("Exiting program...");

    return;

} /* end of procedure */

/***************************************************************/

int main() {

    /* declare local vars */
    int input = 0;

    /* while user has not chosen to quit */
    while (input != 4) {
        /* print menu of options */
        printf("\nPlease choose from the following:\n");
        printf("1) Enter parameters\n");
        printf("2) Create a new child process\n");
        printf("3) Destroy all descendants of a process\n");
        printf("4) Quit program and free memory\n");
        /* prompt for menu selection */
        printf("Enter selection: ");
        scanf("%d", &input);
        printf("\n");
        /* call appropriate procedure based on choice--use switch 
        statement or series of if, else if, else statements */
        switch (input) {
            case 1: input_params(); break;
            case 2: create_child(); break;
            case 3: destroy_descendants(); break;
            case 4: exit_program(); break;
            default: printf("Invalid entry, please try again...");
        }
    } /* while loop */

    return 1; /* indicates success */

} /* end of procedure */