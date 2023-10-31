/**********************
 Name: Chanwoo Ray Bae
 Email: cbae@nd.edu
 File Name: sllist.c
 Date Created: 9/23/2021
 File Contents: This file contains the function definitions for PC03
 Code Credit: Initial Framework for creating the sllist by Professor
 Morrison
***************************/
#include "../include/sllist.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

// Inserts the number of values user put inside the terminal
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

// Pushing back the values to create the initial list in order we desire
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
	
	// Running a while loop to insert a node at the back of the list
	// changed from initial framework
	while( reference->next_node ){
		reference = reference->next_node;
	}
	reference->next_node = insert_node;
	
}

// Print the Singly Linked List by looping through the sll
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

// Calls function in recursive method to input values in opposite order
void reverser( sllist* reversed, sll_node* prev, sll_node* curr ){
	// setting the previous to the current to go backwards		
	prev = curr;
	curr = prev->next_node;
	// recursion until curr reaches a null value
	if(curr){
		reverser(reversed, prev, curr);
	}
	
	push_back( reversed, prev->data );

}

// Frees all the elements to not cause a memory leak
void destructor( sll_node* curr_ptr ){
	
	// Dr. Morrison's Golden Rule of Pointers 
	if( curr_ptr == NULL )
		return;
	

	// Recursively call destructor on the next node  
	destructor( curr_ptr->next_node );
		
	// Free the current pointer 
	free( curr_ptr );
	
}

