#include "Lab1.h"
/**
 *  File:   Lab1a.cpp
 *  Author: Jonathan Abbott
 *  Email:  jabbott4@nd.edu
 *  
 *  This file implements Lab1a, storing user-input in
 *  the Data Heap, and using pointer-arithmetic to
 *  print it out.
 */


/**
 *  Function Name:  setNodeValues
 *  Pre-conditions: void *loc,
 *                  unsigned long int &uli,
 *                  float &f,
 *                  double &d,
 *                  char &c
 *  Post-condition: none
 * 
 *  Takes a void pointer to a memory location on the 
 *  Data Heap and fills it with parameters.
 */
void setNodeValues( const void *loc,
                    const unsigned long int &uli,
                    const float &f,
                    const double &d,
                    const char &c);


/**
 *  Function Name:  printNodeValues
 *  Pre-conditions: void *loc
 *  Post-condition: none
 * 
 *  Takes a void pointer to a memory location on the
 *  Data Heap and, using pointer arithmetic, prints
 *  out contiguous values.
 */
void printNodeValues(void *loc);


/**
 *  Function Name:  main
 *  Pre-conditions: none
 *  Post-condition: int
 *  
 *  This is the entry point of the program.
 */
int main(int argc, char** argv) {
    // Define general local variables.
    unsigned long int uli;
    float f;
    double d;
    char c;

    // Poll input and handle errors.
    if (pollInput(uli, f, d, c) == INPUT_ERR)
        return EXIT_FAILURE;
    
    // Now that input is valid, reserve memory for node.
    size_t nodeSize = sizeof(unsigned long int) + sizeof(float) + sizeof(double) + sizeof(char);
    void *node = malloc(nodeSize);

    // Set node values to an allocated memory block, and then print it out.
    setNodeValues(node, uli, f, d, c);
    printNodeValues(node);

    // Free memory and return cleanly.
    free(node);
    return EXIT_SUCCESS;
}


//  See: "setNodeValues" declaration above.
void setNodeValues( const void *loc,
                    const unsigned long int &uli,
                    const float &f,
                    const double &d,
                    const char &c) {
    // To allow pointer arithmetic, because a character is, and always will be, 1-byte wide.
    char *ref = (char *)loc;

    // De-reference, set, and advance pointer => repeat both redundantly and trivially.
    *( (unsigned long int *)ref ) = uli;
    ref += sizeof(unsigned long int);

    *( (float *)ref ) = f;
    ref += sizeof(float);

    *( (double *)ref ) = d;
    ref += sizeof(double);

    *( (char *)ref ) = c;
}


//  See: "printNodeValues" declaration above.
void printNodeValues(void *loc) {
    // To allow pointer arithmetic, because a character is, and always will be, 1-byte wide.
    char *ref = (char *)loc;

    // Note that we also have to cast to (void *) because I do not want the register of "ref"
    // so I cannot go "&ref", and I cannot just use ref because "char *"s are treated differently
    // than other pointers.
	COUT << ENDL << "Initial address of reference: " << (void *)ref << ENDL << ENDL;	
	
    // Cast to void pointer, print, advance char pointer => rinse and repeat.
    COUT << "Long Unsigned Int: " << *( (unsigned long int *)ref ) << " at address " << (void *)ref << ENDL;
    ref += sizeof(unsigned long int);

    COUT << "Float            : " << *( (float *)ref ) << " at address " << (void *)ref << ENDL;
    ref += sizeof(float);

    COUT << "Double           : " << *( (double *)ref ) << " at address " << (void *)ref << ENDL;
    ref += sizeof(double);

    COUT << "Char             : " << *( (char *)ref ) << " at address " << (void *)ref << ENDL << ENDL;

	COUT << "Final address of reference: " << (void *)ref << ENDL << ENDL;
}