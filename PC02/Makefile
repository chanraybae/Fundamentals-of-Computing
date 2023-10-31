# Name: Chanwoo Ray Bae
# Email: cbae@nd.edu
# File Name: Makefile
# Date Created 9/15/2021
# File Contents: This is the Makefile for the compilation of Programming Challenge 02

# gcc is for the GCC compiler for C
PP := gcc

# Production Quality Compiler Flags for C Programming in CSE 20312
FLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -std=c11 -Werror -lm
CFLAGS := -std=c11 $(FLAGS)

# Folder Variables
SRC := src
INC := include
OBJ := objects
EXE := exe

# NOTE: Please do "make PC01" to compile all

# main Object Files
$(OBJ)/main.o: $(SRC)/main.c
	$(PP) $(CFLAGS) -c $(SRC)/main.c -o $@

# Program Objs
main_objs := $(OBJ)/main.o $(OBJ)/rotations.o

# main executable
main: $(main_objs)
	$(PP) $(CFLAGS) -o main $(main_objs)

# Initialize the folders for the objects and executables
initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)

# Create the Singly Linked List Object
$(OBJ)/rotations.o: $(SRC)/rotations.c
	$(PP) $(CFLAGS) -c $(SRC)/rotations.c -o $@

# Singly Linked List Objects
rotations_objs := $(OBJ)/rotations.o $(OBJ)/main.o

# Singly Linked List Executable and Run
PC02: $(rotations_objs)
	$(PP) $(CFLAGS) -o $(EXE)/rotations $(rotations_objs)

clean:
	rm -rf $(OBJ)/* $(EXE)/*
