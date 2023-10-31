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

#include "../include/rw2bcFunc.h"
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

	// Set the head_node to NULL 
	the_list->head_node = NULL;
		
	// Call push_back with as many as we want to insert
	int iter;
	for( iter = 1; iter < argc; ++iter ){
		
		int the_value = atoi( argv[iter] );
		// for a initial list printout
		push_back( the_list, the_value );
		
	}	
	
	// We are going to iterate and print each value in the list
	printf("Initial List: \n");
	// Printing the initial list
	print_list( the_list->head_node );

	// Referring to the rw2bc function that removes an nth element from end
	rw2bc( the_list, argc );
	printf("\nFinal List: \n");
	// Printing the final list
	print_list( the_list->head_node );

	// Call the destructor
	destructor( the_list->head_node );

	// Free the sllist 
	free( the_list );

	return EXIT_SUCCESS;
}
