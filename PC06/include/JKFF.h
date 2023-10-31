/* Name: Chanwoo Ray Bae
 * Email: cbae@nd.edu
 * Date Created: 10/28/2021
 * File Contents: JKFF.h contains the class declaration JKFF and a constructor for the JKFF src files which
 * contain the class definitions
 */

#ifndef JKFF_H
#define JKFF_H

#include <iostream>

class JKFF{
	private:
		bool varQ, varQbar;

	public:
		// Default constructor
		JKFF();
		// Overloaded constructor
		JKFF( bool varQ_in, bool varQbar_in );
		// Updating the values
		void updateVals( bool CLK, bool J_in, bool K_in ); 
		// functions to get the private values
		bool valueQ() const;
		bool valueQbar() const;

};

#endif
