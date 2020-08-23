/**
 *  @author Jonathan Abbott
 *  @date   Aug 23, 2020
 * 
 *  This file includes all the implementation definitions of "Pascal.h",
 *  implementing Pascal's Triangle functionality.
 */


#include "Pascal.h"


// See "Pascal.h" for more information.
unsigned int ** Pascal::AllocTriangle(unsigned int height) {

    // declare a pointer to pointers for the triangle.
    unsigned int ** triangle;

    // malloc the pointer to pointers.
    triangle = (unsigned int **) malloc( sizeof(unsigned int *) * height );

    // then malloc the pointers, pointed to by the pointer.
    for (unsigned int i = 0; i < height; ++i) {
        triangle[i] = (unsigned int *) malloc( sizeof(unsigned int) * (i + 1) );
    }

    return triangle;
}


// See "Pascal.h" for more information.
void Pascal::FreeTriangle(unsigned int ** triangle, unsigned int height) {

    // free the pointers, pointed to by the pointer.
    for (unsigned int i = 0; i < height; ++i) {
        free(triangle[i]);
    }

    // then, free the pointer.
    free(triangle);
}


// See "Pascal.h" for more information.
int Pascal::FillTriangle(unsigned int ** triangle, unsigned int height) {

    // ex. height = 5. r will span [0, 5), so [0, 4].
    for (unsigned int r = 0; r < height; ++r) {

        // at r = 0, we have 1 value. so c <= r.
        for (unsigned int c = 0; c <= r; ++c) {

            // if below is true, we are at the edges of the row.
            if ( c == 0 or c == r ) {
                triangle[r][c] = 1;
            
            // else, we are in the middle. safe to add adjacent tops.
            } else {

                // store the adjacent values.
                unsigned int a = triangle[r - 1][c - 1];
                unsigned int b = triangle[r - 1][c];

                // if adding these values will overflow, return FAILURE because of overflow.
                if (
                    a >= UINT_MAX - b or
                    b >= UINT_MAX - a
                ) {
                    return FAILURE;
                
                // else, proceed normally, summing adjacent values.
                } else {
                    triangle[r][c] = a + b;
                }
            }
        }
    }

    // we never failed, so we're successful.
    return SUCCESS;
}


// See "Pascal.h" for more information.
unsigned int ** Pascal::CreateTriangle(unsigned int height) {

    // note: because height is unsigned, height can never be negative.
    // create triangle pointer.
    unsigned int ** triangle;

    // allocate the memory for that pointer.
    triangle = AllocTriangle( height );
    
    // and fill it, returning `nullptr` instead if overflow.
    if ( FillTriangle(triangle, height) != SUCCESS ) {
        return nullptr;
    }

    // if no overflow, return the pointer.
    return triangle;
}


// See "Pascal.h" for more information.
void Pascal::PrintTriangle(unsigned int ** triangle, unsigned int height) {

    // print a newline for spacing.
    std::cout << std::endl;

    // iterate through each index in the triangle.
    for (unsigned int r = 0; r < height; ++r) {
        for (unsigned int c = 0; c <= r; ++c) {
            
            // and print out the value at that location.
            std::cout << triangle[r][c] << ' ';
        }

        // at the end of the row, print a newline.
        std::cout << std::endl;
    }

    // and print a newline again for spacing.
    std::cout << std::endl;
}


// See "Pascal.h" for more information.
int Pascal::GetTriangleMember(
    unsigned int ** triangle, 
    unsigned int height, 
    unsigned int row, 
    unsigned int col, 
    unsigned int & out
) {
    
    // ex. if height is 5, max index is 4 for row. so if user inputs 6, and because 6
    // is 1-indexed, return error, because 6 - 1 = 5 is not a valid index.
    if ( row < 1 or row > height ) {
        std::cerr << row << " is not a valid row" << std::endl;
        return FAILURE;
    }

    // note: length of row (number of columns) will always equal 1-indexed row.
    // so if user requests anything less than 1 (which means less than index 0) or
    // if user requests anything larger than index row - 1,  then return error.
    if ( col < 1 or col > row ) {
        std::cerr << col << " is not a valid column in row " << row << std::endl;
        return FAILURE;
    }

    // else, store member in &out.
    out = triangle[row - 1][col - 1];
    return SUCCESS;
}


// See "Pascal.h" for more information.
int PollHeight(unsigned int & height) {

    // prompt user.
    std::cout << "How many levels do you want to calculate: ";

    // if there is an error storing input or if inputted height is < 1, return error.
    long inpHeight;
    if ( 
        not ( std::cin >> inpHeight ) or 
        inpHeight < 1 
    ) {
        return FAILURE;
    }

    // else, cast (positive) 8-byte long to 4-byte int and store in param.
    height = (unsigned int) inpHeight;
    return SUCCESS;
}


// See "Pascal.h" for more information.
int PollIndex(unsigned int & row, unsigned int & col) {

    // prompt user.
    std::cout << "Enter a row and column value to print [two numbers only]: ";

    // if there is an error storing input or if any input < 1, return error.
    long inpRow, inpCol;
    if (
        not ( std::cin >> inpRow ) or
        not ( std::cin >> inpCol ) or
        inpRow < 1 or
        inpCol < 1
    ) {
        return FAILURE;
    }

    // else, cast (positive) 8-byte longs into 4-byte integer params.
    row = (unsigned int) inpRow;
    col = (unsigned int) inpCol;
    return SUCCESS;
}


// See "Pascal.h" for more information.
bool PollContinue() {

    // prompt user.
    std::cout << "Continue? [y/n]: ";

    // if input error or input character is not 'y', assume user does not want to continue.
    char inpChar;
    if ( not ( std::cin >> inpChar ) or inpChar != 'y' ) {
        std::cout << std::endl;
        return false;
    }

    // print newline for spacing.
    std::cout << std::endl;

    // return true if the above statement didn't catch a.k.a. user wants to continue.
    return true;
}