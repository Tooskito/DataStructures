#include "Lab1.h"
/**
 *  File:   Lab1b.cpp
 *  Author: Jonathan Abbott
 *  Email:  jabbott4@nd.edu
 *  
 *  This file implements Lab1b. It stores user-input
 *  in a struct, whose members are printed out via
 *  method call. Credit is due to Prof. Morrison who's 
 *  examples inspired much of what is in here.
 */


/**
 *  Struct Name:   Node
 *  
 *  Similar to Lab1a, this Node holds members that are set via
 *  constructor whose properties can be printed via method call.
 *  Note: struct members are public by default.
 */
struct Node {
    // Struct members.
    unsigned long int theUnsigLongInt;
    float theFloat;
    double theDouble;
    char theChar;

    // Constructor from Prof. Morrison's example.
    Node(unsigned long int uli, float f, double d, char c)
        : theUnsigLongInt(uli), theFloat(f), theDouble(d), theChar(c) {}
    
    // Struct methods from Prof. Morrison's example.
	void printNodeValues(){
		COUT << ENDL << "-----------------------------" << ENDL;
		COUT << "Initial address of 'this': " << this << ENDL << ENDL;	

        // Print out address of each member.
        COUT << "Long Unsigned Int: " << this->theUnsigLongInt << " at address " << &(this->theUnsigLongInt) << ENDL;
        COUT << "Float            : " << this->theFloat << " at address " << &(this->theFloat) << ENDL;
        COUT << "Double           : " << this->theDouble << " at address " << &(this->theDouble) << ENDL;
        COUT << "Char             : " << this->theChar << " at address " << ( (void *)&(this->theChar) ) << ENDL << ENDL;
	}   
};


/**
 *  Function Name:  main
 *  Pre-conditions: none
 *  Post-condition: int
 *  
 *  This is the entry point of the program.
 */
//  Commenting style inspired by Prof. Morrison.
int main() {
    // Define general local variables.
    unsigned long int uli;
    float f;
    double d;
    char c;

    // Poll input and return early if failure.
    if (pollInput(uli, f, d, c) != INPUT_OK)
        return EXIT_FAILURE;
    
    // Create node instance.
    Node node(uli, f, d, c);

    // Print out node's information.
    COUT << "Node is at address: " << &node << ENDL;
    node.printNodeValues();
    COUT << ENDL;

    // Exit program cleanly.
    return EXIT_SUCCESS;
}