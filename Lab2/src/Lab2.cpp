#include <iostream>
#include <vector>

#include "../include/functions.h"

int main(int arc, char ** argv) {
    std::vector<int> MyVec;
    MyVec.push_back(0);
    MyVec.push_back(1);
    MyVec.push_back(2);
    MyVec.push_back(3);
    MyVec.push_back(4);
    MyVec.push_back(5);
    MyVec.push_back(7);
    MyVec.push_back(9);
    MyVec.push_back(10);
    MyVec.push_back(18);
    MyVec.push_back(101);
    PrintVector(MyVec);
    std::cout << LongestIncreasingSubsequence(MyVec) << std::endl;
    return 0;
}