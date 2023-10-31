/******************************
 * Name: Chanwoo Ray Bae
 * Email: cbae@nd.edu
 * File Name: PC03.c
 * Date Created: 9/23/2021
 * File Contents: This file contains the main function for Programming
 * Challenge 03
 * Code Credit: Initial Framework of sllists attributed to Professor 
 * Morrison
 * ****************************/

#include "../include/sllist.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main( const int argc, const char* argv[] ){
	// if the only argument is the executable, no list can be returned
	if(argc == 1){
		fprintf(stdout, "Initial List:\n\n");
		fprintf(stdout, "Reversed List:\n\n");

		return 0;
	}

	// Step 4 - Dynamically allocate a sllist 
	sllist* the_list = (sllist *)malloc( sizeof( sllist ) );
	sllist* reversed = (sllist *)malloc( sizeof( sllist ) );

	// Step 4-1 - Set the head_node to NULL 
	the_list->head_node = NULL;
	reversed->head_node = NULL;
	
	// Calls push_back with as many as we want to insert using terminal
	int iter;
	for( iter = 1; iter < argc; ++iter ){
		
		int the_value = atoi( argv[iter] );
		// calls the push back to insert values from the user terminal run
		push_back( the_list, the_value );
		
	}	
	
	// We are going to iterate and print each value in the list
	printf("Initial List: \n");
	print_list( the_list->head_node );

	// Setting up the values for a reversed SLL and referencing rev func
	sll_node* prev = NULL;
	sll_node* curr = the_list->head_node;
	reverser(reversed, prev, curr);

	// Printing the final reversed list, calls the print function
	printf("Reversed List: \n");
	print_list( reversed->head_node );
	// Step 11 - Call the destructor to free the nodes
	destructor( the_list->head_node );
	destructor( reversed->head_node );
	
	// Step 5 - Free the sllist 
	free( the_list );
	free( reversed );

	return EXIT_SUCCESS;
}
