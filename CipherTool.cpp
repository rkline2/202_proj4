#include "CipherTool.h"
#include <iomanip>
#include <iostream>
using namespace std;

// Name: CipherTool Constructor
    // Desc - Creates a new CipherTool and sets m_filename based on string passed
    // Preconditions - Input file passed and populated with Cipher
    // Postconditions - CipherTool created
CipherTool::CipherTool(string filename) {
    m_filename = filename;
}

// Name: CipherTool Destructor
    // Desc - Calls destructor for all ciphers in m_ciphers
    // Preconditions - m_ciphers is populated
    // Postconditions - m_ciphers emptied
CipherTool::~CipherTool() {}

// Name: LoadFile
    // Desc - Opens file and reads in each Cipher. Each Cipher dynamically allocated
    // and put into m_ciphers
    // Preconditions - Input file passed and populated with Ciphers
    // Postconditions - m_ciphers populated with Ciphers
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
    cout << isEncrypted << endl << message << endl;
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

// Name: DisplayCiphers
    // Desc - Displays each of the ciphers in the m_ciphers
    // Preconditions - Input file passed and m_ciphers populated
    // Postconditions - Displays ciphers
void CipherTool::DisplayCiphers() {}

// Name: EncryptDecrypt
    // Desc - Encrypts or decrypts each of the ciphers in the m_ciphers
    // Preconditions - Input file passed and m_ciphers populated
    // Postconditions - Either Encrypts or Decrypts each cipher in m_ciphers
void CipherTool::EncryptDecrypt(bool) {}

// Name: Export
    // Desc - Exports each of the ciphers in the m_ciphers (so they can be reused)
    // Preconditions - Input file passed and m_ciphers populated
    // Postconditions - All ciphers exported
void CipherTool::Export() {}

// Name: Menu
    // Desc - Displays menu and returns choice
    // Preconditions - m_ciphers all populated
    // Postconditions - Returns choice
//int CipherTool::Menu() {}

// Name: GetType
    // Desc - Pass it a cipher and it returns the char of the subtype
    // Returns c for Caesar, v for Vigenere, and o for Ong
    // Preconditions - m_ciphers all populated
    // Postconditions - Returns char of type
//char CipherTool::GetType(Cipher*) {}

// Name: Start
   // Desc - Loads input file, allows user to choose what to do
   // Preconditions - m_ciphers populated with ciphers
   // Postconditions - none
void CipherTool::Start() {
    LoadFile();
}

/*
    vector<Cipher*> m_ciphers; //List of all Ciphers
    string m_filename; //Name of the file passed from proj4.cpp
*/
