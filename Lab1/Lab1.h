/**
 *  File:   Lab1.h
 *  Author: Jonathan Abbott
 *  Email:  jabbott4@nd.edu
 *  
 *  This is the header (declaration) file for "Lab1.cpp", and
 *  is included in each Lab1[a-c] file.
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <sstream>


// For ease of use without `using namespace std;`
#define SSTREAM std::stringstream
#define STRING std::string
#define COUT std::cout
#define CERR std::cerr
#define ENDL std::endl
#define CIN std::cin


// To push error handling up to main.
#define INPUT_ERR 1
#define INPUT_OK 0


/**
 *  Function Name:  pollInput
 *  Pre-conditions: unsigned long int &uli,
 *                  float &f,
 *                  double &d,
 *                  char &c
 *  Post-condition: int
 *  
 *  Stores user-input in given function parameters, and
 *  returns INPUT_ERR if user-input is invalid. Otherwise,
 *  returns INPUT_OK.
 */
int pollInput(  unsigned long int &uli,
                float &f,
                double &d,
                char &c);


/**
 *  Function Name:  noBadCharsIn
 *  Pre-conditions: STRING &s
 *  Post-condition: bool
 *  
 *  Returns false if any character other than 0 - 9, '.',
 *  or '-' appears in the string. Also returns false if
 *  '.' appears more than once.
 */
bool noBadCharsIn(const STRING &s);