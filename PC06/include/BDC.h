/* Name: Chanwoo Ray Bae
 * Email: cbae@nd.edu
 * Date Created: 10/28/2021
 * File Contents: this file contains the function and constructors 
 * declarations for Programming Challenge 06
 */

#ifndef BDC_H
#define BDC_H
#include<iostream>
#include<fstream>
#include "JKFF.h"

struct AND {
	private: 
		bool A, B;

	public:
		AND();
		bool calc_and( bool A_in, bool B_in );
		bool get_and() const;
};

struct OR {
	private:
		bool A, B;

	public: 
		OR();
		bool calc_or( bool A_in, bool B_in );
		bool get_or() const;
};

struct NOT {
	private:
		bool A;

	public:
		NOT();
		bool calc_not( bool A_in );
		bool get_not() const;
};

class BDC {
	private:
		JKFF JK0;
		JKFF JK1;
		JKFF JK2;
		JKFF JK3;
		unsigned int get_value() const;
	
	public:
		BDC();
		void count( bool clk, bool upDown );
		friend std::ostream& operator<<( std::ostream& out, const BDC& print_BDC );
};

#endif
