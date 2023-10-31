/**********************************
 * Name: Chanwoo Ray Bae 
 * Email: cbae@nd.edu
 * File Name: sudoku.c
 * Date Created: 09/08/2021
 * File Contents: This file contains the function definitions 
 *                for Programming Challenge 01
 **********************************/

#include "sudoku.h"
#define ROWS 9
#define COLS 9

/* Passes 2D dynamic array by reference and allocates the memory */
void malloc_puzzle( int ** sudoku ){
	long unsigned int allocatingIter = 0;
	for(allocatingIter = 0; allocatingIter < COLS; allocatingIter++){
		sudoku[ allocatingIter ] = (int *)malloc( COLS * sizeof( int ) );
	}	
}

/* Freeing the int array pointer and the 2D array itself via iteration */
void free_puzzle( int** sudoku ){
	long unsigned int freeingIter = 0;
	for(freeingIter = 0; freeingIter < COLS; freeingIter++){
		free( sudoku[ freeingIter ] );
	}
	// Freeing the 2D array itself
	free( sudoku );

}

void read_puzzle( int** sudoku, FILE* input_file){
	long unsigned int rowIn = 0;
	long unsigned int colIn = 0; 

	while(input_file != NULL){
		/* Getting int from input file */
		int temp;
		fscanf( input_file, "%d", &temp);

		/* Place int in the row and column of interest*/
		sudoku[ rowIn ][ colIn ] = temp;

		/* If colIn less than COLS - 1, increases colIn */
		if( colIn < COLS - 1){
			++colIn;
		}
		
		/* Elsewise incrementing rowIn and resetting value of colIn*/
		else{
			++rowIn;
			colIn = 0;
		}
		
		/* Breaking at the end of file */
		if(input_file->_IO_read_ptr == input_file->_IO_read_end){
			break;
		}
	}
}

/* prints the current values in the sudoku puzzle */
void print_puzzle( int** sudoku ){
	printf("\n"); // for visual ease, spacing out printed puzzle 

	long unsigned int rowIter = 0;
	long unsigned int colIter = 0;

	// Incrementing variable newline to put newline after 9 digits
	int newLine = 0;
	for(rowIter = 0; rowIter < ROWS; rowIter++){
		for(colIter = 0; colIter < COLS; colIter++){
			fprintf(stdout,"%d", sudoku[rowIter][colIter]);
			newLine++;
			if(newLine == 9){
				printf("\n");
				newLine = 0;
			}
		}	
	}
	printf("\n\n"); // two lines for better visual spacing
}

/* Checks if the sudoku puzzle no longer has any empty values */
unsigned int check_puzzle( int** sudoku ){
	long unsigned int rowIter = 0;
	long unsigned int colIter = 0;

	for(rowIter = 0; rowIter < ROWS; rowIter++){
		for(colIter = 0; colIter < COLS; colIter++){
			if(sudoku[rowIter][colIter] == 0){
				return 0;
			}
		}
	}
	
	return 1;	
}

/* Obtains values from user, then checks if it is a valid entryi, then inserts if it is so */
void insert_and_check_puzzle( int** sudoku ){
	int userEntry;
	long unsigned int userRow;
	long unsigned int userCol;

	printf("Please enter your number to enter, as well as the row (0-8) and column (0-8) number it will go in: \n");
	scanf("%d %lu %lu", &userEntry, &userRow, &userCol);
	printf("\n"); // new line for visual appeal

	// Invalid input if user enters a value not between 1 and 9, prints to stderr
	if( (userEntry < 1) || (userEntry > 9) ){
		fprintf(stderr, "%s", "Your input value is invalid (i.e. not 1-9)!");
	} 
	
	// Invalid input if row value is greater than 8, prints to stderr
	if(userRow > 8){
		fprintf(stderr, "%s", "You have selected a row value exceeding the bounds (8)");
	}
	
	// Invalid input if column value is greater than 8
	if(userCol > 8){
		fprintf(stderr, "%s", "You have selected a column value exceeding the bounds (8)");
	}

	// Traversing the row and column in accordance with sudoku rules in order to validate input
	long unsigned int rowIter = 0;
	long unsigned int colIter = 0;
	/* Keeps user's row constant and checks horizontal validity, returns without updating if invalid */
	for(rowIter = 0; rowIter < ROWS; rowIter++){
		if( userEntry == sudoku[rowIter][userCol]){
			printf("Value already exists in row.");
			return;
		}
	}
	/* Keeps user's col constant and checks vertical validity */
	for(colIter = 0; colIter < COLS; colIter++){
		if( userEntry == sudoku[userRow][colIter] ){
			printf("Value already exists in col.");
			return;
		}
	}
	/* Checks user's 3x3 box for value validity */
	long unsigned int setRow = 0; 
	long unsigned int setCol = 0;

	// Checking the range of the rows
	if( (userRow >= 1) && (userRow <= 3) ){
		setRow = 3;
	}
	else if( (userRow >= 4) && (userRow <= 6) ){
		setRow = 6;
	}
	else if( (userRow >= 7) && (userRow <= 9) ){
		setRow = 9;
	}
	// Checking the range of the columns
	if( (userCol >= 1) && (userCol <= 3) ){
                setCol = 3;
	}
	else if( (userCol >= 4) && (userCol <= 6) ){
		setCol = 6;
	}
	else if( (userCol >= 7) && (userCol <= 9) ){
		setCol = 9;
	}
	
	// Informing the user of the duplicate if present by looping inside the range
	for(rowIter = 0; rowIter <= setRow; rowIter++){
		for(colIter = colIter - 2; colIter <= setCol; colIter++){
			if(userEntry == sudoku[rowIter][colIter]){
				printf("Value already in box.");
				return;
			}
		}
	}
	
	// If it passes all these tests (does not return immediately), value is stored 
	sudoku[userRow][userCol] = userEntry;
}










