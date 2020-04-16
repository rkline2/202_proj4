#include "Vigenere.h"
#include <iostream>
using namespace std;

// Name: Vigenere (Default Constructor)
    // Desc: Constructor to build an empty Vigenere Cipher (Defaults key to "test")
    // Preconditions - None
    // Postconditions - Creates a Vigenere cipher to be encrypted
Vigenere::Vigenere() { m_key = DEFAULTKEY; }

// Name: Vigenere (Overloaded Constructor)
    // Desc: Constructor to build a populated Vigenere Cipher
    // Preconditions - Pass it the message, isEncrypted, and key
    // Postconditions - Creates a Vigenere cipher to be encrypted
Vigenere::Vigenere(string message, bool isEncrypted, string key) :Cipher(message, isEncrypted) { m_key = key; }

// Name: Vigenere (Destructor)
    // Desc: Destructor - Anything specific to delete in Vigenere?
    // Preconditions - ~Vigenere exists
    // Postconditions - Vigenere destroyed
Vigenere::~Vigenere() {}

// Name: Encrypt
    // Desc: Encrypts using key (See project document for details)
    // Preconditions - Message exists
    // Postconditions - Encrypts using key
void Vigenere::Encrypt(){}

// Name: Decrypt
    // Desc: Decrypts using key (See project document for details)
    // Preconditions - Message exists
    // Postconditions - Uses key to decrypt.
void Vigenere::Decrypt() {}

// Name: ToString
    // Desc - A function that returns the string of the object type
    // Preconditions - The object exists
    // Postconditions - The subtype is returned (Vigenere in this case)
//string Vigenere::ToString(){}

// Name: FormatOutput()
    // Desc - A function that returns the formatted output for Output function
    // Preconditions - The object exists (use stringstream)
    // Postconditions - v, delimiter, isencrypted, delimiter,
    // message, delimiter, key are returned for output
//string Vigenere::FormatOutput(){}

/*string m_key; //Key to encrypt or decrypt message*/
