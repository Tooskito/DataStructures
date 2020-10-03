#include <iostream>
#include "../include/Priority.h"
#include "../include/SorDLList.h"

int main() {
    SorDLList<Priority<int>> myList;
    myList.Insert(Priority<int>(5, 1));
    myList.Insert(Priority<int>(10, 3));
    myList.Insert(Priority<int>(42, 2));
    myList.Insert(Priority<int>(100, 0));
    std::cout << myList << std::endl;
    return 0;
}