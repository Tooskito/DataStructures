/**
 *  @author Jonathan Abbott
 *  @date   September 27th, 2020
 *  This file includes the tests for Prob2 in CC4 for CSE 20312.
 */

#include <iostream> // std::cout
#include "../include/Rain.h" // Rain::Trap

// Main driver function.
int main() {

    // Test one, from website.
    v_t TestOne_Vector{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << "-=-=- Test One -=-=-" << std::endl;
    std::cout << TestOne_Vector << std::endl;
    std::cout << "-=-=- Result -=-=-" << std::endl;
    std::cout << Rain::Trap(TestOne_Vector) << std::endl << std::endl;

    // Test two, two big buckets.
    v_t TestTwo_Vector{0, 4, 2, 2, 2, 4, 2, 2, 2, 2, 4, 0};
    std::cout << "-=-=- Test Two -=-=-" << std::endl;
    std::cout << TestTwo_Vector << std::endl;
    std::cout << "-=-=- Result -=-=-" << std::endl;
    std::cout << Rain::Trap(TestTwo_Vector) << std::endl << std::endl;

    // Test two, tall, descending slope.
    v_t TestThree_Vector{9, 7, 6, 7, 5, 3, 5, 4, 2, 1, 0, 1};
    std::cout << "-=-=- Test Three -=-=-" << std::endl;
    std::cout << TestThree_Vector << std::endl;
    std::cout << "-=-=- Result -=-=-" << std::endl;
    std::cout << Rain::Trap(TestThree_Vector) << std::endl;

    return 0;
}