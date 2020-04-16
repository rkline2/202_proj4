#include "Caesar.h"

#include <iostream>
using namespace std;

// Name: Caesar (Default Constructor)
    // Desc: Constructor to build an empty Caesar Cipher (Defaults to shift 3)
    // Preconditions - None
    // Postconditions - Creates a Caesar cipher to be encrypted
Caesar::Caesar() { m_shift = DEFAULTSHIFT; }

// Name: Caesar (Overloaded Constructor)
    // Desc: Constructor to build a populated Caesar Cipher (Defaults to shift 3)
    // Preconditions - Pass it the message, isEncrypted, and shift (any integer)
    // Postconditions - Creates a Caesar cipher to be encrypted
Caesar::Caesar(string message, bool isEncrypted, int shift) :Cipher(message, isEncrypted) {
    m_shift = shift;
}

// Name: Caesar (Destructor)
    // Desc: Destructor - Anything specific to Caesar to delete?
    // Preconditions - ~Caesar exists
    // Postconditions - Caesar destroyed
Caesar::~Caesar() {}

// Name: Encrypt
    // Desc: Shifts characters right based on shift (lower stay lower, upper stay upper)
    // Preconditions - Message exists
    // Postconditions - Shifts each character "right".
void Caesar::Encrypt() {}

// Name: Decrypt
    // Desc: Shifts characters left based on shift (lower stay lower, upper stay upper)
    // Preconditions - Message exists
    // Postconditions - Shifts each character "left".
void Caesar::Decrypt() {}

// Name: ToString
    // Desc - A function that returns the string of the object type
    // Preconditions - The object exists
    // Postconditions - The subtype is returned (Caesar in this case)
//string Caesar::ToString() {}

// Name: FormatOutput()
   // Desc - A function that returns the formatted output for Output function
   // Preconditions - The object exists (use stringstream)
   // Postconditions - c, delimiter, isencrypted, delimiter,
   // message, delimiter, m_shift are returned for output
//string Caesar::FormatOutput() {}

/*int m_shift; //Number of characters to shift. (A shift 3 = D) (D shift -3 = A)*/
