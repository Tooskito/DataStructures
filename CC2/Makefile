# @author	Jonathan Abbott
# @date		Aug 30, 2020
#
# This Makefile includes the build commands for my `CC2` assignment for CSE 20312.

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
FundamentalObjs := $(OBJ)/Fundamental.o

Fundamental: $(FundamentalObjs)
	$(PP) $(PQCXX) -o $(EXE)/$@ $(FundamentalObjs)
	$(EXE)/./$@

$(OBJ)/Fundamental.o: $(SRC)/Fundamental.cpp
	$(PP) $(PQCXX) -c $< -o $@


##	Fundamental
# 	Command: make Fundamental
CreativeObjs := $(OBJ)/Creative.o

Creative: $(CreativeObjs)
	$(PP) $(PQCXX) -o $(EXE)/$@ $(CreativeObjs)
	$(EXE)/./$@

$(OBJ)/Creative.o: $(SRC)/Creative.cpp
	$(PP) $(PQCXX) -c $< -o $@


##	All/Clean
#	Command: make all/clean
.PHONY := all clean initialize
all: Fundamental Creative
initialize:
	mkdir $(OBJ) $(EXE)
clean:
	rm -rf $(OBJ)/* $(EXE)/*