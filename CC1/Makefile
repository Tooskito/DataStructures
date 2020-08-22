# g++ is the compiler I will use for C++.
PP := g++

# Flags given by instructor, Prof. Morrison, for code compilation.
FLAGS := -O0 -g -Wall
CXXFLAGS := -m64 -std=c++11 $(FLAGS)
PQCFLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
PQCXX    := -m64 -std=c++11 -Weffc++ $(PQCFLAGS)

#	Fundamental
#	Command: make Fundamental
FundamentalObjs := Fundamental.o Pascal.o

Fundamental: $(FundamentalObjs)
	$(PP) $(PQCXX) $^ -o $@
	./$@
Fundamental.o: Fundamental.cpp
	$(PP) $(PQCXX) -c $< -o $@
Pascal.o: Pascal.cpp
	$(PP) $(PQCXX) -c $< -o $@

.PHONY := clean
clean:
	rm -rf *.o
	rm -rf Fundamental