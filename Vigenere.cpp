/*****************************************
** File:    Vigenere.cpp
** Project: CMSC 202 Project 4, Spring 2020
** Author:  Rooklyn Kline
** Date:    4/21/20
** Section: 02
** E-mail:  rkline2@umbc.edu
**
** This file contains the derived class "Vigenere".
** The primary functions are to encrypt, decrypt, and
** format a given message from the base class.
**
***********************************************/
#include "Vigenere.h"
#include <iostream>
using namespace std;

// Vigenere (Default Constructor)
    // Creates a Vigenere cipher to be encrypted
Vigenere::Vigenere() { m_key = DEFAULTKEY; }

// Vigenere (Overloaded Constructor)
    // Given the the message, isEncrypted, and key, creates a Vigenere cipher to be encrypted
Vigenere::Vigenere(string message, bool isEncrypted, string key) :Cipher(message, isEncrypted) { m_key = key; }

// Vigenere (Destructor)
    // Deletes anything specific to Vigenere
Vigenere::~Vigenere() { m_key.erase(); }

// Encrypt
    // Encrypts using key
void Vigenere::Encrypt() {
    string newMessage = GetMessage();
    char keyChar;
    int shift = 0;
    int keyVal = 0;
    int messageSize = newMessage.length();

    for (int i = 0; i < messageSize; i++) {
        char x = newMessage.at(i);
        // if the char is a letter 
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

// Decrypt
    // Uses key to decrypt.
void Vigenere::Decrypt() {
    string newMessage = GetMessage();
    char keyChar;
    int shift = 0;
    int keyVal = 0;
    int messageSize = newMessage.length();

    for (int i = 0; i < messageSize; i++) {
        char x = newMessage.at(i);
        // if the char is a letter 
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

// ToString
    // Returns the string of the object type
string Vigenere::ToString() { return STR_VIGEN; }

// FormatOutput 
    // Returns the formatted output for Output function
string Vigenere::FormatOutput() {
    stringstream strStream;
    strStream << ISVIGEN << DELIMITER <<
        GetIsEncrypted() << DELIMITER << GetMessage()
        << DELIMITER << m_key;
    return strStream.str();
}
