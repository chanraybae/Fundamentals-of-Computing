// Name: Chanwoo Ray Bae
// Email: cbae@nd.edu
// Date Created: 9/16/2021
// File Name: rotations.h
// File Contents: rotations.h contains the function declarations/prototypes for them to be
// defined in rotations.c and called in main.c

#ifndef ROTATIONS_H
#define ROTATIONS_H

#include<stdio.h>
#include<stdlib.h>

// Function declarations go here:
void printAddress( int* rotationsArray, long unsigned int n );
void leftRotation( int* rotationsArray, long unsigned int n, long unsigned int r);
void rightRotation( int* rotationsArray, long unsigned int n, long unsigned int r);
void freeRotations( int* rotationsArray, long unsigned int n);

#endif
