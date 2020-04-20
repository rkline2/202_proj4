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
Vigenere::~Vigenere() { m_key.erase(); }

// Name: Encrypt
    // Desc: Encrypts using key (See project document for details)
    // Preconditions - Message exists
    // Postconditions - Encrypts using key
void Vigenere::Encrypt(){
    string newMessage = GetMessage();
    char keyChar;
    int shift = 0;
    int keyVal = 0;
    int messageSize = newMessage.length();

    for (int i = 0; i < messageSize; i++) {
        char x = newMessage.at(i);
        if (((x <= MAX_UP_C_VAL) && (x >= MIN_UP_C_VAL)) ||
            ((x <= MAX_LOW_C_VAL) && (x >= MIN_LOW_C_VAL))) {

            // true when keyVal has reached it's max limit 
            if ((keyVal != 0) && (keyVal % m_key.size() == 0)) {
                keyVal = 0;
            }

            keyChar = m_key.at(keyVal);
                // uppercase letters only 
                if (isupper(x)) {
                    // change to values 0-25
                    keyChar = toupper(keyChar) - MIN_UP_C_VAL;
                    x -= MIN_UP_C_VAL;

                    shift = (x + keyChar) % MAX_CHAR;
                    x = MIN_UP_C_VAL + shift;
                }

                // lowercase letters only
                else {
                    // change to values 0-25
                    keyChar = tolower(keyChar) - MIN_LOW_C_VAL;
                    x -= MIN_LOW_C_VAL;

                    shift = (x + keyChar) % MAX_CHAR;
                    x = MIN_LOW_C_VAL + shift;
                }
                newMessage.at(i) = x;
                SetMessage(newMessage);
                keyVal++; 
        }
              
    }
   
}

// Name: Decrypt
    // Desc: Decrypts using key (See project document for details)
    // Preconditions - Message exists
    // Postconditions - Uses key to decrypt.
void Vigenere::Decrypt() {
    string newMessage = GetMessage();
    char keyChar;
    int shift = 0;
    int keyVal = 0;
    int messageSize = newMessage.length();

    for (int i = 0; i < messageSize; i++) {
        char x = newMessage.at(i);
        if (((x <= MAX_UP_C_VAL) && (x >= MIN_UP_C_VAL)) ||
            ((x <= MAX_LOW_C_VAL) && (x >= MIN_LOW_C_VAL))) {
            // when the keyVal has reached it's max limit 
            if ((keyVal != 0) && (keyVal % m_key.size() == 0)) {
                keyVal = 0;
            }
            keyChar = m_key.at(keyVal);
            // uppercase letters only 
            if (isupper(x)) {
                // change to values 0-25
                keyChar = toupper(keyChar) - MIN_UP_C_VAL;
                x -= MIN_UP_C_VAL;

                // prevents inconsistent values
                if (x >= keyChar) {
                    shift = (x - keyChar) % MAX_CHAR;
                    x = MIN_UP_C_VAL + shift;
                }
                else {
                    shift = (keyChar - x) % MAX_CHAR;
                    x = (MAX_UP_C_VAL - shift) + 1;
                }
                
            }
            // lowercase letters only
            else {
                // change to values 0-25
                keyChar = tolower(keyChar) - MIN_LOW_C_VAL;
                x -= MIN_LOW_C_VAL;

                // prevents inconsistent values
                if (x >= keyChar) {
                    shift = (x - keyChar) % MAX_CHAR;
                    x = MIN_LOW_C_VAL + shift;
                }
                else {
                    shift = (keyChar - x) % MAX_CHAR;
                    x = (MAX_LOW_C_VAL - shift) + 1;
                }
                
            }
            newMessage.at(i) = x;
            SetMessage(newMessage);
            keyVal++;
        }

    }
}

// Name: ToString
    // Desc - A function that returns the string of the object type
    // Preconditions - The object exists
    // Postconditions - The subtype is returned (Vigenere in this case)
string Vigenere::ToString() { return STR_VIGEN; }

// Name: FormatOutput()
    // Desc - A function that returns the formatted output for Output function
    // Preconditions - The object exists (use stringstream)
    // Postconditions - v, delimiter, isencrypted, delimiter,
    // message, delimiter, key are returned for output
string Vigenere::FormatOutput() {
    stringstream strStream;
    string objtype(NUMCHAR, ISVIGEN);
    strStream << objtype << DELIMITER <<
        to_string(GetIsEncrypted()) << DELIMITER << GetMessage()
        << DELIMITER << m_key;
    return strStream.str();
}

/*string m_key; //Key to encrypt or decrypt message*/
