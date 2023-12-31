/**********************************
 * Name: 
 * Email: 
 * File Name: sudoku.h
 * Date Created: 
 * File Contents: This file contains the function declarations  
 *                for Programming Challenge 01
 **********************************/

#ifndef SUDOKU_H
#define SUDOKU_H

#include <stdio.h>
#include <stdlib.h>

#define ROWS 9
#define COLS 9

void malloc_puzzle( int** sudoku );
void free_puzzle( int** sudoku );
void read_puzzle( int** sudoku, FILE* input_file);
void print_puzzle( int** sudoku);
unsigned int check_puzzle( int** sudoku);
void insert_and_check_puzzle( int** sudoku );

#endif
