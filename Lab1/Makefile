#	Author: Jonathan Abbott
#	Date:	Tue, Aug 18, 2020
#
#	This is my Makefile for Lab1.


# g++ is the compiler I will use for C++.
PP := g++

# Flags given by instructor, Prof. Morrison, for code compilation.
FLAGS := -O0 -g -Wall
CXXFLAGS := -m64 -std=c++11 $(FLAGS)
PQCFLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
PQCXX    := -m64 -std=c++11 -Weffc++ $(PQCFLAGS)


##	Common
#	This object file is common to all Lab1 sub-questions.
Lab1.o: Lab1.cpp
	$(PP) $(CXXFLAGS) -c Lab1.cpp


##	Lab1a
#	Command: make Lab1a
Lab1aObjs := Lab1.o Lab1a.o

Lab1a: $(Lab1aObjs)
	$(PP) $(CXXFLAGS) $^ -o $@
	./$@


##	Lab1b
#	Command: make Lab1b
Lab1bObjs := Lab1.o Lab1b.o

Lab1b: $(Lab1bObjs)
	$(PP) $(PQCXX) $^ -o $@
	./$@


##	Lab1c
#	Command: make Lab1c
Lab1cObjs := Lab1.o Lab1c.o

Lab1c: $(Lab1cObjs)
	$(PP) $(PQCXX) $^ -o $@
	./$@


##	Phony Targets
#	To avoid problems with non-file targets "all" and "clean".
.PHONY: clean all
all: Lab1a Lab1b Lab1c
clean:
	rm -rf ./*.o
	rm -rf Lab1a Lab1b Lab1c