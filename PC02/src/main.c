/*******************************
 * Name: Chanwoo Ray Bae
 * Email: cbae@nd.edu
 * File Name: main.c
 * Date Created: 9/16/2021
 * File Contents: Contains the main driver function for Programming Challenge 02
 ******************************/

#include "../include/rotations.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(){
	long unsigned int n;
	long unsigned int r;
	char d;
	int cont = 1;

	// Creating the array of interest from the user
	printf("\nPlease enter the size, num rotations, and direction: \n");
	fscanf(stdin, "%lu %lu %c", &n, &r, &d);
	int* rotationsArray = (int *)malloc( n * sizeof(int) );
	// Prompting users to enter values into the array
	printf("Please input the %lu values: \n", n);

	while(cont == 1){
		// making the lettercase standardized to be capitalized if not
		d = toupper(d);

		// storing these values into the array
		long unsigned int iter;
		for( iter = 0; iter < n; iter++ ){
			scanf("%d", &rotationsArray[iter]);
		}

		/* Calling the function to display the values' addresses */
		printf("Before rotation: \n");
		printAddress(rotationsArray, n);

		/* Calling the function to rotate the values */
		if(d == 'L')
			leftRotation(rotationsArray, n, r);	
		else if(d == 'R')
			rightRotation(rotationsArray, n, r);

		/* Calling function to display value addresses after rot */
		printf("After rotation\n");
		printAddress(rotationsArray, n);

		/* Asking what user wants next, including more rotations or quitting */
		char yn;
		printf("Do you wish to continue? (y/n): ");
		fscanf(stdin, " %c", &yn);
		
		if(yn == 'n'){ // user elects to quit if 'n'
			cont = 0;
			free( rotationsArray );
			return 0;
		}
		if(yn == 'y'){
			printf("\nPlease enter the size, num rotations, and direction: \n");
			fscanf(stdin, "%lu %lu %c", &n, &r, &d);
			printf("Please input the %lu values: \n", n);
		}
	}	
	// frees memory from Our Lady's servers
	free( rotationsArray );
	
	return 0;
}
