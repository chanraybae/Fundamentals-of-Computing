# Name: Chanwoo Ray Bae
# Email: cbae@nd.edu
# File Name: Makefile
# Date Created: 09/08/2021
# File Contents: This is the Makefile for compilation of Programming Challenge 01

# gcc is for the GCC compiler for C
PP := gcc

# Production Quality Compiler Flags for C Programming in CSE 20312
CFLAGS := -O2 -g -Wall -Wextra -Wconversion -Wshadow -std=c11 -Werror -lm

# PC01 Object Files
PC01.o: PC01.c
	$(PP) $(CFLAGS) -c PC01.c

# Sudoku Object FIles
sudoku.o: sudoku.c
	$(PP) $(CFLAGS) -c sudoku.c

# PC01 Objs
PC01_objs := PC01.o sudoku.o

# PC01 Executable
PC01: $(PC01_objs)
	$(PP) $(CFLAGS) -o PC01 $(PC01_objs)

# Make all
#all: sudoku PC01
#	./sudoku
#	./PC01

# Cleaning the server from my stuff
clean:
	rm -rf *.o* PC01
