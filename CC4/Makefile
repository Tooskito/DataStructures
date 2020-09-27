# @author	Jonathan Abbott
# @date		September 27th, 2020
#
# This is my Makefile for CC4 for CSE 20312, guided by Prof. Morrison.

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


# Command: make Prob1
Prob2Objs := $(OBJ)/Prob2.o

Prob2 : $(Prob2Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob2 $(Prob2Objs)
	$(EXE)/./Prob2

$(OBJ)/Prob2.o : $(SRC)/Prob2.cpp $(INC)/Rain.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob2.cpp -o $@


# Command: make Prob1
Prob1Objs := $(OBJ)/Prob1.o

Prob1 : $(Prob1Objs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Prob1 $(Prob1Objs)
	$(EXE)/./Prob1

$(OBJ)/Prob1.o : $(SRC)/Prob1.cpp $(INC)/Flow.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Prob1.cpp -o $@

# Make all
all: Prob1 Prob2


# make initialize
initialize: 
	mkdir obj exe

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*