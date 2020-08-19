#include "Lab1.h"
/**
 *  File:   Lab1c.cpp
 *  Author: Jonathan Abbott
 *  Email:  jabbott4@nd.edu
 * 
 *  This file implements Lab1c. It stores user-input in a
 *  class, whose members are printed out via method call.
 *  This file also presents proper data hiding and encapsulation.
 *  Credit is due to Prof. Morrison who's examples inspired
 *  much of what is in here.
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
    // Constructor from Prof. Morrison's example.
    Node(unsigned long int uli, float f, double d, char c)
        : theUnsigLongInt(uli), theFloat(f), theDouble(d), theChar(c) {
        COUT << ENDL << "-----------------------------" << ENDL;
		COUT << "Initial address of 'this': " << this << ENDL << ENDL;	
    }
    
    // Class methods inspired by Prof. Morrison's examples.
	void printNodeValues(){
        
	}

    // Friend operator to output variables using COUT.
    friend OSTREAM& operator<< (OSTREAM& out, Node& n) {
        // Without using "this", simply print members and their addresses.
        out << "Long Unsigned Int: " << n.theUnsigLongInt << " at address " << &n.theUnsigLongInt << ENDL;
        out << "Float            : " << n.theFloat << " at address " << &n.theFloat << ENDL;
        out << "Double           : " << n.theDouble << " at address " << &n.theDouble << ENDL;
        out << "Char             : " << n.theChar << " at address " << ( (void *)&n.theChar ) << ENDL;
        // Return OSTREAM for chaining.
        return out;
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

    // Gather user-input and return early if error.
    if (pollInput(uli, f, d, c) != INPUT_OK)
        return EXIT_FAILURE;
    
    // Create instance of class Node and pass user-input.
    Node node(uli, f, d, c);

    // Print out node's properties.
    COUT << node << ENDL;

    // Exit program cleanly.
    return EXIT_SUCCESS;
}