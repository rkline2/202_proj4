/*****************************************
** File:    Cipher.cpp
** Project: CMSC 202 Project 4, Spring 2020
** Author:  Rooklyn Kline
** Date:    4/21/20
** Section: 02
** E-mail:  rkline2@umbc.edu
**
** This file contains the base class "Cipher".
** This class contains the message and if the cipher 
** has been encrypted or not for every cipher. 
** The primary functions from this class are the getters 
** and setters for the m variables. 
**
***********************************************/
#include "Cipher.h"
#include <iostream>
using namespace std;

// Cipher (Default Constructor)
    // A message is stored in a Cipher object
Cipher::Cipher() {
    m_message = "test";
    m_isEncrypted = 0;
}

// Cipher (Overloaded Constructor)
    // Given the message and if it's encrypted, 
    // the message and isEncrypted is stored in a Cipher object
Cipher::Cipher(string message, bool isEncrypted) {
    m_message = message;
    m_isEncrypted = isEncrypted;
}

// ~Cipher (Destructor)
    // A base class is deleted
Cipher::~Cipher() {
    m_isEncrypted = false;
    m_message.erase();
}

// GetMessage
    // A message is returned
string Cipher::GetMessage() { return m_message; }

// GetIsEncrypted
    // returns a bool if the message is encrypted or not
bool Cipher::GetIsEncrypted() { return m_isEncrypted; }

// SetMessage
    // Given a new message, the message is updated
void Cipher::SetMessage(string message) { m_message = message; }

// ToggleEncrypted
    // Turns m_isEncrypted (true to false) or (false to true)
void Cipher::ToggleEncrypted() {
    if (m_isEncrypted) { m_isEncrypted = false; }
    else { m_isEncrypted = true; }
}

// Overloaded << Operator
    // Given the object, the formatted message from the object is returned
ostream& operator<<(ostream& output, Cipher& C) {
    if (C.GetMessage().at(0) == QUOTE) {
        return output << C.GetMessage() << " (" << C.ToString() << ")";
    }
    else { 
        return output << "\"" << C.GetMessage() << "\"" << " (" << C.ToString() << ")"; 
    }   
}
