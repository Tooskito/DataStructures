#include "Lab1.h"

bool noBadCharsIn(const STRING &s) {
    bool haveSeenDecimalPoint = false;
    for (size_t i = 0; i < s.length(); ++i) {
        // Simply continues (a.k.a skips this) if 0-9.
        if (s[i] < '0' or '9' < s[i]) {
            // Make sure '-' only appears at beginning.
            if (s[i] == '-' && i != 0)
                return false;
            // Make sure we only see one decimal '.' point.
            if (s[i] == '.') {
                if (haveSeenDecimalPoint)
                    return false;
                else
                    haveSeenDecimalPoint = true;
            }
        }
    }
    // If we reach here, we never found any bad chars.
    return true;
}

int pollInput(  unsigned long int &uli,
                float &f,
                double &d,
                char &c) {
    // Define local variables.
    STRING strUnsigLongInt;
    STRING strFloat;
    STRING strDouble;
    STRING strChar;

    // Capture unsigned long integer and verify it is an unsigned long integer.
    COUT << "Input an unsigned long integer: ";
    CIN >> strUnsigLongInt;
    if (SSTREAM(strUnsigLongInt) >> uli
            && noBadCharsIn(strUnsigLongInt)
            && strUnsigLongInt.find('.') == STRING::npos) {
        COUT << "Received an unsigned long integer with value: " << uli << ENDL;
    } else {
        // If it is not a valid unsigned long integer, return early with an error code.
        CERR << strUnsigLongInt << " is not a valid unsigned long integer." << ENDL;
        return INPUT_ERR;   
    }

    // Capture a float and verify it is a float.
    COUT << "Input a float: ";
    CIN >> strFloat;
    if (SSTREAM(strFloat) >> f
            && noBadCharsIn(strFloat)) {
        COUT << "Received a float with value: " << f << ENDL;
    } else {
        // If it is not a valid float, return early with an error code.
        CERR << strFloat << " is not a valid float." << ENDL;
        return INPUT_ERR;
    }

    // Capture a double and verify it is a double.
    COUT << "Input a double: ";
    CIN >> strDouble;
    if (SSTREAM(strDouble) >> d
            && noBadCharsIn(strDouble)) {
        COUT << "Received a double with value: " << d << ENDL;
    } else {
        // If it is not a valid double, return early with an error code.
        CERR << strDouble << " is not a valid double." << ENDL;
        return INPUT_ERR;
    }

    // Capture a char and verify it is so.
    COUT << "Input a char: ";
    if (CIN >> c) {
        COUT << "Received a char with repr: " << c << ENDL;
    } else {
        CERR << "Not a valid character." << ENDL;
        return INPUT_ERR;
    }

    // If we've gotten to here, then that means we haven't thrown an error.
    // Which means that polling input was successful!
    return INPUT_OK;
}