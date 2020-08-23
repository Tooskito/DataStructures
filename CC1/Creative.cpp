/**
 *  @author Jonathan Abbott
 *  @date   Aug 23, 2020
 * 
 *  This `main` file demonstrates Prime-checking via Pascal's Triangle
 *  implemented in `Prime.cpp` via user-interaction.
 */


#include <iostream> // For i.e. `std::cout`
#include "Pascal.h" // For Pascal's Triangle functionality.
#include "Prime.h"  // For Prime-checking functionality.



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
        std::cerr << "height too big" << std::endl;
        return FAILURE;
    }
    // otherwise, `triangle` now holds a multi-dimensional pointer.


    // we pass in `height` here because `PrintTriangle` has no idea how big our `triangle` is.
    Pascal::PrintTriangle(triangle, height);


    // `true` because we'll just break whenever the user doesn't input a 'y'.
    while ( true ) {


        // `PollNumber` returns `FAILURE` if input failure or input < 0.
        unsigned int number;
        if ( PollNumber(number) != SUCCESS ) {
            std::cerr << "error reading input" << std::endl;
            return FAILURE;
        }
        // else, `number` holds positive number to check for primality.


        // `TriangleCheckPrime` returns `FAILURE` if number out of range. otherwise, `SUCCESS`.
        bool isPrime;
        if ( TriangleCheckPrime(triangle, height, number, isPrime) == SUCCESS ) {

            // `isPrime` now holds if number is prime or not prime.
            if ( isPrime ) {
                std::cout << number << " is a prime number" << std::endl;
            } else {
                std::cout << number << " is not a prime number" << std::endl;
            }
        }


        // `PollContinue` returns false if user does not want to continue.
        if ( not PollContinue() ) {
            break;
        }
    }


    // always free dynamically allocated memory.
    Pascal::FreeTriangle(triangle, height);

    
    // and return exit code 0 for success.
    std::cout << "Exiting program..." << std::endl;
    return SUCCESS;
}