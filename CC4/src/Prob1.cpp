/**
 *  @author Jonathan Abbott
 *  @date   September 27th, 2020
 *  This file includes the tests for Prob1 in CC4 for CSE 20312.
 */

#include <iostream> // std::cout
#include "../include/Flow.h" // Flow::PacificAtlantic

// Main driver function to test Prob1 solutions.
int main() { 
    
    // Test one, test from website.
    vv_t TestOne_Vector{
      {1, 3, 4, 3, 7},
      {2, 2, 3, 4, 4},
      {2, 4, 5, 3, 1},
      {6, 7, 5, 4, 5},
      {5, 1, 6, 2, 4},  
    };
    std::cout << "-=-=- Test One -=-=-" << std::endl;
    std::cout << TestOne_Vector << std::endl;
    std::cout << "-=-=- Result -=-=-" << std::endl;
    std::cout << Flow::PacificAtlantic(TestOne_Vector) << std::endl;

    // Test two, flow is a maze.
    vv_t TestTwo_Vector{
      {9, 9, 9, 9, 9, 9, 8},
      {1, 2, 3, 3, 4, 9, 7},
      {9, 9, 9, 9, 5, 9, 7},
      {9, 6, 6, 6, 5, 9, 7},
      {9, 7, 9, 9, 9, 9, 7},
      {8, 7, 8, 7, 7, 7, 7},
    };
    std::cout << "-=-=- Test Two -=-=-" << std::endl;
    std::cout << TestTwo_Vector << std::endl;
    std::cout << "-=-=- Result -=-=-" << std::endl;
    std::cout << Flow::PacificAtlantic(TestTwo_Vector) << std::endl;

    // Test three, no flow.
    vv_t TestThree_Vector{
      {5, 2, 1, 3, 7},
      {9, 7, 6, 8, 4},
      {5, 6, 2, 3, 6},
      {6, 7, 8, 9, 8},
      {5, 4, 2, 9, 3},  
    };
    std::cout << "-=-=- Test Three -=-=-" << std::endl;
    std::cout << TestThree_Vector << std::endl;
    std::cout << "-=-=- Result -=-=-" << std::endl;
    std::cout << Flow::PacificAtlantic(TestThree_Vector) << std::endl;

    return 0;
}
