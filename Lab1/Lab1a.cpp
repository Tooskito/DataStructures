#include "Lab1.h"

void setNodeValues( const void *loc,
                    const unsigned long int &uli,
                    const float &f,
                    const double &d,
                    const char &c);

void printNodeValues(void *loc);

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


void setNodeValues( const void *loc,
                    const unsigned long int &uli,
                    const float &f,
                    const double &d,
                    const char &c) {
    // To allow pointer arithmetic, because a character is, and always will be, 1-byte wide.
    char *ref = (char *)loc;

    // De-reference, set, advance => repeat redundantly and trivially.
    *( (unsigned long int *)ref ) = uli;
    ref += sizeof(unsigned long int);

    *( (float *)ref ) = f;
    ref += sizeof(float);

    *( (double *)ref ) = d;
    ref += sizeof(double);

    *( (char *)ref ) = c;
}

void printNodeValues(void *loc) {
    // To allow pointer arithmetic, because a character is, and always will be, 1-byte wide.
    char *ref = (char *)loc;

    COUT << "-----------------------------" << ENDL;
	COUT << "Initial address of reference: " << (void *)ref << ENDL << ENDL;	
	
    COUT << "Unsigned long int: " << *( (unsigned long int *)ref ) << " at address: " << (void *)ref << ENDL;
    ref += sizeof(unsigned long int);

    COUT << "Float: " << *( (float *)ref ) << "at address: " << (void *)ref << ENDL;
    ref += sizeof(float);

    COUT << "Double: " << *( (double *)ref ) << " at address: " << (void *)ref << ENDL;
    ref += sizeof(double);

    COUT << "Char: " << *( (char *)ref ) << " at address: " << (void *)ref << ENDL;

	COUT << "Final address of reference: " << ref << ENDL;	
    COUT << "-----------------------------" << ENDL;
}