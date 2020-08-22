#include <iostream>
#include <cstdlib>

// Standard include protection.
#ifndef _PASCAL_H
#define _PASCAL_H

// For use in `getTriangleMember`.
#define ROW_INVALID -1
#define COL_INVALID -2

// Instead of typing out `unsigned int`.
typedef unsigned int uint;

namespace Pascal {
    /**
     *  Function Name:      createTriangle
     *  Pre-Conditions:     unsigned int
     *  Post-Conditions:    unsigned int **
     *  
     *  Allocates and creates a Pascal's triangle with a given height,
     *  and returns a pointer to the structure.
     */
    uint **createTriangle(uint);


    /**
     *  Function Name:      getTriangleMember
     *  Pre-Conditions:     unsigned int **, unsigned int, long, long
     *  Post-Conditions:    long
     *
     *  Given a pointer to a Pascal's triangle structure, its height, and
     *  a row and column, returns the value of the Pascal's triangle's
     *  member at that 1-indexed position. If the given row is not valid,
     *  returns ROW_INVALID and if the given col is not valid, returns COL_INVALID.
     *  ROW_INVALID has greater priority than COL_INVALID.
     */
    long getTriangleMember(uint **, uint, long, long);


    /**
     *  Function Name:      printTriangle
     *  Pre-Conditions:     unsigned int **, unsigned int
     *  Post-Conditions:    none
     *
     *  Given a pointer to a Pascal's triangle structure and its height,
     *  prints the triangle.
     */
    void printTriangle(uint **, uint);


    /**
     *  Function Name:      destroyTriangle
     *  Pre-Conditions:     unsigned int **, unsigned int
     *  Post-Conditions:    none
     *  
     *  Given a pointer to a Pascal's triangle structure and its height,
     *  destroys and deallocates the triangle.
     */
    void destroyTriangle(uint **, uint);
}

#endif