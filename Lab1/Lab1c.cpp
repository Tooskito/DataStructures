#include "Lab1.h"
/**
 *  File:   Lab1c.cpp
 *  Author: Jonathan Abbott
 *  Email:  jabbott4@nd.edu
 *  
 *  This file implements Lab1c. It stores user-input in a
 *  class, whose members are printed out via method call.
 *  This file also presents proper data hiding and encapsulation.
 */


/**
 *  Class Name: Node
 * 
 *  Similar to Lab1b, this Node holds members that are
 *  passed in via constructor, whose properties can be printed
 *  via method call. This Node also incorporates proper
 *  data hiding and encapsulation. Note: class members are
 *  private by default.
 */
class Node {
private:
    // Class members.
    unsigned long int theUnsigLongInt;
    float theFloat;
    double theDouble;
    char theChar;
public:
    // Constructor.
    Node(unsigned long int uli, float f, double d, char c)
        : theUnsigLongInt(uli), theFloat(f), theDouble(d), theChar(c) {}
    
    // Class methods.
	void printNodeValues(){
		COUT << ENDL << "-----------------------------" << ENDL;
		COUT << "Initial address of 'this': " << this << ENDL << ENDL;	

        // Without using "this", simply print members and their addresses.
        COUT << "Long Unsigned Int\t: " << theUnsigLongInt << " at address " << &theUnsigLongInt << ENDL;
        COUT << "Float\t\t\t: " << theFloat << " at address " << &theFloat << ENDL;
        COUT << "Double\t\t\t: " << theDouble << " at address " << &theDouble << ENDL;
        COUT << "Char\t\t\t: " << theChar << " at address " << ( (void *)&theChar ) << ENDL << ENDL;
	}
};


/**
 *  Function Name:  main
 *  Pre-conditions: none
 *  Post-condition: int
 *  
 *  This is the entry point of the program.
 */
int main() {
    // Define general local variables.
    unsigned long int uli;
    float f;
    double d;
    char c;

    // Gather user-input and return early if error.
    if (pollInput(uli, f, d, c) != INPUT_OK)
        return EXIT_FAILURE;
    
    // Create instance of class Node and pass user-input.
    Node node(uli, f, d, c);

    // Print out node's properties.
    COUT << "Node is at address: " << &node << ENDL;
    node.printNodeValues();
    COUT << ENDL;

    // Exit program cleanly.
    return EXIT_SUCCESS;
}