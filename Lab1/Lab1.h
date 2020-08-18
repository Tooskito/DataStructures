// Author:  Jonathan Abbott
// Date:    Monday, Aug 17, 2020
// Desc:    Header file for Lab1
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

int pollInput(  unsigned long int &uli,
                float &f,
                double &d,
                char &c);

bool noBadCharsIn(const STRING &s);