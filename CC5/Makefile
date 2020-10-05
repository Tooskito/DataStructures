# @author	Jonathan Abbott
# @date		October 2nd, 2020
#
# This is my Makefile for CC5 for CSE 20312, guided by Prof. Morrison.

# G++ is for the GCC compiler for C++
PP := g++

# CXXFLAGS are the compiler flages for when we compile C++ code in this course 
FLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror 
CXXFLAGS := -m64 -std=c++11 -Weffc++ $(FLAGS)

# Variables for Folders
INC := include
SRC := src
OBJ := obj
EXE := exe

# Command: make SorDLLTest
SorDLLTestObjs := $(OBJ)/SorDLLTest.o

SorDLLTest : $(SorDLLTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/SorDLLTest $(SorDLLTestObjs)
	$(EXE)/./SorDLLTest 5 10 12 6 7 1 0 3

$(OBJ)/SorDLLTest.o : $(SRC)/SorDLLTest.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/SorDLLTest.cpp -o $@

# Command: make PQTest
PQTestObjs := $(OBJ)/PQTest.o

PQTest : $(PQTestObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/PQTest $(PQTestObjs)
	$(EXE)/./PQTest

$(OBJ)/PQTest.o : $(SRC)/PQTest.cpp $(INC)/Priority.h
	$(PP) $(CXXFLAGS) -c $(SRC)/PQTest.cpp -o $@

# Command: make Creative
CreativeObjs := $(OBJ)/Creative.o

Creative : $(CreativeObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Creative $(CreativeObjs)
	$(EXE)/./Creative

$(OBJ)/Creative.o : $(SRC)/Creative.cpp
	$(PP) $(CXXFLAGS) -c $(SRC)/Creative.cpp -o $@

# Make all
all: SorDLLTest PQTest Creative

# Make Fundamental
Fundamental: SorDLLTest PQTest

# make initialize
initialize: 
	mkdir obj exe

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*