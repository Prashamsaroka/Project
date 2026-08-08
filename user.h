#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User
{
private:
    string username;
    string password;
    bool validUsername(string username);
public:
    void registerUser();
    bool login();
};

#endif