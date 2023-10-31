/*********************************
 * Name: Chanwoo Ray Bae
 * Date Created: 10/13/2021
 * Email: cbae@nd.edu
 * File Contents: this file contains the definition for
 * rw2bc.c
 * *******************************/

#include <vector>
#include <iostream>
#include <cmath>
#include <stdio.h>

#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector
#define MAX std::max

// printing array function from Prof Morrison's template
void printArray( VECTOR<int>& theArray ){
	
	COUT << "[";
    
	for(long unsigned int iter = 0; iter < theArray.size(); iter++){
 
    	COUT << theArray.at(iter);
 
        if( iter < theArray.size() - 1 ){  
			COUT << ",";
 		}
	}
 
	COUT << "]";
 
}

// finds the max amount of water area based on vertical line area
long unsigned int max_contained( VECTOR<int>& theArray ){

	// if the array number is 0, should default to holding no water
	if(theArray.size() == 0){
		return 0;
	}
	// setting the default to 0 anyways
	int waterArea = 0;
	// setting the front value to compare to the back most and parsing through
	int index = 0;
	int back = (int) theArray.size() - 1; // backmost, casting as the size is an unsigned int

	// while they don't cross
	while(index < back){
		// finds the max where the index of the back is >= front index 
		if(theArray[index] <= theArray[back]){
			waterArea = MAX(waterArea, (back - index) * theArray[index]);
			index++; // increments index to keep comparing while front increases
		}
		else{
			waterArea = MAX(waterArea, (back - index) * theArray[back]);
			back--; // decrements index to keep comparing, while the front stays
		}
	}
	
	return waterArea;

}

// main function inspired by prof morrison's max_subarray main function
int main( const int argc, const char* argv[] ){

    VECTOR<int> the_array;

    for( int iter = 1; iter < argc; ++iter ){
 
          int temp = atoi( argv[iter] );
 
          the_array.push_back( temp );
 
	}
	// prints the array for the user to view
	printArray(the_array);
 	COUT << ENDL;
	COUT << "maximum water solution = " << max_contained(the_array) << ENDL;


	return EXIT_SUCCESS;
}

