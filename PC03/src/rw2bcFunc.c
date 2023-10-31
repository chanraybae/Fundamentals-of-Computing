/**********************
 Name: Chanwoo Ray Bae
 Email: cbae@nd.edu
 File Name: sllist.c
 Date Created: 9/23/2021
 File Contents: This file contains the function definitions for PC03
**************************/
#include "../include/rw2bcFunc.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

// Removes an nth element from the list
void rw2bc( sllist* the_list, int argc ){
	// Getting the index of the element wanted to be removed from the end
	int remElem;
	fprintf(stdout, "Provide the nth-element from the end: ");
	fscanf(stdin, "%d", &remElem);
	
	// If user tries to remove an element that does not exist, no element
	// will be removed
	if((remElem < 1) || (remElem > 5))
		return;

	// Calculating index value from the beginning instead of from the end
	int index = argc - remElem - 1;
	int counter = 0; // to detect which element we are on before skipping

	// Creating a reference node that points to the initial value
	sll_node* ref_node = the_list->head_node;
	
	// If index is zero, the list will simply be started at the one after
	// the initial value i.e. the original head node
	if(index == 0){
		the_list->head_node = ref_node->next_node;
		free( ref_node );
		return;
	}

	// Determines when to skip a node to not consider it i.e. the removed
	// element
	while(counter < index - 1){
		ref_node = ref_node->next_node;
		counter++;
	}
	// Skipping the removed element
	sll_node* new_node = ref_node->next_node;
	ref_node->next_node = new_node->next_node;

	// Freeing our allocated memory to ensure good practice 
	free( new_node );
}

void insert( sllist* the_list, int the_value ){
	
	// Create a sll_node pointer called insert_node
	sll_node* insert_node = (sll_node*)malloc( sizeof(sll_node) );
	
	// Set the insert_node's data to the_value and next_node to NULL 
	insert_node->data = the_value;
	insert_node->next_node = NULL;
	
	// Dr. Morrison's Golden Rule of Pointers 
	// Check if the list is empty
	if( the_list->head_node == NULL ){
		
		// Set the head node equal to insert_node 
		the_list->head_node = insert_node;
		
		// And return
		return;
	}
	
	// Otherwise, create a curr_ptr equal to the head_node 
	sll_node* curr_ptr = the_list->head_node;
	
	// Iterate until the next_node is NULL
	while( curr_ptr->next_node != NULL ){
		
		curr_ptr = curr_ptr->next_node;
	}
	
	// Set curr_ptr's next_node equal to insert_node
	curr_ptr->next_node = insert_node;
	
}

// Step 13 - Push Front 
void push_back( sllist* the_list, int the_value ){
	
	// 13 - 1 We can copy everything up through the empty head node from Insert 
	
	// Create a sll_node pointer called insert_node
	sll_node* insert_node = (sll_node*)malloc( sizeof(sll_node) );
	
	// Set the insert_node's data to the_value and next_node to NULL 
	insert_node->data = the_value;
	insert_node->next_node = NULL;
	
	// Dr. Morrison's Golden Rule of Pointers 
	// Check if the list is empty
	if( the_list->head_node == NULL ){
		
		// Set the head node equal to insert_node 
		the_list->head_node = insert_node;
		
		// And return
		return;
	}
	
	// 13-2 Now we just need to use a reference pointer and put them in front
	sll_node* reference = the_list->head_node;
	
	// Looping through and inserting the value at the back of the sll
	while( reference->next_node ){
		reference = reference->next_node;
	}
	reference->next_node = insert_node;

}

// Step 8 - Print the Singly Linked List 
void print_list( sll_node* head_node ){
	
	// We can just copy and paste from sllist_part2.c
	
	// Just change node_0 to head_node

	sll_node* curr_ptr = head_node;
	while( curr_ptr != NULL ){
		
		// Step 17 - Only print the value
		fprintf( stdout, "%d %p\n", curr_ptr->data, curr_ptr);		

		// Iterate through the next node
		curr_ptr = curr_ptr->next_node;

	}
	fprintf( stdout, "\n" );

}

// Free all the elements 
void destructor( sll_node* curr_ptr ){
	
	// Dr. Morrison's Golden Rule of Pointers 
	if( curr_ptr == NULL )
		return;
	

	// Recursively call destructor on the next node  
	destructor( curr_ptr->next_node );
		
	// Free the current pointer 
	free( curr_ptr );
	
}
