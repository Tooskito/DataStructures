#include "Pascal.h"

// See "Pascal.h" for information.
uint **Pascal::createTriangle(uint h) {
    uint **res;
    // Allocate memory first.
    res = (uint**)malloc(sizeof(uint*) * h);
    for (uint r = 0; r < h; ++r)
        res[r] = (uint*)malloc(sizeof(uint) * (r + 1));
    // Now, calculate triangle.
    for (uint r = 0; r < h; ++r)
        for (uint c = 0; c <= r; ++c)
            res[r][c] = (c != 0 and c != r) 
                            ? res[r - 1][c - 1] + res[r - 1][c]
                            : 1;
    // Return the triangle, now.
    return res;
}


// See "Pascal.h" for information.
long Pascal::getTriangleMember(uint **d, uint h, long r, long c) {
    // Note: `r`, `c`, and `h` (row index, col index, and height respectively) are 1-indexed.
    if (r < 1 or h < r)
        return ROW_INVALID;
    if (c < 1 or r < c)
        return COL_INVALID;
    // Now, since indices are valid, return the member at that index.
    return d[r - 1][c - 1];
}


// See "Pascal.h" for information.
void Pascal::printTriangle(uint **d, uint h) {
    for (uint r = 0; r < h; ++r) {
        for (uint c = 0; c <= r; ++c)
            std::cout << d[r][c] << " ";
        std::cout << std::endl;
    }
}


// See "Pascal.h" for information.
void Pascal::destroyTriangle(uint **d, uint h) {
    for (uint r = 0; r < h; ++r)
        free(d[r]);
    free(d);
}