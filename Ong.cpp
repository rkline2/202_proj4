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
bool Ong::IsVowel(char letter) {

    // uppercase letters 
    if (letter == toupper(IS_A) || letter == toupper(IS_E) ||
    letter == toupper(IS_I) || letter == toupper(IS_O) ||
    letter == toupper(IS_U)) {
    return true;
    }

    // lowercase letters
    else if (letter == IS_A || letter == IS_E ||
        letter == IS_I || letter == IS_O ||
        letter == IS_U) {
        return true;
    }
    return false;

}

// Name: Encrypt
    // Desc: If vowel then vowel and dash displayed. dog = dong-o-gong
    // If consonant then consonant and ong and dash displayed.
    // Preconditions - Message exists
    // Postconditions - Encrypts as above
void Ong::Encrypt() {
    string newMessage = GetMessage();
    bool lastLetter = true;
    int messageSize = newMessage.length();
    char nextChar;

    for (int i = messageSize - 1; i >= 0; i--) {
        char x = newMessage.at(i);
        if (((x <= MAX_UP_C_VAL) && (x >= MIN_UP_C_VAL)) ||
            ((x <= MAX_LOW_C_VAL) && (x >= MIN_LOW_C_VAL))) {
            // last letter only
            if (lastLetter) { 
                if (!IsVowel(x)) {
                    newMessage.insert(i + 1, ONG);
                }
                lastLetter = false; 
            }

            else {
                nextChar = newMessage.at(i + 1);
                if (!IsVowel(x) && (((nextChar <= MAX_UP_C_VAL) && 
                    (nextChar >= MIN_UP_C_VAL)) || ((nextChar <= MAX_LOW_C_VAL) &&
                        (nextChar >= MIN_LOW_C_VAL)))) { 
                    newMessage.insert(i + 1, ONG_W_DASH); 
                }

                else if (!IsVowel(x)) { newMessage.insert(i + 1, ONG); }

                else if (IsVowel(x) && (((nextChar <= MAX_UP_C_VAL) &&
                    (nextChar >= MIN_UP_C_VAL)) || ((nextChar <= MAX_LOW_C_VAL) &&
                        (nextChar >= MIN_LOW_C_VAL)))) {
                    newMessage.insert(i + 1, DASH_STR); 
                }
            }
            SetMessage(newMessage);
        }
    }
}

// Name: Decrypt
    // Desc: Removes the dashes and "ong" when necessary cong-a-tong = cat
    // Preconditions - Message exists
    // Postconditions - Original message is displayed
void Ong::Decrypt() {
    string newMessage = GetMessage();
    for (int i = 0; i < newMessage.length(); i++) {
        char x = newMessage.at(i);
        if (x == DASH_C) {
            newMessage.erase(i, 1);
        }
        x = newMessage.at(i);
        if(((x <= MAX_UP_C_VAL) && (x >= MIN_UP_C_VAL)) ||
            ((x <= MAX_LOW_C_VAL) && (x >= MIN_LOW_C_VAL))) {
            if (!IsVowel(x)) {
                newMessage.erase(i + 1, ONG.size());
            }
        }
        SetMessage(newMessage);
    }
}

// Name: ToString
    // Desc - A function that returns the string of the object type
    // Preconditions - The object exists
    // Postconditions - The subtype is returned (Ong in this case)
string Ong::ToString() {  return STR_ONG; }

// Name: FormatOutput()
    // Desc - A function that returns the formatted output for Output function
    // Preconditions - The object exists (use stringstream)
    // Postconditions - o, delimiter, isencrypted, delimiter,
    //                  message, delimiter, blank are output
string Ong::FormatOutput() {
    stringstream strStream;
    string objType(NUMCHAR, ISONG);
    strStream << objType << DELIMITER <<
        to_string(GetIsEncrypted()) << DELIMITER
        << GetMessage() << DELIMITER;
    return strStream.str();

}
