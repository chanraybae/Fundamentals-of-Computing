# Name: Chanwoo Ray Bae
# Email: cbae@nd.edu
# Date Created: 10/28/2021
# File Name: Makefil
# File Contents: This is the Makefile which will determine how Programming Challenge
# 06 will be compiled

# G++ is for the GCC compiler for C++
PP := g++

# CXX FLAGS are the compiler flags for when we compile C++ code in this course
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := include
SRC := src
EXE := exe
OBJ := obj

# command to make JK_Test
#JKTest: $(JKTestObjs)
#	$(PP) $(CXXFLAGS) -o $(EXE)/JKTest $(JKTestObjs)
#	$(EXE)/./JKTest

#JK Test Compilation

$(OBJ)/JK_Test.o: $(SRC)/JK_Test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/JK_Test.cpp -o $@

$(OBJ)/JKFF.o: $(SRC)/JKFF.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/JKFF.cpp -o $@

# JKFF Objects
JKFF_Objs := $(OBJ)/JKFF.o $(OBJ)/JK_Test.o

# JKFF Executable
JK_Test : $(JKFF_Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/JK_Test $(JKFF_Objs)


# BDC class compilation
$(OBJ)/BDC_Test.o : $(SRC)/BDC_Test.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/BDC_Test.cpp -o $@

$(OBJ)/BDC.o : $(SRC)/BDC.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/BDC.cpp -o $@

# BDC Objects
BDC_Objs := $(OBJ)/JKFF.o $(OBJ)/BDC.o $(OBJ)/BDC_Test.o

# BDC Executable
BDC_Test : $(BDC_Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/BDC_Test $(BDC_Objs)

# rw2bc compilation
$(OBJ)/rw2bc.o: $(SRC)/rw2bc.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/rw2bc.cpp -o $@

rw2bc: $(OBJ)/rw2bc.o
	$(PP) $(CXXFLAGS) -o $(EXE)/rw2bc $(OBJ)/rw2bc.o

# make initialize
initialize:
	rm -rf $(OBJ) $(EXE)
	mkdir $(OBJ) $(EXE)

# make all
all: JK_Test BDC_Test rw2bc

# Make clean
clean:
	rm -rf *.o $(OBJ)/* $(EXE)/*


