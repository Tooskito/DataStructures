/**
 *  @author Jonathan Abbott
 *  @date   Aug 31, 2020
 *  
 *  This file includes my driver program for `Lab3` for CSE 20312.
 */


#include <iostream> // std::cout
#include <string>   // std::string

#include "../include/Anagram.h" // AnagramTest


/**
 *  Main driver for `Lab3`.
 *  @return Operating system exit code.
 */
int main() {
    

    // Test #1 -> Two short words that are anagrams.
    std::cout << "-=-=- Test #1 - Two Short Anagrams -=-=-" << std::endl;
    std::string Test1_S = "rats";
    std::string Test1_T = "star";
    AnagramTest(Test1_S, Test1_T);
    std::cout << std::endl;


    // Test #2 -> Two short words that are not anagrams.
    std::cout << "-=-=- Test #2 - Two Short Non-Anagrams -=-=-" << std::endl;
    std::string Test2_S = "bruh";
    std::string Test2_T = "cake";
    AnagramTest(Test2_S, Test2_T);
    std::cout << std::endl;


    // Test #3 -> Two long words that are anagrams.
    std::cout << "-=-=- Test #3 - Two Long Anagrams -=-=-" << std::endl;
    std::string Test3_S = "thermonastically";
    std::string Test3_T = "hematocrystallin";
    AnagramTest(Test3_S, Test3_T);
    std::cout << std::endl;


    // Test #4 -> Two long words that are not anagrams.
    std::cout << "-=-=- Test #4 - Two Long Non-Anagrams -=-=-" << std::endl;
    std::string Test4_S = "bumfuzzle";
    std::string Test4_T = "borborygm";
    AnagramTest(Test4_S, Test4_T);
}