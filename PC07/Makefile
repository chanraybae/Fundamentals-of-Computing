# Name: Chanwoo Ray Bae
# Email: cbae@nd.edu
# Date Created: 11/10/2021
# File Name: Makefile
# File Contents: This is the Makefile which will determine how Programming Challenge 07 will be compiled

# G++ is for the GCC compiler for C++
PP := g++

# CXX FLAGS are the compiler flags for when we compile C++ code in this course
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := inc
SRC := src
EXE := exe
OBJ := obj

# Palindrome PC07 compilation

# PC07 compilation
$(OBJ)/PC07Func.o : $(SRC)/PC07Func.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/PC07Func.cpp -o $@

$(OBJ)/PC07.o : $(SRC)/PC07.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/PC07.cpp -o $@

# PC07 Objects
PC07_Objs := $(OBJ)/PC07.o $(OBJ)/PC07Func.o

# PC07 Executable
PC07 : $(PC07_Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/PC07 $(PC07_Objs)

# rw2bc compilation
#$(OBJ)/rw2bc.o: $(SRC)/rw2bc.cpp
#	$(PP) $(CXXFLAGS) -c $(SRC)/rw2bc.cpp -o $@

#rw2bc: $(OBJ)/rw2bc.o
#	$(PP) $(CXXFLAGS) -o $(EXE)/rw2bc $(OBJ)/rw2bc.o

# make initialize
initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)

# make all
all: PC07 rw2bc

# Make clean
clean:
	rm -rf *.o $(OBJ)/* $(EXE)/*


