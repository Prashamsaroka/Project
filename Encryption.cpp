#include "Encryption.h"
#include <iostream>
#include <fstream>
#include <limits>

using namespace std;


// Default constructor
      Encryption::Encryption()
       {
         activeUsername = "";
       }
// Parameterized constructor using the basic method
       Encryption::Encryption(string username) 
        {
          activeUsername = username;
        }
        string Encryption:: Encrypt(string text, string userkey)
        {
        if (userkey.empty())
        {
          return text;
        }
          for (size_t i = 0; i < text.length(); i++)
           {
             text[i] = text[i] + userkey[i % userkey.length()];
           }
          return text;
       }
       // Vigenere-style Cipher Decryption using a string key
       string Encryption::Decrypt(string text,string userkey)
        {
         if (userkey.empty()) return text;
          for (size_t i = 0; i < text.length(); i++) 
          {
        text[i] = text[i] - userkey[i % userkey.length()];
          }
         return text;
       }
        void Encryption::encryptdata()
         {
        string key;
        string plainText;

        cout << "\nEnter string key for encryption: ";
        cin >> key;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline buffer

        cout << "Enter text/details to encrypt: ";
        getline(cin, plainText);

        string encryptedText = Encrypt(plainText, key);

        // Open specific file for this logged-in user: vault_<username>.txt
        string fileName = "vault_" + activeUsername + ".txt";
        ofstream vaultFile(fileName, ios::app);
        
        if (vaultFile.is_open())
         {
            vaultFile << encryptedText << endl;
            vaultFile.close();
            cout << "Encrypted data successfully saved to " << fileName << "!\n";
         } 
        else
        {
            cout << "Could not open the file to save data.\n";
        }
    }

    // Read and decrypt the encrypted data from the logged-in user's file
        void Encryption::decryptdata()
        {
             string key;
             cout << "\nEnter string key for decryption: ";
             cin >> key;
             cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline buffer
             string fileName = "vault_" + activeUsername + ".txt";
             ifstream vaultFile(fileName, ios::in);

           if (!vaultFile)
        {
            cout << "No saved encrypted data found for user '" << activeUsername << "'.\n";
            return;
        }

        string encryptedLine;
        cout << "\n--- Decrypted Vault Items for " << activeUsername << " ---\n";
        int count = 1;
        while (getline(vaultFile, encryptedLine))
         {
            if (!encryptedLine.empty()) 
            {
                string decryptedText = Decrypt(encryptedLine, key);
                cout << count++ << ". " << decryptedText << endl;
            }
        }
        vaultFile.close();
    }
