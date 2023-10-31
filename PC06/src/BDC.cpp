/* Name: Chanwoo Ray bae
 * Email: cbae@nd.edu
 * Date Created: 10/28/2021
 * File Contents; This file contains the function definitions in BDC.h
 */

#include "../include/BDC.h"

AND::AND(): A(0), B(0) {}

bool AND::calc_and( bool A_in, bool B_in ){
	A = A_in;
	B = B_in;
	
	return A && B;
}

bool AND::get_and() const{
	return A && B;
}

OR::OR(): A(0), B(0) {}

bool OR::calc_or( bool A_in, bool B_in ){
	A = A_in;
	B = B_in;
	return A || B;
}

bool OR::get_or() const{
	return A || B;
}

NOT::NOT(): A(0) {}

bool NOT::calc_not( bool A_in ){
	A = A_in;
	return !A;
}

bool NOT::get_not() const{
	return !A;
}

BDC::BDC() : JK0(), JK1(), JK2(), JK3() {}

void BDC::count( bool clk, bool upDown ){
	JK0.updateVals( clk, 1, 1 );
	
	NOT not_0;
	not_0.calc_not( upDown );

	AND and_0;
	and_0.calc_and( not_0.get_not(), JK0.valueQbar() );

	AND and_1;
	and_1.calc_and( upDown, JK0.valueQ() );

	OR or_0;
	or_0.calc_or( and_0.get_and(), and_1.get_and() );

	JK1.updateVals( clk, or_0.get_or(), or_0.get_or() );

	AND and_2;
	and_2.calc_and( and_0.get_and(), JK1.valueQbar() );

	AND and_3;
	and_3.calc_and( and_1.get_and(), JK1.valueQ() );

	OR or_1;
	or_1.calc_or(and_2.get_and(), and_3.get_and() );

	JK2.updateVals( clk, or_1.get_or(), or_1.get_or() );

	AND and_4;
	and_4.calc_and( and_2.get_and(), JK2.valueQbar() );

	AND and_5;
	and_5.calc_and( and_3.get_and(), JK2.valueQ() );

	OR or_2;
	or_2.calc_or(and_4.get_and(), and_5.get_and() );

	JK3.updateVals( clk, or_2.get_or(), or_2.get_or() );
}

unsigned int BDC::get_value() const{
	return 8 * JK3.valueQ() + 4 * JK2.valueQ() + 2 * JK1.valueQ() + 1 * JK0.valueQ();
}

std::ostream& operator<<( std::ostream& out, const BDC& printBDC ){
	out << printBDC.JK3.valueQ() << " " << printBDC.JK2.valueQ() << " " << printBDC.JK1.valueQ() << " " << printBDC.JK0.valueQ() << " " << printBDC.get_value();

	return out;
}







