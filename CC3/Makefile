# @author 	Jonathan Abbott
# @date		Sep 13, 2020
# 
# This is my makefile for the fundamental and creative portions for CC3 for CSE 20312.

# The compiler we will use.
CC := g++

# The flags we are required to use.
CCFLAGS := -std=c++11 -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm \
           -m64 -Weffc++


# Define some directories.
INC := include
SRC := src
OBJ := obj
EXE := exe


##	Fundamental
# Command: make Fundamental
FundamentalObjs := $(OBJ)/DoubleTest.o

Fundamental : $(FundamentalObjs)
	$(CC) $(CCFLAGS) $(FundamentalObjs) -o $(EXE)/$@
	$(EXE)/./$@

$(OBJ)/DoubleTest.o : $(SRC)/DoubleTest.cpp
	$(CC) $(CCFLAGS) -c $< -o $@


##	Creative
# Command: make Creative
CreativeObjs := $(OBJ)/Creative.o

Creative : $(CreativeObjs)
	$(CC) $(CCFLAGS) $(CreativeObjs) -o $(EXE)/$@
	$(EXE)/./$@

$(OBJ)/Creative.o : $(SRC)/Creative.cpp
	$(CC) $(CCFLAGS) -c $< -o $@


##	Phonies
# Command: make all/clean/initialize
.PHONY : all clean initialize

all : Fundamental Creative

clean :
	rm -rf $(OBJ)/* $(EXE)/*

initialize :
	mkdir $(OBJ) $(EXE)