/**********************************
 * Name: 
 * Email: 
 * File Name: PC01.c
 * Date Created: 
 * File Contents: Contains the main driver function
 *                for Programming Challenge 01
 **********************************/

#include "sudoku.h"
#define ROWS 9
#define COLS 9

int main( const int argc, const char* argv[] ){
	/* ensures that the argc variable is exactly two from the input */
	if(argc != 2){
		fprintf(stderr, "%s", "Invalid number of inputs!\n");
	}
	
	/* File input for main to read the text files given in the PC */
	FILE* puzzleFile = fopen(argv[1], "r");

	/* Initializing two-dimensional dynamic array by refference and allocates the memory
 	to defined variable*/
	int** sudoku = (int**)malloc( ROWS * sizeof( int * ));

	/* Calling the functions for the sudoku puzzle to function */
	malloc_puzzle( sudoku ); // iteration of array for allocation

	/* Step 6: Opening and freeing a file */
	FILE* input_file = fopen(argv[1], "r");

	/* References function that takes file and reads values into sudoku int** array */
	read_puzzle(sudoku, input_file);

	// Switch statement to get input from user 
	int userChoice = 0;
	printf("Please enter your number choice for playing the game\n");
	printf("1 - print the current puzzle\n");
	printf("2 - try to update a value in the puzzle\n");
	printf("4 - terminate the program\n");
	scanf("%d", &userChoice);
	while(userChoice != 4){
		switch(userChoice){
			case 1:	// choosing 1 prints the puzzle
				print_puzzle( sudoku );
				break;
			case 2: // attempts to update value based on input
				insert_and_check_puzzle( sudoku );
				break;
			case 4:	// terminates the program
				userChoice = 4;
				break;
			default:
				printf("You failed to enter a valid number from 1,2,4.\n");
		}
		// checking if puzzle is solved
		if((check_puzzle( sudoku )) == 1){
			break;
		}
		printf("Please enter your number choice for playing the game\n");
		printf("1 - print the current puzzle\n");
		printf("2 - try to update a value in the puzzle\n");
		printf("4 - terminate the program\n");
		scanf("%d", &userChoice);
	}
	// Freeing my allocation in server memory
	// Closing the puzzleFile itself at the end of main
	free_puzzle( sudoku ); // freeing the puzzle's 2D array
	fclose(puzzleFile);
	free( input_file );
	
	return 0;
}
