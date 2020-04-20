/*****************************************
** File:    CipherTool.cpp
** Project: CMSC 202 Project 4, Spring 2020
** Author:  Rooklyn Kline
** Date:    4/21/20
** Section: 02
** E-mail:  rkline2@umbc.edu
**
** This file contains the class "CipherTool".
** This class helps out the base class "Cipher" by
** receiving the messages from a .txt file and storing  
** it in a vevtor. It's the primary class for the user to 
** interact to the program. 
***********************************************/
#include "CipherTool.h"
#include <iomanip>
#include <iostream>
using namespace std;

// CipherTool (Constructor)
    // Creates a new CipherTool and sets m_filename based on string passed
CipherTool::CipherTool(string filename) {
    m_filename = filename;
}

// CipherTool (Destructor)
    // m_ciphers is emptied
CipherTool::~CipherTool() {
    m_filename.erase();
    for (unsigned int i = 0; i != m_ciphers.size(); i++) {
        delete m_ciphers.at(i);
    }
    m_ciphers.clear();
    
}

// LoadFile
    // m_ciphers is populated with Ciphers
void CipherTool::LoadFile() {
    char cipherType;
    string isEncrypted;
    string message;
    string shift;

    ifstream file;
    file.open(m_filename);
    
    while (file >> cipherType) {
    Cipher* cipherPtr;

    file.ignore(256,DELIMITER);
    getline(file, isEncrypted, DELIMITER);
    getline(file, message, DELIMITER);

    if (cipherType == ISCAESAR){
        getline(file,shift);
        cipherPtr = new Caesar(message, stoi(isEncrypted), stoi(shift));
    }

    else if (cipherType == ISVIGEN) {
        getline(file, shift);
        cipherPtr = new Vigenere(message, stoi(isEncrypted), shift);
    }

    else if (cipherType == ISONG) {
        cipherPtr = new Ong(message, stoi(isEncrypted));
    }

    m_ciphers.push_back(cipherPtr);
    
    }
    file.close();
}

// DisplayCiphers
    // Displays each of the ciphers in the m_ciphers
void CipherTool::DisplayCiphers() {
    for (unsigned int i = 0; i != m_ciphers.size(); i++) {
        cout << i + 1 << ". " << *m_ciphers.at(i) << endl << endl;
    }
}

// EncryptDecrypt
    // Either Encrypts or Decrypts each cipher in m_ciphers
void CipherTool::EncryptDecrypt(bool encrypt) {
    int num = 0;
    // for encryption only
    if (encrypt) {
        for (unsigned int i = 0; i != m_ciphers.size(); i++) {
            // if the cipher is not encrypted
            if (!m_ciphers.at(i)->GetIsEncrypted()) {
                m_ciphers.at(i)->Encrypt();
                m_ciphers.at(i)->ToggleEncrypted();
                num++;
            }
        }
        cout << num << " ciphers Encrypted" << endl;
    }
    // for decryption only 
    else {
        for (unsigned int i = 0; i != m_ciphers.size(); i++) {
            // if the cipher is encrypted
            if (m_ciphers.at(i)->GetIsEncrypted()) {
                m_ciphers.at(i)->Decrypt();
                m_ciphers.at(i)->ToggleEncrypted();
                num++;
            }
        }
        cout << num << " ciphers Decrypted" << endl;
    }
}

// Export
    // Exports each of the ciphers in the m_ciphers (so they can be reused)
void CipherTool::Export() {
    string newFilename = "*.txt";
    cout << "What would you like the file name to be?: ";
    cin >> newFilename;

    ofstream newFile(newFilename);
    for (unsigned int i = 0; i != m_ciphers.size(); i++) {
    newFile << m_ciphers.at(i)->FormatOutput() << '\n';
    }
    newFile.close();
}

// Menu
    // Displays menu and returns user choice
int CipherTool::Menu() {
    int usrInput = 0;
    cout << "What would you like to do?" << endl;
    cout << "1. Display All Ciphers" << endl;
    cout << "2. Encrypt All Ciphers" << endl;
    cout << "3. Decrypt All Ciphers" << endl;
    cout << "4. Export All Ciphers" << endl;
    cout << "5. Quit" << endl;
    cin >> usrInput;
    cout << endl;
    return usrInput;
}

// GetType
    // Given a cipher, returns char of cipher type
char CipherTool::GetType(Cipher* cipherPtr) {
    if (dynamic_cast<Caesar*>(cipherPtr)) { return ISCAESAR; }

    else if (dynamic_cast<Ong*>(cipherPtr)) { return ISONG; }

    else if (dynamic_cast<Vigenere*>(cipherPtr)) { return ISVIGEN; }
    
    return -1;

}

// Start
   // Loads input file, allows user to choose what to do
void CipherTool::Start() {
    LoadFile();
    int usrChoice = Menu();
    while (usrChoice != QUIT) {
        switch (usrChoice){
        case DISPLAY:
            DisplayCiphers();
            break;
        case ENCRYPT:
            EncryptDecrypt(true);
            break;
        case DECRYPT:
            EncryptDecrypt(false);
            break;
        case EXPORT:
            Export();
            break;
        default:
            break;
        }
        usrChoice = Menu();

    }
    cout << "Thanks for using UMBC Encryption" << endl;
   
}

