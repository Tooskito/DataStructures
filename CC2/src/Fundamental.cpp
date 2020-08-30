/**
 *  @author Jonathan Abbott
 *  @date   Aug 30, 2020
 *  
 *  This file includes the driver for the Fundamental portion of my CC2 for CSE 20312.
 */


#include <iostream> // std::cout
#include <vector>   // std::vector
#include <string>   // std::string

#include "../include/Quick.h"   // Quick::Sort


/**
 *  This is the main driver for my Fundamental portion of CC2, demonstrating 
 *  QuickSort.
 *  
 *  @return An exit code 0 for success. Otherwise, failure.
 */
int main() {



    // Test using an odd-length character vector.
    std::string OddCharString = "THECORONAVIRUSSUCKS";
    std::vector<char> OddCharVector(OddCharString.begin(), OddCharString.end());

    std::cout << "Initial is:\t";
    PrintVector(OddCharVector);

    Quick::Sort(OddCharVector);

    std::cout << "Final is:\t";
    PrintVector(OddCharVector);

    std::cout << std::endl;



    // Test using an odd-length integer vector.
    std::vector<int> IntVector{
        22, 13, 33, 44, -10, 55, 88, 27
    };

    std::cout << "Initial is:\t";
    PrintVector(IntVector);

    Quick::Sort(IntVector);

    std::cout << "Final is:\t";
    PrintVector(IntVector);

    std::cout << std::endl;



    // Test using an even-length unsigned integer vector.
    std::vector<unsigned int> UnsignedIntVector{
        14, 99, 42, 77, 2, 66, 1, 8, 44
    };

    std::cout << "Initial is:\t";
    PrintVector(UnsignedIntVector);

    Quick::Sort(UnsignedIntVector);

    std::cout << "Final is:\t";
    PrintVector(UnsignedIntVector);

    std::cout << std::endl;



    // Test using an even-length character vector.
    std::string EvenCharString = "Notre Dame";
    std::vector<char> EvenCharVector(EvenCharString.begin(), EvenCharString.end());

    std::cout << "Initial is:\t";
    PrintVector(EvenCharVector);

    Quick::Sort(EvenCharVector);

    std::cout << "Final is:\t";
    PrintVector(EvenCharVector);

    std::cout << std::endl;



    // Test using an odd-length string vector.
    std::vector<std::string> OddStringVector{
        "Data", "Structures", "Creativity", "Challenge", "2"
    };

    std::cout << "Initial is:\t";
    PrintVector(OddStringVector);

    Quick::Sort(OddStringVector);

    std::cout << "Final is:\t";
    PrintVector(OddStringVector);



    return 0;
}