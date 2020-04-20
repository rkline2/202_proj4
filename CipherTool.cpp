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
CipherTool::~CipherTool() {
    m_filename.erase();
    for (unsigned int i = 0; i != m_ciphers.size(); i++) {
        delete m_ciphers.at(i);
    }
    m_ciphers.clear();
    
}

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
void CipherTool::DisplayCiphers() {
    for (unsigned int i = 0; i != m_ciphers.size(); i++) {
        cout << i + 1 << ". " << *m_ciphers.at(i) << endl << endl;
    }
}

// Name: EncryptDecrypt
    // Desc - Encrypts or decrypts each of the ciphers in the m_ciphers
    // Preconditions - Input file passed and m_ciphers populated
    // Postconditions - Either Encrypts or Decrypts each cipher in m_ciphers
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

// Name: Export
    // Desc - Exports each of the ciphers in the m_ciphers (so they can be reused)
    // Preconditions - Input file passed and m_ciphers populated
    // Postconditions - All ciphers exported
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

// Name: Menu
    // Desc - Displays menu and returns choice
    // Preconditions - m_ciphers all populated
    // Postconditions - Returns choice
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

// Name: GetType
    // Desc - Pass it a cipher and it returns the char of the subtype
    // Returns c for Caesar, v for Vigenere, and o for Ong
    // Preconditions - m_ciphers all populated
    // Postconditions - Returns char of type
char CipherTool::GetType(Cipher* cipherPtr) {
    if (dynamic_cast<Caesar*>(cipherPtr)) { return ISCAESAR; }

    else if (dynamic_cast<Ong*>(cipherPtr)) { return ISONG; }

    else if (dynamic_cast<Vigenere*>(cipherPtr)) { return ISVIGEN; }
    
    return -1;

}

// Name: Start
   // Desc - Loads input file, allows user to choose what to do
   // Preconditions - m_ciphers populated with ciphers
   // Postconditions - none
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

/*
    vector<Cipher*> m_ciphers; //List of all Ciphers
    string m_filename; //Name of the file passed from proj4.cpp
*/
