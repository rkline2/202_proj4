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
Caesar::~Caesar() { m_shift = NULL; }

// Name: Encrypt
    // Desc: Shifts characters right based on shift (lower stay lower, upper stay upper)
    // Preconditions - Message exists
    // Postconditions - Shifts each character "right".
void Caesar::Encrypt() {
    int testVal = 0;
    string newMessage = GetMessage();
    int messageSize = newMessage.length();

    for (int i = 0; i < messageSize; i++) {
        char x = newMessage.at(i);
        if (((x <= MAX_UP_C_VAL) && (x >= MIN_UP_C_VAL)) || 
            ((x <= MAX_LOW_C_VAL) && (x >= MIN_LOW_C_VAL))) {

            // uppercase letters only 
            if (isupper(x)) {
                testVal = (x + (m_shift % MAX_CHAR)) - MAX_UP_C_VAL;
                // if char is out of A-Z range 
                if (testVal > 0) {
                    x = MIN_UP_C_VAL + (m_shift - testVal);
                    newMessage.at(i) = x;
                }

                else {
                    x += m_shift;
                    newMessage.at(i) = x;
                }
            }

            // lowercase letters only
            else {
                testVal = (x + (m_shift % MAX_CHAR)) - MAX_LOW_C_VAL;
                // if char is out of A-Z range
                if (testVal > 0) {
                    x = MIN_LOW_C_VAL + (m_shift - testVal);
                    newMessage.at(i) = x;
                }

                else {
                    x += m_shift;
                    newMessage.at(i) = x;
                }
            }
            SetMessage(newMessage);
        }
        
    }

}

// Name: Decrypt
    // Desc: Shifts characters left based on shift (lower stay lower, upper stay upper)
    // Preconditions - Message exists
    // Postconditions - Shifts each character "left".
void Caesar::Decrypt() {
    int testVal = 0;
    string newMessage = GetMessage();
    int messageSize = newMessage.length();

    for (int i = 0; i < messageSize; i++) {
        char x = newMessage.at(i);
        if (((x <= MAX_UP_C_VAL) && (x >= MIN_UP_C_VAL)) ||
            ((x <= MAX_LOW_C_VAL) && (x >= MIN_LOW_C_VAL))) {

            // uppercase letters only 
            if (isupper(x)) {
                testVal = (x - (m_shift % MAX_CHAR)) - MIN_UP_C_VAL;
                // if char is out of A-Z range 
                if (testVal < 0) {
                    x = MAX_UP_C_VAL - (m_shift + testVal);
                    newMessage.at(i) = x;
                }

                else {
                    x -= m_shift;
                    newMessage.at(i) = x;
                }
            }

            // lowercase letters only
            else {
                testVal = (x - (m_shift % MAX_CHAR)) - MIN_LOW_C_VAL;
                // if char is out of A-Z range
                if (testVal < 0) {
                    x = MAX_LOW_C_VAL - (m_shift + testVal);
                    newMessage.at(i) = x;
                }

                else {
                    x -= m_shift;
                    newMessage.at(i) = x;
                }
            }
            SetMessage(newMessage);
        }

    }
}

// Name: ToString
    // Desc - A function that returns the string of the object type
    // Preconditions - The object exists
    // Postconditions - The subtype is returned (Caesar in this case)
string Caesar::ToString() { return STR_CAESAR; }

// Name: FormatOutput()
   // Desc - A function that returns the formatted output for Output function
   // Preconditions - The object exists (use stringstream)
   // Postconditions - c, delimiter, isencrypted, delimiter,
   // message, delimiter, m_shift are returned for output
string Caesar::FormatOutput() {
    stringstream strStream;
    string objType(NUMCHAR, ISCAESAR);
    strStream << objType << DELIMITER << 
        to_string(GetIsEncrypted()) << DELIMITER << GetMessage() 
        << DELIMITER << to_string(m_shift);
    return strStream.str();
}

/*int m_shift; //Number of characters to shift. (A shift 3 = D) (D shift -3 = A)*/
