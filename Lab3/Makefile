# @author	Jonathan Abbott
# @date		Aug 31, 2020
#
# This Makefile includes the build commands for my `Lab3` assignment for CSE 20312.


## 
# g++ is the compiler I will use for C++.
PP := g++

# Flags given by instructor, Prof. Morrison, for code compilation.
PQCFLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
PQCXX    := -m64 -std=c++11 -Weffc++ $(PQCFLAGS)

# Separate source from generated files via these path constants.
INC := include
SRC := src
OBJ := obj
EXE := exe


##	Fundamental
# 	Command: make Fundamental
Lab3Objs := $(OBJ)/Lab3.o

Lab3: $(Lab3Objs)
	$(PP) $(PQCXX) -o $(EXE)/$@ $(Lab3Objs)
	$(EXE)/./$@

$(OBJ)/Lab3.o: $(SRC)/Lab3.cpp
	$(PP) $(PQCXX) -c $< -o $@


##	All/Clean
#	Command: make all/clean
.PHONY := all clean initialize
all: Lab3
initialize:
	mkdir $(OBJ) $(EXE)
clean:
	rm -rf $(OBJ)/* $(EXE)/*