#include <stdio.h>
#include <stdlib.h>

// declare global variables including linked list of blocks
// containing id, starting address, ending address, link to next node in list
int mem_size, remaining;
struct node {
    int id, start, end;
    struct node* link;
}* head = NULL;

typedef struct node block_type;

//********************************************************************

void enter_params() {

	// declare/initialize local variables
	// prompt for size of physical memory
	printf("Enter size of memory: \n");
    scanf("%d", &mem_size);

	// initilize remaining memory to size of physical memory
	remaining = mem_size;

	// allocate memory for linked list of blocks
	head = (block_type *)malloc(sizeof(block_type));

	// create "dummy" block with id -1, staring/ending address of 0 and link of NULL
	head->id = -1;
	head->start = 0;
	head->end = 0;
	head->link = NULL;

	return;

}

/********************************************************************/

void print_blocks() {

	// declare/initialize local variables
	block_type* curr = head->link; 

	// print header of table containing fields: ID, Start, End
	printf("ID\tStart\tEnd\n");
	printf("---------------\n");

	// print each block in list with while-loop, loop until end of list, advancing "current block" pointer
	while(curr != NULL) {
		printf("%d\t%d\t%d\n", curr->id, curr->start, curr->end);
		curr = curr->link;
	}

	return;

}

/********************************************************************/

void first_fit() {

	// declare/initialize local variables
	int block_id, block_size;
	int hole_start, hole_end, hole_size;
	block_type* curr = head;
	block_type* new_block;

	// prompt for block id & block size
	printf("Enter block ID: \n");
    scanf("%d", &block_id);
	printf("Enter size of block: \n");
    scanf("%d", &block_size);

	// if block size is larger than remaining memory, print message, return
	if (block_size > remaining) {
		printf("Error: Block size is larger than available memory.\n");
		return;
	}

	// allocate memory for new block, set block id
	new_block = (block_type *)malloc(sizeof(block_type));
	new_block->id = block_id;

	// if block list is "empty", set fields for new block, link to block list, reduce remaining memory, return
	if (head->link == NULL) {
		new_block->start = head->end;
		new_block->end = new_block->start + block_size;
		new_block->link = NULL;
		head->link = new_block;
		remaining -= block_size;
		return;
	}

	// while not end of list, loop
	while (curr != NULL) {
		//if duplicate id, print message, return
		if (block_id == curr->id) {
			printf("Error: Duplicate block ID\n");
			free(new_block);
			return;
		}
		curr = curr->link;
	}

	curr = head;
	while (curr != NULL) {
		//set values for start and end of current hole
		hole_start = curr->end;

		if (curr->link != NULL) {
			hole_end = curr->link->start;
		} else {
			hole_end = mem_size;
		}

		hole_size = hole_end - hole_start;

		// if block fits in hole
		if (block_size <= hole_size) {
			// set fields for new block, link to block list, reduce remaining memory, return
			new_block->start = hole_start;
			new_block->end = hole_start + block_size;
			new_block->link = curr->link;
			curr->link = new_block;
			remaining -= block_size;
			
			print_blocks();
			return;
		}
		
		// advance "current block" pointer
		curr = curr->link;

	}
	
	// if end of list reached, print message no fitting hole
	printf("Error: Not enough memory available.\n");
	free(new_block);
	
	print_blocks();
  	return;

}

/***************************************************************/

