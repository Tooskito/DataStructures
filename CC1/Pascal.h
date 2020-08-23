/**
 *  @author Jonathan Abbott
 *  @date   Aug 23, 2020
 *  
 *  This file holds the declarations for all Pascal's Triangle functionality.
 */


#include <cstdlib>  // For `malloc`.
#include <climits>  // For `UINT_MAX`.
#include <iostream> // For i.e. `std::cout`


// For readability of function error codes.
#ifndef SUCCESS
#define SUCCESS 0
#endif

#ifndef FAILURE
#define FAILURE 1
#endif


// Classic include guarding (ensures singular include).
#ifndef CC1_PASCAL_H_
#define CC1_PASCAL_H_


// So we can put all triangle-related functions in one namespace.
namespace Pascal {


    /**
     *  Allocates a triangle structure with a given height.
     * 
     *  @param height The height of the triangle a.k.a. how many rows.
     *  @return A multi-dimensional unsigned int pointer.
     */
    unsigned int ** AllocTriangle(unsigned int height);


    /**
     *  De-allocates a dynamically allocated triangle structure with a given height.
     * 
     *  @param triangle The multi-dimensional pointer to the structure.
     *  @param height How many rows the structure has.
     */
    void FreeTriangle(unsigned int ** triangle, unsigned int height);


    /**
     *  Fills a triangle structure with Pascal's triangle values.
     *  
     *  @param triangle The triangle structure to fill.
     *  @param height And how many rows that structure has.
     *  @return `FAILURE` on overflow. otherwise, `SUCCESS`
     */
    int FillTriangle(unsigned int ** triangle, unsigned int height);


    /**
     *  Allocates, fills, and returns a Pascal's triangle structure.
     * 
     *  @param height How many rows the structure should have.
     *  @return A multi-dimensional pointer to the structure, or `nullptr` on failure.
     */
    unsigned int ** CreateTriangle(unsigned int height);


    /**
     *  Prints a triangle into standard output.
     * 
     *  @param triangle The pointer to the triangle structure.
     *  @param height How many rows that triangle has.
     */
    void PrintTriangle(unsigned int ** triangle, unsigned int height);


    /**
     *  Retrieves the member of a triangle structure.
     *  
     *  @param triangle The pointer to the triangle structure.
     *  @param height How many rows that triangle has.
     *  @param row The requested 1-indexed row.
     *  @param col The requested 1-indexed column.
     *  @param out THE MEMBER ("true output") WILL BE STORED HERE.
     *  @return `FAILURE` on invalid indices. otherwise, `SUCCESS`.
     */
    int GetTriangleMember(
        unsigned int ** triangle, 
        unsigned int height, 
        unsigned int row, 
        unsigned int col, 
        unsigned int & out
    );
}


/**
 *  Prompts user for height of the triangle and stores the response.
 * 
 *  @param height Where the user's input will be stored.
 *  @return `FAILURE` if height < 1 or input failure. otherwise, `SUCCESS`.
 */
int PollHeight(unsigned int & height);


/**
 *  Prompts user for a row and column of the triangle and stores the response.
 * 
 *  @param row Where the user's input for a row will be stored.
 *  @param col Where the user's input for a column will be stored.
 *  @return `FAILURE` if input failure or input < 1. otherwise, `SUCCESS`.
 */
int PollIndex(unsigned int & row, unsigned int & col);


/**
 *  Prompts user if they would like to continue and returns their response.
 *  
 *  @return `true` if user would like to continue. else, `false`.
 */
bool PollContinue();


#endif