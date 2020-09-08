# @author	Jonathan Abbott
# @date		September 7th, 2020
#
# This Makefile includes the build commands for my `Lab4` assignment for CSE 20312.


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


##	Lab4
# 	Command: make Lab4
Lab4Objs := $(OBJ)/Lab4.o

Lab4: $(Lab4Objs)
	$(PP) $(PQCXX) -o $(EXE)/$@ $(Lab4Objs)
	$(EXE)/./$@

$(OBJ)/Lab4.o: $(SRC)/Lab4.cpp
	$(PP) $(PQCXX) -c $< -o $@


##	All/Clean
#	Command: make all/clean
.PHONY := all clean initialize
all: Lab4
initialize:
	mkdir $(OBJ) $(EXE)
clean:
	rm -rf $(OBJ)/* $(EXE)/*