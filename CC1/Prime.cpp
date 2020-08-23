/**
 *  @author Jonathan Abbott
 *  @date   Aug 23, 2020
 * 
 *  This file includes all the implementation details of Prime-checking via
 *  Pascal's Triangle functionality.
 */


#include <iostream> // For i.e. `std::cout`


#include "Prime.h"  // So that we may implement `Prime.h`
#include "Pascal.h" // So that we have access to Pascal's Triangle functionality.


// See "Prime.h" for details.
int TriangleCheckPrime(
    unsigned int ** triangle, 
    unsigned int height, 
    unsigned int num, 
    bool & out
) {

    // if we are checking number i.e. 5 for primality, we must check index row number i.e. 5.
    // so if num is equal to height, that is out of bounds because max index for triangle with
    // `height` is actually `height - 1`. therefore, num >= height.
    if ( num >= height ) {
        std::cerr << num << " is out of range" << std::endl;
        return FAILURE;
    }
    
    // if num is 1 or 0 (not negative because it is unsigned), return false because 1 and 0 are not prime.
    if ( num <= 1 ) {
        out = false;
        return SUCCESS;
    }

    // assume number is prime unless proven otherwise.
    bool isPrime = true;

    // since length of row = 1-indexed row index, and num corresponds to checking row index num,
    // length of row index num is num + 1. we want to ignore the 1s on the sides.
    for (unsigned int c = 1; c < num; ++c) {

        // check if num evenly divides all the numbers in the middle. if not, num is not prime.
        if ( triangle[num][c] % num != 0 ) {
            isPrime = false;
            break;
        }
    }

    // set output variable to whether or not the number was prime.
    out = isPrime;
    return SUCCESS;
}


// See "Prime.h" for details.
int PollNumber(unsigned int & num) {
    
    // prompt user.
    std::cout << "Which number would you like to check for primality: ";

    // returns `FAILURE` if input failure or input < 0.
    long inpNum;
    if ( 
        not ( std::cin >> inpNum ) or
        inpNum < 0
    ) {
        return FAILURE;
    }

    // cast (positive) 8-byte long into 4-byte integer.
    num = (unsigned int) inpNum;
    return SUCCESS;
}