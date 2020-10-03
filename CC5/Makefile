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


# Command: make Fundamental
FundamentalObjs := $(OBJ)/Fundamental.o

Fundamental : $(FundamentalObjs)
	$(PP) $(CXXFLAGS) -o $(EXE)/Fundamental $(FundamentalObjs)
	$(EXE)/./Fundamental

$(OBJ)/Fundamental.o : $(SRC)/Fundamental.cpp $(INC)/Priority.h
	$(PP) $(CXXFLAGS) -c $(SRC)/Fundamental.cpp -o $@

# Make all
all: Fundamental


# make initialize
initialize: 
	mkdir obj exe

# Make clean
clean :
	rm -rf *.o $(OBJ)/* $(EXE)/*