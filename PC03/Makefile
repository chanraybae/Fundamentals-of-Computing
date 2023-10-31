# Name: Chanwoo Ray Bae
# Email: cbae@nd.edu
# File Name: Makefile
# Date Created 9/24/2021
# File Contents: This is the Makefile for the compilation of Programming Challenge 03

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
$(OBJ)/PC03.o: $(SRC)/PC03.c
	$(PP) $(CFLAGS) -c $(SRC)/PC03.c -o $@

# rw2bc main Object Files
$(OBJ)/rw2bc.o: $(SRC)/rw2bc.c
	$(PP) $(CFLAGS) -c $(SRC)/rw2bc.c -o $@

# Program Objs
PC03_objs := $(OBJ)/PC03.o $(OBJ)/sllist.o

# Program Objs
rw2bc_objs := $(OBJ)/rw2bc.o $(OBJ)/rw2bcFunc.o

# Initialize the folders for the objects and executables
initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)

# Create the Singly Linked List Object
$(OBJ)/sllist.o: $(SRC)/sllist.c
	$(PP) $(CFLAGS) -c $(SRC)/sllist.c -o $@

$(OBJ)/rw2bcFunc.o: $(SRC)/rw2bcFunc.c
	$(PP) $(CFLAGS) -c $(SRC)/rw2bcFunc.c -o $@

# Singly Linked List Executable and Run
PC03: $(PC03_objs)
	$(PP) $(CFLAGS) -o $(EXE)/PC03 $(PC03_objs)

rw2bc: $(rw2bc_objs)
	$(PP) $(CFLAGS) -o $(EXE)/rw2bc $(rw2bc_objs)

clean:
	rm -rf $(OBJ)/* $(EXE)/*
