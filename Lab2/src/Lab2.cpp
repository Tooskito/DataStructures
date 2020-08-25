/**
 *  @author Jonathan Abbott
 *  @date   Aug 25, 2020
 * 
 *  This file includes the `main` driver for Lab2, including the tests
 *  for finding the longest increasing subsequence in an array.
 */


#include <iostream>
#include <vector>
#include <string>

#include "../include/functions.h"


/**
 *  This is the `main` driver of the program.
 * 
 *  @return An integer exit code (i.e. 0 for success).
 */
int main() {


    // first test, test edge case.
    std::vector<int> EmptyVector;
    std::cout << "----------------------" << std::endl;
    std::cout << "Empty Array Test:" << std::endl;
    std::cout << "Array to Test for LIS\t: ";
    PrintVector(EmptyVector);
    std::cout << "Result: " << LongestIncreasingSubsequenceLength(EmptyVector) << std::endl;
    std::cout << "----------------------" << std::endl;


    // test normal signed integers. GIVEN #1
    std::vector<int> SignedTest{
        10, 9, 2, 5, 3, 7, 101, 18
    };
    std::cout << "Signed Integer Test:" << std::endl;
    std::cout << "Array to Test for LIS\t: ";
    PrintVector(SignedTest);
    std::cout << "Result: " << LongestIncreasingSubsequenceLength(SignedTest) << std::endl;
    std::cout << "----------------------" << std::endl;


    // test unsigned integers. GIVEN #2
    std::vector<unsigned int> UnsignedTest{
        10, 5, 8, 3, 9, 4, 12, 11
    };
    std::cout << "Unsigned Integer Test:" << std::endl;
    std::cout << "Array to Test for LIS\t: ";
    PrintVector(UnsignedTest);
    std::cout << "Result: " << LongestIncreasingSubsequenceLength(UnsignedTest) << std::endl;
    std::cout << "----------------------" << std::endl;


    // test characters. GIVEN #3
    std::vector<char> CharTest{
        'e', 'A', 'B', 'a', 'C', 'f', 'D', 'E'
    };
    std::cout << "ASCII Character Test" << std::endl;
    std::cout << "Array to Test for LIS\t: ";
    PrintVector(CharTest);
    std::cout << "Result: " << LongestIncreasingSubsequenceLength(CharTest) << std::endl;
    std::cout << "----------------------" << std::endl;


    // test string by passing string's properties to vector. CREATED #1 STRING
    std::string MyString = "The last thing you'd want in your Burger King burger is someone's foot fungus. But as it turns out, that might be what you get.";
    std::vector<char> StringTest(MyString.begin(), MyString.end());
    std::cout << "String Test:" << std::endl;
    std::cout << "Array to Test for LIS\t: ";
    PrintVector(StringTest, false);
    std::cout << "Result: " << LongestIncreasingSubsequenceLength(StringTest) << std::endl;
    std::cout << "----------------------" << std::endl;


    // test another set of unsigned integers. CREATED #2 UNSIGNED INT
    std::vector<unsigned int> SecondUnsignedTest{
        38, 26, 32, 41, 12, 7, 22, 19, 35, 37, 48, 7, 29, 11, 47, 30, 35, 22, 27, 24, 47, 34, 36, 0, 14
    };
    std::cout << "Second Unsigned Test:" << std::endl;
    std::cout << "Array to Test for LIS\t: ";
    PrintVector(SecondUnsignedTest);
    std::cout << "Result: " << LongestIncreasingSubsequenceLength(SecondUnsignedTest) << std::endl;
    std::cout << "----------------------" << std::endl;


    // EXIT_SUCCESS.
    return 0;
}