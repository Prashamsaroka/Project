#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
using namespace std;

class Encryption
{
private:
    string activeUsername;

public:
    Encryption();
    Encryption(string username);

    string Encrypt(string text, string userkey);
    string Decrypt(string text, string userkey);

    void encryptdata();
    void decryptdata();
};

#endif