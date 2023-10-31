/* Name: Chanwoo Ray Bae
 * Email: cbae@nd.edu
 * Date Created: 11/10/2021
 * File Contents: PC07Func.cpp contains the function definitions and the resources
 * PC07.cpp needs to operate its file inputs and their respective outputs
 */

#include "../inc/PC07.h"
#include<iostream>
#include<fstream>
#define STRING std::string
#define COUT std::cout
#define ENDL std::endl
#define IFSTREAM std::ifstream
#define OFSTREAM std::ofstream

// Validating the number of arguments
void isValidTerminal( int argc ){
	if( argc != 2){
		COUT << "Incorrect number of inputs." << ENDL << "Please make sure you have a file." << ENDL;
		exit(-1);
	}
}

// We want to ignore whitespace; therefore, we are
// using ASCII table comparisons to verify that the characters are valid
bool isValidChar( char input ){
	if( ( input >= 'A' && input <= 'Z') || ( input >= 'a' && input <= 'z' ) ){
		return true;
	}
	// assuming numbers can also be in the string
	if( ( input >= '0' && input <= '9' ) ){
		return true;
	}
	
	return false;
}

// formula to determine if palindrome
bool is_permutation( STRING s ){
    // hash table to store frequency of characters
	std::unordered_map<char, int> countChars;

    // enumerating the appearance of characters in string
	for( long unsigned int i = 0; i < s.length(); i++ ){	
		// taking in character of interest from our string input
		char ofInterest = s[i];
	
		// only going through if not whitespace or punctuation
		if( isValidChar( ofInterest ) ){
			// making the characters lowercase, as palindromes exist regardless of case
            if( isupper(ofInterest) ){ 
				ofInterest = char( tolower( ofInterest ) ); // casting so the flags take a chill pill
			}
			// incrementing the count of the char count in using the key in hash table 
            countChars[ofInterest]++;
		}
	}

    // count of odd numbered letters, since only one is allowed
    int countOdd = 0;
    
	// Credit: Auto loop inspired by https://runestone.academy/runestone/books/published/cpp4python/CollectionData/HashTables.html's article guide about Hash Tables
    for( auto key = countChars.begin(); key != countChars.end(); key++ ){
    // seeing the count if even using mod, 1 should be the remainder
		if( key->second % 2 == 1 )
            countOdd++;
    }

    // should return true if the number of odd letters is only 1 or less, since the middle character
	// should be the only one that can be odd
    if( countOdd <= 1 )
		return true;

	// if more than 1 odd, then there can be no symmetry
	return false;
}

// printing out in the PC07 format
void printOut(STRING s, bool palindrome, OFSTREAM &output){
	if( palindrome == true ){
		output << "\"" << s << "\"" << " is a palindromic permutation" << ENDL;
	}
	else{
		output << "\"" << s << "\"" <<" is not a palindromic permutation" << ENDL;
	}
}
