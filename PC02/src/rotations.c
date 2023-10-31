// Name: Chanwoo Ray Bae
// Email: cbae@nd.edu
// File Name: rotations.c
// Date Created: 9/16/2021
// File Contents; rotations.c contains all the function definitions that will be called by the main function, which
// were originally declared in the rotations.h file for Programming Challenge 02

/* This function displays the addresses of each value in the array */
#include<stdio.h>
#include<stdlib.h>
#include "../include/rotations.h"

/* Displaying the address of each value when called */
void printAddress( int* rotationsArray, long unsigned int n ){
	long unsigned int i;
	for( i = 0; i < n; i++ ){
		printf("%d at %p\n", rotationsArray[i], &rotationsArray[i]);
	}
}

/* Rotating formula if user types L in the beginning */
void leftRotation( int* rotationsArray, long unsigned int n, long unsigned int r){
	long unsigned int iter;
	int* tempArr = (int *)malloc( n * sizeof(int) );
	int* invArr = (int *)malloc( n * sizeof(int) );
	// Inversing array to apply right hand formula to get left
	for( iter = 0; iter < n; iter++){
		invArr[n - 1 - iter] = rotationsArray[iter];
	}
	// applying modulo to find new index, then inserting it into the temp array	
	for( iter = 0; iter < n; iter++){
		long unsigned int newIndex = (iter + r) % n;
		tempArr[newIndex] = invArr[iter];
	}
	// inversing array, as unsigned ints cannot have negatives calculated right
	for( iter = 0; iter < n; iter++){
		invArr[n - 1 - iter] = tempArr[iter];
	}

	// Assigning back new rotated and inversed array to the original to have left rot
	for( iter = 0; iter < n; iter++){
		rotationsArray[iter] = invArr[iter];
	}
	
	// Freeing the arrays used in this problem
	free( tempArr );
	free( invArr );
}

/* Rotating if user types R in the beginning */
void rightRotation( int* rotationsArray, long unsigned int n, long unsigned int r){
	long unsigned int iter;
	int* tempArr = (int *)malloc( n * sizeof(int) );
	for( iter = 0; iter < n; iter++ ){
		long unsigned int newIndex = (iter + r) % n;
		tempArr[newIndex] = rotationsArray[iter];
	}
	// Assigning back new rotated array to the original
	for( iter = 0; iter < n; iter++){
		rotationsArray[iter] = tempArr[iter];
	}
	// Freeing the memory of the arrays used in this problem
	free( tempArr );
}
