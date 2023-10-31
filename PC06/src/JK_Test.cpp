/* Name: Chanwoo Ray Bae
 * Email: cbae@nd.edu
 * Date Created: 10/28/2021
 * File Contents: JK_Test.cpp is the upper most file, containing the read in and
 * the main function for the JKFF Programming Challenge 06 Problem
 */

#include "../include/JKFF.h"
#include <iostream>
#include <fstream>
#define STRING std::string
#define COUT std::cout
#define ENDL std:: endl
#define IFSTREAM std::ifstream

// This function will read the file in
void readFile(IFSTREAM& file, JKFF& flipFlop);

int main( int argc, char** argv ){
	JKFF flipFlop;

	// Ensuring the number of inputs is correct
	if( argc != 2 ){
		COUT << "Incorrect number of inputs" << ENDL;
		exit(-1);
	}

	// stream for input
	IFSTREAM file(argv[1]);

	// Checking if the file exists
	if( !file ){
		COUT << argv[1] << " does not exist" << ENDL;
		exit(-1);
	}

	// Reading the file 
	readFile(file, flipFlop);

	// Closing the file after read
	file.close();

	return 0;
}

// taking in the inputs from the file function definition
void readFile( IFSTREAM& file, JKFF& flipFlop ){
	bool CLK, J_in, K_in;

	// Reads in every number into variable until the file ends
	while( !file.eof() ){
		file >> CLK;
		file >> J_in;
		file >> K_in;
		flipFlop.updateVals( CLK, J_in, K_in );
		COUT << flipFlop.valueQ() << " " << flipFlop.valueQbar() << ENDL;
	}
}
