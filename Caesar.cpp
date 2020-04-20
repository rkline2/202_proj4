/*****************************************
** File:    Caesar.cpp
** Project: CMSC 202 Project 4, Spring 2020
** Author:  Rooklyn Kline
** Date:    4/21/20
** Section: 02
** E-mail:  rkline2@umbc.edu
**
** This file contains the derived class "Caesar".
** The primary functions are to encrypt, decrypt, and
** format a given message from the base class.
**
***********************************************/
#include "Caesar.h"
#include <iostream>
using namespace std;

// Caesar (Default Constructor)
    // Creates a Caesar cipher to be encrypted
Caesar::Caesar() { m_shift = DEFAULTSHIFT; }

// Caesar (Overloaded Constructor)
    // Given a message, isEncrypted, and shift. It creates a Caesar cipher to be encrypted
Caesar::Caesar(string message, bool isEncrypted, int shift) :Cipher(message, isEncrypted) {
    m_shift = shift;
}

// Caesar (Destructor)
    // Postconditions - Destroys anything specific to Caesar
Caesar::~Caesar() { m_shift = NULL; }

// Encrypt
    // Shifts each character to the right based on shift value
void Caesar::Encrypt() {
    int modShift = 0;
    string newMessage = GetMessage();
    int messageSize = newMessage.length();

    for (int i = 0; i < messageSize; i++) {
        char x = newMessage.at(i);
        if (((x <= MAX_UP_C_VAL) && (x >= MIN_UP_C_VAL)) ||
            ((x <= MAX_LOW_C_VAL) && (x >= MIN_LOW_C_VAL))) {

            // uppercase letters only 
            if (isupper(x)) {
                // converts x to range 0-26
                x -= MIN_UP_C_VAL;
                modShift = (x + m_shift) % MAX_CHAR;

                // if char is out of A-Z range 
                if (x + m_shift >= MAX_CHAR) {
                    x = MIN_UP_C_VAL + modShift;
                    newMessage.at(i) = x;
                }

                else {
                    // converts to ascii format
                    x += MIN_UP_C_VAL;
                    x += m_shift;
                    newMessage.at(i) = x;
                }
            }

            // lowercase letters only
            else {
                // converts x to range 0-26
                x -= MIN_LOW_C_VAL;
                modShift = (x + m_shift) % MAX_CHAR;

                // if char is out of A-Z range
                if (x + m_shift >= MAX_CHAR) {
                    x = MIN_LOW_C_VAL + modShift;
                    newMessage.at(i) = x;
                }

                else {
                    // converts to ascii format
                    x += MIN_LOW_C_VAL;
                    x += m_shift;
                    newMessage.at(i) = x;
                }
            }
            SetMessage(newMessage);
        }

    }

}

// Decrypt
    // Shifts each character to the left based on shift value
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
                x -= MIN_UP_C_VAL;
                testVal = (x - m_shift) % MAX_CHAR;

                // if char is out of A-Z range 
                if (testVal < 0) {
                    x = (MAX_UP_C_VAL + testVal) + 1;
                    newMessage.at(i) = x;
                }

                else {
                    // converts to ascii format
                    x += MIN_UP_C_VAL;
                    x -= m_shift;
                    newMessage.at(i) = x;
                }
            }

            // lowercase letters only
            else {
                x -= MIN_LOW_C_VAL;
                testVal = (x - m_shift) % MAX_CHAR;

                // if char is out of A-Z range
                if (testVal < 0) {
                    x = (MAX_LOW_C_VAL + testVal) + 1;
                    newMessage.at(i) = x;
                }

                else {
                    // converts to ascii format
                    x += MIN_LOW_C_VAL;
                    x -= m_shift;
                    newMessage.at(i) = x;
                }
            }
            SetMessage(newMessage);
        }

    }
}

// ToString
    // Returns the subtype of class Caesar 
string Caesar::ToString() { return STR_CAESAR; }

// FormatOutput
   // Returns the formatted output for the Output function
string Caesar::FormatOutput() {
    stringstream strStream;
    strStream << ISCAESAR << DELIMITER <<
        GetIsEncrypted() << DELIMITER << GetMessage()
        << DELIMITER << m_shift;
    return strStream.str();
}

