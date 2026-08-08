#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <string>
using namespace std;

class Encryption
{
public:
    string encrypt(string text, int key);
    string decrypt(string text, int key);
};

#endif