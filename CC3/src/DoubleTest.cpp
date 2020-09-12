#include <iostream>
#include "../include/DoubleHash.h"
int main()
{
    // Create two tables, hash same three elements.
    HashTable<int, std::string> LinearTable;
    DoubleHash<int, std::string> DoubleTable;

    LinearTable.insert( std::pair<int, std::string>{76, "\"First\""} );
    LinearTable.insert( std::pair<int, std::string>{40, "\"Second\""} );
    LinearTable.insert( std::pair<int, std::string>{48, "\"Third\""} );
 
    DoubleTable.insert( std::pair<int, std::string>{76, "\"First\""} );
    DoubleTable.insert( std::pair<int, std::string>{40, "\"Second\""} );
    DoubleTable.insert( std::pair<int, std::string>{48, "\"Third\""} );
    
    std::cout << LinearTable << std::endl;
    std::cout << DoubleTable << std::endl;
    std::cout << std::endl;


    // Hash two more elements.
    LinearTable.insert( std::pair<int, std::string>{5, "\"Fourth\""} );
    LinearTable.insert( std::pair<int, std::string>{55, "\"Fifth\""} );
 
    DoubleTable.insert( std::pair<int, std::string>{5, "\"Fourth\""} );
    DoubleTable.insert( std::pair<int, std::string>{55, "\"Fifth\""} );

    std::cout << LinearTable << std::endl;
    std::cout << DoubleTable << std::endl;
    std::cout << std::endl;


    // Hash two more elements.
    LinearTable.insert( std::pair<int, std::string>{10, "\"Sixth\""} );
    LinearTable.insert( std::pair<int, std::string>{18, "\"Seventh\""} );
 
    DoubleTable.insert( std::pair<int, std::string>{10, "\"Sixth\""} );
    DoubleTable.insert( std::pair<int, std::string>{18, "\"Seventh\""} );

    std::cout << LinearTable << std::endl;
    std::cout << DoubleTable << std::endl;
    std::cout << std::endl;


    // Hash two more elements.
    LinearTable.insert( std::pair<int, std::string>{44, "\"Eighth\""} );
    LinearTable.insert( std::pair<int, std::string>{64, "\"Ninth\""} );
 
    DoubleTable.insert( std::pair<int, std::string>{44, "\"Eighth\""} );
    DoubleTable.insert( std::pair<int, std::string>{64, "\"Ninth\""} );

    std::cout << LinearTable << std::endl;
    std::cout << DoubleTable << std::endl;
    std::cout << std::endl;


    // Return success.
    return EXIT_SUCCESS;
}