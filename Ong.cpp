#include "Ong.h"
#include <iostream>
using namespace std;

// Name: Ong (Default Constructor)
    // Desc: Constructor to build an empty Ong Cipher
    // Preconditions - None
    // Postconditions - Creates a Ong cipher to be encrypted
Ong::Ong() {}

// Name: Ong (Overloaded Constructor)
    // Desc: Constructor to build a populated Ong Cipher
    // Preconditions - Pass it the message and isEncrypted
    // Postconditions - Creates a Ong cipher to be encrypted
Ong::Ong(string message, bool isEncrypted) :Cipher(message, isEncrypted) {}

// Name: Ong (Destructor)
    // Desc: Destructor - Anything unique to Ong to delete?
    // Preconditions - ~Ong exists
    // Postconditions - Ong destroyed
Ong::~Ong() {}

// Name: IsVowel (Helper function)
    // Desc: Returns true if vowel, space, or punctuation
    // Preconditions - Message exists
    // Postconditions - Returns true or false as above
//bool Ong::IsVowel(char) {}

// Name: Encrypt
    // Desc: If vowel then vowel and dash displayed. dog = dong-o-gong
    // If consonant then consonant and ong and dash displayed.
    // Preconditions - Message exists
    // Postconditions - Encrypts as above
void Ong::Encrypt() {}

// Name: Decrypt
    // Desc: Removes the dashes and "ong" when necessary cong-a-tong = cat
    // Preconditions - Message exists
    // Postconditions - Original message is displayed
void Ong::Decrypt() {}

// Name: ToString
    // Desc - A function that returns the string of the object type
    // Preconditions - The object exists
    // Postconditions - The subtype is returned (Ong in this case)
//string Ong::ToString() {}

// Name: FormatOutput()
    // Desc - A function that returns the formatted output for Output function
    // Preconditions - The object exists (use stringstream)
    // Postconditions - o, delimiter, isencrypted, delimiter,
    //                  message, delimiter, blank are output
//string Ong::FormatOutput() {}
