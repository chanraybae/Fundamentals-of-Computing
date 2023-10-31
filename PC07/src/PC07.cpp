/* Name: Chanwoo Ray Bae
 * Email: cbae@nd.edu
 * Date Created: 11/10/2021
 * File Contents: contains the main function, which reads in the file contents and evaluates
 * it for validity to determine if a string is actually a palindrome or not
 * Top level file for Programming Challenge 07
 */

#include "../inc/PC07.h"
#include<iostream>
#include<fstream>
#define STRING std::string
#define COUT std::cout
#define ENDL std::endl
#define IFSTREAM std::ifstream
#define OFSTREAM std::ofstream

int main( int argc, char** argv ){
	// Checking that the number of inputs is correct
	isValidTerminal(argc);
	// Opening the input file
	IFSTREAM inFile( argv[1] );
	// Checking that file exists
	if( !inFile ){
		COUT << argv[1] << " does not exist." << ENDL;
		exit(-1);
	}
	// Opening the output file as noted in project desc
	OFSTREAM outFile("output.txt");
	
	// String to be read in from file
	STRING s;
	// getline() function obtained from https://eng.libretexts.org/Courses/Delta_College/C___Programming_I_(McClanahan)/11%3A_C_Input_and_Output/11.02%3A_C_Input-_getline()
	while( getline( inFile, s ) ){
		bool palindrome = is_permutation( s );
		printOut( s, palindrome, outFile );
	}

	// closing the files after all is done
	inFile.close();
	outFile.close();

	return 1;
}

