/* Name: Chanwoo Ray Bae
 * Email: cbae@nd.edu
 * Date Created: 10/30/2021
 * File Contents: the BDC_Test file contains the main function and the read in of the file 
 * as a top-level file for the BDC portion of Programming Challenge 06
 */

#include "../include/BDC.h"
#define COUT std::cout
#define ENDL std::endl
#define IFSTREAM std::ifstream

// basically same thing as the JKFF
void readFile( IFSTREAM& file, BDC& bdcIn );

int main( int argc, char** argv ){
	BDC bdcIn;

	// Testing to see if the correct number of inputs exists
	if( argc != 2 ){
		COUT << "Incorrect number of inputs" << ENDL;
		exit(-1);
	}

	// Creating stream for input file
	IFSTREAM file( argv[1] );

	// Validating the file's existence
	if( !file ){
		COUT << argv[1] << " does not exist" << ENDL;
		exit(-1);
	}

	// Printing out the values subsequent;y to the user terminal
	COUT << "Initial value in main: " << bdcIn << ENDL;
	readFile( file, bdcIn );
	COUT << "Final value in main: " << bdcIn << ENDL;
	file.close();

	return 0;
}

// function definition for reading each file's inputs
void readFile( IFSTREAM& file, BDC& bdcIn ){
	bool CLK;
	bool upDown;

	while( !file.eof() ){
		file >> CLK;
		file >> upDown;
		bdcIn.count( CLK, upDown );
		COUT << bdcIn << ENDL;
	}
}
