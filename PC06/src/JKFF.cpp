/* Name: Chanwoo Ray Bae
 * Email: cbae@nd.edu
 * Date Created: 10/30/2021
 * File Contents: This file contains JKFF.cpp, which contains the function
 * definitions from the header file's declarations
*/

#include "../include/JKFF.h"

// Default constructor that initializes Q ro 0 and Q to 1
JKFF::JKFF() : varQ(0), varQbar(1) {}

// Overloaded constructor
JKFF::JKFF( bool varQ_in, bool varQbar_in) : varQ(varQ_in), varQbar(varQbar_in ) {}

// Determining value of Q
bool JKFF::valueQ() const{
	return varQ;
}

// Determining value of Q bar
bool JKFF::valueQbar() const{
	return varQbar;
}

// Updating the values 
void JKFF::updateVals( bool CLK, bool J_in, bool K_in ){
	// Condition 1: when clock is 0, the values do not change
	if(CLK == 0)
		return;
	
	// The other conditions based on the table
	else if((J_in == 0) && (K_in == 0)){
		return;
	}

	else if((J_in == 0) && (K_in == 1)){
		varQ = 0;
		varQbar = 1;
	}

	else if((J_in == 1) && (K_in == 0)){
		varQ = 1;
		varQbar = 0;
	}
	// switching values
	else if((J_in == 1) && (K_in == 1)){
		bool tempVarQ = varQ;
		varQ = varQbar;
		varQbar = tempVarQ;
	}

	return;
}

