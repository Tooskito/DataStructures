#include "Pascal.h"

int main() {
    // Declare the pointer to hold the triangle.
    uint **p;
    // These are longs because they are twice the size of an unsigned int. This
    // means the user can enter negative values (which will throw an error) instead
    // of the program trying to read a negative value into an unsigned int. Since longs
    // are twice the size, we lose no ability in addressing the triangle's values.
    long h, r, c, m;
    // This will hold the user's answer to `continue? [y/n]`
    char a;
    // Poll user input.
    std::cout << "How many levels do you want to calculate: ";
    std::cin >> h;
    // Check if input is valid.
    if (h <= 0) {
        std::cerr << h << " is not a valid height." << std::endl;
        return 1;
    }
    // Now, create and print the triangle.
    p = Pascal::createTriangle((uint)h);
    std::cout << std::endl;
    Pascal::printTriangle(p, (uint)h);
    std::cout << std::endl;

    // Essentially an infinite loop.
    while (not std::cin.eof()) {
        // Poll for input for row.
        std::cout << "Enter a row and column value to print [two numbers only]: ";
        std::cin >> r;
        // Return early if unexpected end-of-file.
        if (std::cin.eof()) {
            std::cerr << "Unexpected end-of-file." << std::endl;
            return 1;
        }
        // Else, read another integer.
        std::cin >> c;

        // Check if r and c are within bounds. If so, return the value at
        // that 1-indexed position in Pascal's triangle.
        m = Pascal::getTriangleMember(p, (uint)h, r, c);
        if (m == ROW_INVALID)
            // `m` will be set to ROW_INVALID if row was invalid.
            std::cerr << r << " is not a valid row." << std::endl;
        else if (m == COL_INVALID)
            // `m` will be set to COL_INVALID if col is invalid.
            std::cerr << c << " is not a valid column in row " << r << "." << std::endl;
        else
            // Else, we print the value without error (1-indexed).
            std::cout << m << std::endl;
        
        // Return early if unexpected end-of-file.
        if (std::cin.eof()) {
            std::cerr << "Unexpected end-of-file." << std::endl;
            return 1;
        }

        // Else, check if the user wants to continue.
        std::cout << "Continue? [y/n]: ";
        std::cin >> a;
        // Break if user did not type 'y'.
        if (a != 'y')
            break;
        // Just for nice whitespace.
        std::cout << std::endl;
    }
    
    std::cout << std::endl << "Exiting program..." << std::endl;
    // Cleanup nicely.
    Pascal::destroyTriangle(p, (uint)h);
    return 0;
}