#include <stdio.h>
#include <stdlib.h>

/* The program creates/destroys child processes based on choosing from a menu of choices, where
each choice calls the appropriate procedure, where the choices are:
1) Enter parameters
2) Create a new child process
3) Destroy all descendants of a process
4) Quit program and free memory */

/* Define structures and global variables */

// TODO: main

int n;

struct node {
    int process_id;
    struct node* link;
}

typedef struct node list_type;

//pcb_array points to the first element in an array of PCBs
struct pcb {
    int parent;
    list_type* children;
}*pcb_array = NULL;

typedef struct pcb pcb_type;

/***************************************************************/

void print_pcbs() {
    /* declare local vars */
    int i;
    list_type* child;

    /* for each PCB index i from 0 up to (but not including) maximum number*/
    for (i = 0; i < n; i++) {

        /* check if PCB[i] has a parent and children */
        if ( (pcb_array[i].parent > -1) && (pcb_array[i] != NULL) ) {
            /* print message about children of the current PCB[i] */

            /* initialize variable to head of list of children */
            child = pcb_array[i].children;

            /* while the end of the linked list of children is not reached */ 
            while (child != NULL) { 
                /* print message about current child process index */
                printf("Process %d is the parent of Process %d\n", pcb_array[i].parent, child->process_id);
                
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

    /* for-loop to intitialize all other indices' parent to -1 */
    for (i = 1; i < n; i++) {
        pcb_array[i].parent = -1;
        pcb_array.children = NULL;
    }
    return;
} /* end of procedure */

/***************************************************************/

void create_child() {
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
    while (i < n && pcb_array[i].parent != -1) {
        i++;
    }
    if (i == n) {
        printf("Memory limit: process cannot be created.\n");
        printf("Destroy an existing process to create a new process.\n");
        return;
    }
    /* allocate memory for new child process, initilize fields */
    child = (list_type*)malloc(sizeof(ListNode));
    child->process_id = i;
    child->link = NULL;

    /* record the parent's index p in PCB[q] */
    pcb_array[q].parent = p;

    /* initialize the list of children of PCB[q] as empty */
    /* create a new link containing the child's index q and append the 
    link to the end of the linked list of PCB[p] */
    if (pcb_array[p].children == NULL) {
        pcb_array[p].children = child;
    } else {
        curr = pcb_array[p].children;

        while(curr.link != NULL) {
            curr = curr.link;
        }
        curr.link = child;
    }
    /* call procedure to print current hierachy of processes */
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
    /* declare local vars */
    int p;

    /* prompt for parent process index p */
    printf("Enter the parent process ID: ");
    scanf("%d", &p);

    /* call recursive procedure to destroy children of PCB[p] */
    kill_process(pcb_array[p].children);

    /* reset children of PCB[p] to NULL */
    pcb_array[p].children = NULL;

    /* call procedure to print current hierarchy of processes */
    print_pcbs();

    return;
} /* end of procedure */

/***************************************************************/

void exit_program() {
    /* check if PCB is non null) */
    if (pcb_array == NULL) {
        printf("Error: PCB array doesn't exist.\n");
        return;
    } else {
        /* check if children of PCB[0] is not null */
        /* call recursive procedure to destroy children of PCB[0] */
        kill_process(pcb_array[0].children);
        /* free memory of PCB */
        free(pcb_array);
        printf("Process 0 destroyed.\n");
    } /* if */

    return;
} /* end of procedure */

/***************************************************************/

int main() {
    /* declare local vars */
    int input = 0;

    /* while user has not chosen to quit */
    while (input != 4) {
        /* print menu of options */
        printf();
        /* prompt for menu selection */
        printf("Enter selection: ");
        scanf("%d", &input);
        /* call appropriate procedure based on choice--use switch 
        statement or series of if, else if, else statements */
        switch (input) {
            case 1:
            case 2:
            case 3:
            case 4:
            default: printf("Invalid entry, please try again...");
        }
    } /* while loop */

    return 1; /* indicates success */

} /* end of procedure */