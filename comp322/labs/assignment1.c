#include <stdio.h>
#include <stdlib.h>

/* The program creates/destroys child processes based on choosing from a menu of choices, where
each choice calls the appropriate procedure, where the choices are:
1) Enter parameters
2) Create a new child process
3) Destroy all descendants of a process
4) Quit program and free memory */

/* Define structures and global variables */
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
}*pcb_array = null;

typedef struct pcb pcb_type;

/***************************************************************/

void print_pcbs() {
    /* declare local vars */
    int i;

    /* for each PCB index i from 0 up to (but not including) maximum number*/
    for (i = 0; i < n; i++) {

        /* check if PCB[i] has a parent and children */
        if (pcb_array[i].parent > -1) {

            /* print message about children of the current PCB[i] */

            /* intilize variable to head of list of 
            children */
                while () { /* while the end of the linked list of children is not reached */ 
                /* print message about current child 
                process index */
                /* move to next node in linked list */
                } /* while */
            /* print newline */
        }/* if */
    } /* for */
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
        printf("Memory limit: process cannot be created.");
        printf("Destroy an existing process to create a new process.");
        return;
    }
    /* allocate memory for new child process, initilize fields */
    child = (list_type*)malloc(sizeof(ListNode));
    child -> process_id = i;
    child -> link = NULL;

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
        curr -> link = child;
    }
    /* call procedure to print current hierachy of processes */
    print_pcbs();
    return;
} /* end of procedure */

/***************************************************************/

void kill_process(parameter) {
    /* declare local vars */
    if () {
        /* check if end of linked list--if so return */
    } else {
        /* else call self on next node in linked list */
        /* set variable q to current node's process index field 
        */
        /* call self on children of PCB[q] */ 
        /* free memory of paramter */
        /* reset parent of PCB[q] to -1 */
        /* set paramter to NULL */
    } /* end of else */
    return;
} /* end of procedure */

/***************************************************************/

void destroy_descendants() {
    /* declare local vars */
    /* prompt for process index p */
    /* call recursive procedure to destroy children of PCB[p] */
    /* reset children of PCB[p] to NULL */
    /* call procedure to print current hierarchy of processes */
    return;
} /* end of procedure */

/***************************************************************/

void exit_program() {
    /* check if PCB is non null)
    /* check if children of PCB[0] is not null */
    /* call recursive procedure to destroy 
    children of PCB[0] */
    } /* if */
    /* free memory of PCB */
    } /* if */
    return;
} /* end of procedure */

/***************************************************************/

int main() {
    /* declare local vars */
    /* while user has not chosen to quit */
    /* print menu of options */
    /* prompt for menu selection */
    /* call appropriate procedure based on choice--use switch 
    statement or series of if, else if, else statements */
    } /* while loop */
    return 1; /* indicates success */
} /* end of procedure */