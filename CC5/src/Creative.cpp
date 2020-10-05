// @author      Jonathan Abbott
// @date        Oct 4th, 2020
// @desc        This file implements the tests for my Huffman encoding implementation that uses a PriorityQueue.


#include <iostream> // std::cout, std::endl
#include <string> // std::string
#include "../include/Huffman.h" // Huffman::Encode


// Driver function for the tests for my Huffman encoding implementation.
int main() {


    std::string TestOne_String = "aaaaaaaaaaaaaaaaaaaabbbbb";
    std::string TestTwo_String = "According to all known laws of aviation, there is no way that a bee should be able to fly. Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyways. Because bees don't care what humans think is impossible.";


    std::cout << "********** TEST ONE - BASIC **********" << std::endl;
    Huffman::Encode(TestOne_String);


    std::cout << "********** TEST TWO - MOVIE QUOTE **********" << std::endl;
    Huffman::Encode(TestTwo_String);


    return 0;
}