void best_fit() {

	// declare/initialize local variables
	int block_id, block_size;
	int hole_start, hole_end, hole_size;
	block_type* curr;
	block_type* new_block; 
	block_type* best_block;
	int fit_found = 0, best_hole = mem_size, best_start;

	// prompt for block id & block size
	printf("Enter block ID: \n");
    scanf("%d", &block_id);
	printf("Enter size of block: \n");
    scanf("%d", &block_size);

	// if block size is larger than remaining memory, print message, return
	if (block_size > remaining) {
		printf("Error: Block size is larger than available memory.\n");
		return;
	}

	// allocate memory for new block, set block id
	new_block = (block_type *)malloc(sizeof(block_type));
	new_block->id = block_id;

	// if block list is "empty", set fields for new block, link to block list, reduce remaining memory, return
	if (head->link == NULL) {
		new_block->start = head->end;
		new_block->end = new_block->start + block_size;
		new_block->link = NULL;
		head->link = new_block;
		remaining -= block_size;
		return;
	}

	// initialize "current block" to compare hole
	curr = head;

	// while not end of list, loop
	while (curr != NULL) {
		//if duplicate id, print message, returnxt_block = block_list;
		if (block_id == curr->id) {
			printf("Error: Duplicate block ID\n");
			free(new_block);
			return;
		}

 		//set values for start and end of current hole
		hole_start = curr->end;

		if (curr->link != NULL) {
			hole_end = curr->link->start;
		} else {
			hole_end = mem_size;
		}

		hole_size = hole_end - hole_start;
		
		// if block fits in hole, 
		if (block_size <= hole_size) { 
			//set flag "at least one" fitting hole found
			fit_found = 1;
			// if current hole is smaller than best so far
			if (hole_size < best_hole) {
				// set new value for "best so far", "best start", copy "best block" to current block
				best_hole = hole_size;
				best_start = hole_start;
				best_block = curr;
			}
		}
					
		//advance "current block" pointer
		curr = curr->link;
	}

	// if no hole was found large enough, print message, return
	if (fit_found == 0) {
		printf("Error: Not enough memory available.\n");
		return;
	}

	// set fields for new block, link to block list, reduce remaining memory
	new_block->start = best_start;
	new_block->end = best_start + block_size;
	new_block->link = best_block->link;
	best_block->link = new_block;
	remaining -= block_size;

	print_blocks();
	return;

}

/********************************************************************/

void deallocate() {

	// declare/initialize local variables
	int block_id, found = 0;
	block_type* curr;
	block_type* prev;

	// prompt for block id
	printf("Enter block ID: \n");
    scanf("%d", &block_id);

	// initialize "current block"
	curr = head;

	// while id not found and end of block list not reached
	while ( (curr != NULL) && (block_id != curr->id) ) {
		// advance "previous block" pointer and "current block" pointer
		prev = curr;
		curr = curr->link;
	}
	
	// if "current block" is NULL, print message id not found
	if (curr == NULL) printf("Error: ID not found.\n");
	// else
	
	// remove block, adjusting "previous block" pointer around it,
	prev->link = curr->link;
	//increment remaining memory with block size, 
	remaining += curr->end - curr->start;
	// free block with matching id
	free(curr);
	
	print_blocks();
	return;

}

/********************************************************************/

void defrag_mem() {

	// declare/initialize local variables
	// initialize "current block"
	block_type* curr = head;

	// while end of block list not reached
	while (curr->link != NULL) {
		// adjust start and end fields of each block, compacting together
		int newStart = curr->end;
		int newEnd = curr->link->end - (curr->link->start - curr->end);
		curr->link->start = newStart;
		curr->link->end = newEnd; 
		curr = curr->link;
	}

	print_blocks();
	return;

}

//******************************************************************

void quit_program(block_type *node) {

	// if node is NULL return
	if (node == NULL) return;
	else { // else call self on link field of node, free node
		quit_program(node->link);
		free(node);
	}
    
    return;

}

//*************************************************************

int main() {

	// declare local vars
    int input = 0;

    while (input != 6) { // while user has not chosen to quit
        // print menu of options
        printf("---------------------------------\n");
        printf("Memory Allocation\n");
        printf("---------------------------------\n");
        printf("Please choose from the following:\n");
        printf("1) Enter parameters\n");
		printf("2) Allocate memory for a block using First-Fit\n"); 
		printf("3) Allocate memory for a block using Best-Fit\n");
		printf("4) Deallocate memory for a block\n");
		printf("5) Defragment memory\n");
		printf("6) Quit program and free memory\n");
        /* prompt for menu selection */
        printf("\nEnter selection: \n");
        scanf("%d", &input);

        // call appropriate procedure based on choice
        //use switch statement or series of if, else if, else statements
        switch (input) {
            case 1: enter_params(); break;
            case 2: first_fit(); break;
            case 3: best_fit(); break;
			case 4: deallocate(); break;
			case 5: defrag_mem(); break;
			case 6: printf("\nQuitting program...\n"); quit_program(head); break;
            default: printf("Invalid entry, please try again...\n");
        }

    } // while loop

	return 1; // indicates success 

} // end of procedure 