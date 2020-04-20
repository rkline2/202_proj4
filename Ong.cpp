/*****************************************
** File:    Ong.cpp
** Project: CMSC 202 Project 4, Spring 2020
** Author:  Rooklyn Kline
** Date:    4/21/20
** Section: 02
** E-mail:  rkline2@umbc.edu
**
** This file contains the derived class "Ong".
** The primary functions are to encrypt, decrypt, and
** format a given message from the base class.
**
***********************************************/
#include "Ong.h"
#include <iostream>
using namespace std;

// Ong (Default Constructor)
    // Creates a Ong cipher to be encrypted
Ong::Ong() {}

// Ong (Overloaded Constructor)
    // Given the message and isEncrypted, creates a Ong cipher to be encrypted
Ong::Ong(string message, bool isEncrypted) :Cipher(message, isEncrypted) {}

// Ong (Destructor)
    // Anything specific to Ong is destroyed
Ong::~Ong() {}


// IsVowel 
    // Given the char, returns true or false if it's a vowel
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

// Encrypt
    // Uses Ong encryption to manipulate the message
void Ong::Encrypt() {
    string newMessage = GetMessage();
    bool lastLetter = true;
    int messageSize = newMessage.length();
    char nextChar;

    for (int i = messageSize - 1; i >= 0; i--) {
        char x = newMessage.at(i);
        // if the char is a letter
        if (((x <= MAX_UP_C_VAL) && (x >= MIN_UP_C_VAL)) ||
            ((x <= MAX_LOW_C_VAL) && (x >= MIN_LOW_C_VAL))) {
            // if it's the last letter of the sentence only
            if (lastLetter) {
                // if it's not a vowel
                if (!IsVowel(x)) {
                    newMessage.insert(i + 1, ONG);
                }
                lastLetter = false;
            }
            // if the char is not the last letter 
            else {
                // checks if the current char is a vowel
                // and if the next char is a letter or not 
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

// Decrypt
    // Removes the dashes and "ong" when necessary
void Ong::Decrypt() {
    string newMessage = GetMessage();
    for (int i = 0; i < newMessage.length(); i++) {
        char x = newMessage.at(i);
        if (x == DASH_C) {
            newMessage.erase(i, 1);
        }
        x = newMessage.at(i);
        // if the char is a letter 
        if (((x <= MAX_UP_C_VAL) && (x >= MIN_UP_C_VAL)) ||
            ((x <= MAX_LOW_C_VAL) && (x >= MIN_LOW_C_VAL))) {
            if (!IsVowel(x)) {
                newMessage.erase(i + 1, ONG.size());
            }
        }
        SetMessage(newMessage);
    }
}

// ToString
    // returns the string of the object type
string Ong::ToString() { return STR_ONG; }

// FormatOutput()
    // returns the formatted output for Output function
string Ong::FormatOutput() {
    stringstream strStream;
    strStream << ISONG << DELIMITER <<
        GetIsEncrypted() << DELIMITER
        << GetMessage() << DELIMITER;
    return strStream.str();

}
