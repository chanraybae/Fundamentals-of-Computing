/*****************************
 * Name: Chanwoo Ray Bae
 * Email: cbae@nd.edu
 * File NAme: sllist.h
 * Date Created: 9/23/2021
 * File Contents: This file contains the function definitions for PC03
 * **************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct sll_node{
	int data;
	struct sll_node* next_node;
}sll_node;

typedef struct sllist{

	struct sll_node* head_node;
}sllist;

// Creating the function prototypes
void rw2bc( sllist* the_list, int argc);

void insert( sllist* the_list, int the_value );

void push_back( sllist* the_list, int the_value );

void print_list( sll_node* head_node );

void destructor( sll_node* curr_ptr );

