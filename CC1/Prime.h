/**
 *  @author Jonathan Abbott
 *  @date   Aug 23, 2020
 * 
 *  This file includes all the declarations of Prime-checking via Pascal's
 *  Triangle functionality, for the `Creative` portion of CC1.
 */


#include <iostream> // For i.e. `std::cout`
#include "Pascal.h" // Since this script inherently relies on Pascal's triangle.

// For readability of function error codes.
#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAILURE
#define FAILURE 1
#endif


// Classic include guarding, to avoid multiple inclusion.
#ifndef CC1_PRIME_H_
#define CC1_PRIME_H_


/**
 *  Checks if a given number is prime given a Pascal's Triangle and a number.
 * 
 *  @param triangle The pointer to Pascal's Triangle to use.
 *  @param height The height of that triangle.
 *  @param num The number to check for primality.
 *  @param out Where the result of this check for primality is stored.
 *  @return `FAILURE` if `num` is out of range. otherwise, `SUCCESS`.
 */
int TriangleCheckPrime(
    unsigned int ** triangle, 
    unsigned int height, 
    unsigned int num, 
    bool & out
);


/**
 *  Prompts the user for a number to check for primality and stores the result.
 * 
 *  @param num Where the user's input is stored.
 *  @return `FAILURE` if error reading input. otherwise, `SUCCESS`.
 */
int PollNumber(unsigned int & num);


#endif