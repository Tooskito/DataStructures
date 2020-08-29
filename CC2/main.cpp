#include <iostream>
#include <vector>
#include <string>

#include "Quick.h"

int main() {


    // Test using an odd-length character vector.
    std::string OddCharString = "THECORONAVIRUSSUCKS";
    std::vector<char> OddCharVector(OddCharString.begin(), OddCharString.end());

    std::cout << "Initial is:\t";
    PrintVector(OddCharVector);

    std::cout << "Final is:\t";
    Quick::Sort(OddCharVector);
    PrintVector(OddCharVector);

    std::cout << std::endl;


    // Test using an odd-length integer vector.
    std::vector<int> IntVector{
        22, 13, 33, 44, -10, 55, 88, 27
    };

    std::cout << "Initial is:\t";
    PrintVector(IntVector);

    std::cout << "Final is:\t";
    Quick::Sort(IntVector);
    PrintVector(IntVector);

    std::cout << std::endl;


    // Test using an even-length unsigned integer vector.
    std::vector<unsigned int> UnsignedIntVector{
        14, 99, 42, 77, 2, 66, 1, 8, 44
    };

    std::cout << "Initial is:\t";
    PrintVector(UnsignedIntVector);

    std::cout << "Final is:\t";
    Quick::Sort(UnsignedIntVector);
    PrintVector(UnsignedIntVector);

    std::cout << std::endl;


    // Test using an even-length character vector.
    std::string EvenCharString = "Notre Dame";
    std::vector<char> EvenCharVector(EvenCharString.begin(), EvenCharString.end());

    std::cout << "Initial is:\t";
    PrintVector(EvenCharVector);

    std::cout << "Final is:\t";
    Quick::Sort(EvenCharVector);
    PrintVector(EvenCharVector);

    std::cout << std::endl;


    // Test using an odd-length string vector.
    std::vector<std::string> OddStringVector{
        "Data", "Structures", "Creativity", "Challenge", "2"
    };

    std::cout << "Initial is:\t";
    PrintVector(OddStringVector);

    std::cout << "Final is:\t";
    Quick::Sort(OddStringVector);
    PrintVector(OddStringVector);


    return 0;
}