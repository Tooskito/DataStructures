#include "Lab1.h"

class Node {
    unsigned long int theUnsigLongInt;
    float theFloat;
    double theDouble;
    char theChar;
public:
    Node(unsigned long int uli, float f, double d, char c)
        : theUnsigLongInt(uli), theFloat(f), theDouble(d), theChar(c) {}
    
    /* Class methods */
	void printNodeValues(){
		COUT << "-----------------------------" << ENDL;
		COUT << "Initial address of 'this': " << this << ENDL << ENDL;	

        COUT << "Unsigned long int: " << theUnsigLongInt << " at address " << &theUnsigLongInt << ENDL;
        COUT << "Float: " << theFloat << " at address " << &theFloat << ENDL;
        COUT << "Double: " << theDouble << " at address " << &theDouble << ENDL;
        COUT << "Char: " << theChar << " at address " << ( (void *)&theChar ) << ENDL;
	}
};

int main() {
    unsigned long int uli;
    float f;
    double d;
    char c;

    if (pollInput(uli, f, d, c) != INPUT_OK)
        return EXIT_FAILURE;
    
    Node node(uli, f, d, c);

    COUT << "Node is at address: " << &node << ENDL;
    node.printNodeValues();
    COUT << ENDL;

    return EXIT_SUCCESS;
}