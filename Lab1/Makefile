
PP := g++

FLAGS := -O0 -g -Wall
CXXFLAGS := -m64 -std=c++11 $(FLAGS)
PQCFLAGS := -O0 -g -Wall -Wextra -Wconversion -Wshadow -pedantic -Werror -lm
PQCXX    := -m64 -std=c++11 -Weffc++ $(PQCFLAGS)

##
#
Lab1.o: Lab1.cpp
	$(PP) $(CXXFLAGS) -c Lab1.cpp

##
#
Lab1aObjs := Lab1.o Lab1a.o

Lab1a: $(Lab1aObjs)
	$(PP) $(CXXFLAGS) $^ -o $@
	./$@

##
#
.PHONY: clean
clean:
	rm -rf ./*.o
	rm -rf Lab1a