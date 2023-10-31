/* Name: Chanwoo Ray Bae
 * Email: cbae@nd.edu
 * Date Created: 11/10/2021
 * File Contents: PC07.h contains the function initialization/ 
 * declaration for Programming Challenge 07
 */

#ifndef PC07_H
#define PC07_H

#include<iostream>
#include<string>
#include<fstream>
#include<ctype.h>
#include<unordered_map>
#include<iterator>
#define STRING std::string
#define OFSTREAM std::ofstream

// validating terminal input
void isValidTerminal( int );

// Since we don't know if the valid input is in the file, we must check
bool isValidChar( char );

// Function that determines if a string s is a palindrome
bool is_permutation( STRING );

// printing the final output
void printOut( STRING, bool, OFSTREAM & );

#endif
