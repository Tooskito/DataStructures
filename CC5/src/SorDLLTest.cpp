// @author      Jonathan Abbott
// @date        Oct 4th, 2020
// @desc        This file implements the tests for `SorDLLTest<T>`, taken from Prof. Morrison.


#include <iostream> // std::cout, std::endl
#include "../include/SorDLList.h" // SorDLList<T>


int check(const char* argv) {
    for (int i = 0; i < argv[i]; ++i) {
        if (i == 0 and (argv[i] < 48 or argv[i] > 57) and argv[i] != 45) {
            std::cerr << "Invalid input: " << argv << std::endl;
            exit(EXIT_FAILURE);
        } else if (i > 0 and (argv[i] < 48 or argv[i] > 57)) {
            std::cerr << "Invalid input: " << argv << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    return atoi(argv);
}


int main(int argc, char** argv) {

    // If there are no integer arguments...
    if (argc < 2) {
        std::cerr << "At least one integer is required" << std::endl;
        exit(EXIT_FAILURE);
    }

    /* Add integer arguments, after verifying that they are valid, to SorDLList. */
    int len = argc - 1;
    SorDLList<int> list;

    for (int i = 1; i < len; ++i) {
        int temp = check(argv[i]);
        std::cout << "Inserting " << temp << " into Linked List" << std::endl;
        list.Insert(temp);
        std::cout << "list: " << list << std::endl;
    }
    

    /* Query user until they deletes all values. */
    int num;
    while (not list.IsEmpty()) {
        std::cout << std::endl << "Enter a value to be deleted: ";
        std::cin >> num;
        list.Delete(num);
        std::cout << "list: " << list << std::endl;
    }


    return 0;
}
