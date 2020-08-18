#include "Lab1.h"

struct Node {
    unsigned long int theUnsigLongInt;
    float theFloat;
    double theDouble;
    char theChar;

    Node(unsigned long int uli, float f, double d, char c)
        : theUnsigLongInt(uli), theFloat(f), theDouble(d), theChar(c) {}
    
    /* Struct methods */
	void printNodeValues(){
		COUT << "-----------------------------" << ENDL;
		COUT << "Initial address of 'this': " << this << ENDL << ENDL;	

        COUT << "Unsigned long int: " << this->theUnsigLongInt << " at address " << &(this->theUnsigLongInt) << ENDL;
        COUT << "Float: " << this->theFloat << " at address " << &(this->theFloat) << ENDL;
        COUT << "Double: " << this->theDouble << " at address " << &(this->theDouble) << ENDL;
        COUT << "Char: " << this->theChar << " at address " << ( (void *)&(this->theChar) ) << ENDL;
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