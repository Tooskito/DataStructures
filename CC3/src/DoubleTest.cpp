#include <iostream>
#include "../include/DoubleHash.h"
int main()
{
    DoubleHash<int, int> d;
    d.insert( std::pair<int, int>{10, 10} );
    std::cout << d[5] << std::endl;
}