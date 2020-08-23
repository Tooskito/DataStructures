/**
 *  @author Jonathan Abbott
 *  @date   Aug 23, 2020
 *  
 *  This `main` file demonstrates Pascal's Triangle functionality implemented
 *  in `Pascal.cpp` via user interaction.
 */

#include <iostream> // For I/O, i.e. std::cout.
#include "Pascal.h" // For Pascal's Triangle functionality.


/**
 *  The `main` driver of the program.
 *  @return exit code 0 for success or 1 for failure.
 */
int main() {


    // `PollHeight` will return FAILURE if input fails or `height` < 1 .
    unsigned int height;
    if ( PollHeight(height) != SUCCESS ) {
        std::cerr << "height is invalid" << std::endl;
        return FAILURE;
    }
    // otherwise, `height` is now >= 1.

    
    // `CreateTriangle` will return `nullptr` if there was overflow due to addition.
    unsigned int ** triangle;
    triangle = Pascal::CreateTriangle(height);
    if ( triangle == nullptr ) {
        std::cerr << "height too big. integer overflow" << std::endl;
        return FAILURE;
    }
    // otherwise, `triangle` now holds a multi-dimensional pointer.

    
    // we pass in `height` here because `PrintTriangle` has no idea how big our `triangle` is.
    Pascal::PrintTriangle(triangle, height);


    // `true` because we'll just break whenever the user doesn't input a 'y'.
    while ( true ) {


        // `PollIndex` will return FAILURE if input fails or input < 1.
        //      "Hint 1: You may assume that the user will not enter a 
        //       value less than 1, or an invalid integer" -CC1 Document
        unsigned int row, col;
        if ( PollIndex(row, col) != SUCCESS ) {
            std::cerr << "error reading input" << std::endl;
            return FAILURE;
        }
        // otherwise, `row` and `col` now hold a positive value.


        // `GetTriangleMember` returns FAILURE if `row` or `col` was out of range.
        unsigned int member;
        if ( Pascal::GetTriangleMember(triangle, height, row, col, member) == SUCCESS ) {
            std::cout << member << std::endl;
        }
        // otherwise, we just printed out the value at 1-indexed `row` and `col`.


        // `PollContinue` returns false if user didn't enter 'y' to continue.
        if ( not PollContinue() ) {
            break;
        }
    }


    // always make sure we free the dynamically allocated memory.
    Pascal::FreeTriangle(triangle, height);


    // and if we make it here, return exit code 0 for success.
    std::cout << "Exiting program..." << std::endl;
    return SUCCESS;
}