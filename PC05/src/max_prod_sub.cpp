/************************
 * Name: Chanwoo Ray Bae
 * Date Created: 10/13/2021
 * CSE 20312
 * File Contents: this file contains the function definition
 * for max_prod_sub that will compute the final output
 * Email: cbae@nd.edu
 * *********************/


#include <vector>
#include <iostream>

#define COUT std::cout
#define ENDL std::endl
#define VECTOR std::vector

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

// finding max product of the subarray, inspired by max_subarray_dyn by Prof Morrison  
int max_prod_sub( VECTOR<int>& theArray ) {
	// Condition if there are no values, by default 0
	if(theArray.size() == 0){
		return 0;
	}
	// Condition if there is only the first value, the maximum is just going to be the first val
	if(theArray.size() == 1){
		return theArray.at(0);
	}
	
	int currMax = theArray.at(0);
	int globalMax = theArray.at(0);

	for(unsigned int iter = 1; iter < theArray.size(); iter++){
		// Getting the intermediate product
		int prod = theArray.at(iter) * currMax;

		// Selecting the current Max using ternary conditional
		currMax = (prod > theArray.at(iter)) ? prod : theArray.at(iter);

		// Updating global max if greater than previous stored
		globalMax = ( currMax > globalMax ) ? currMax : globalMax;
	}

	return globalMax;
}


int main( const int argc, const char* argv[] ){
	
	VECTOR<int> the_array;
	
	for( int iter = 1; iter < argc; ++iter ){
		
		int temp = atoi( argv[iter] );
		
		the_array.push_back( temp );
		
	}	
	
	printArray(the_array);
	COUT << ENDL;
	COUT << "Max Product Subarray Solution = " << max_prod_sub(the_array) << ENDL;
	
	return EXIT_SUCCESS;
}

