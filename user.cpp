#include "User.h"
#include <iostream>
#include <fstream>

using namespace std;

void User::registerUser()
{
    string confirmPassword;
    
    cout << "\n========== Registration ==========\n";

    cout << "Enter username: ";
    cin >> username;

    // Check whether username already exists
    ifstream checkFile("user.txt");

    string fileUser, filePass;

    while (checkFile >> fileUser >> filePass)
    {
        if (username == fileUser)
        {
            cout << "Username already exists!\n";
            checkFile.close();
            return;
        }
    }

    checkFile.close();

    cout << "Enter password: ";
    cin >> password;

    cout << "Confirm password: ";
    cin >> confirmPassword;

    if (password != confirmPassword)
    {
        cout << "Passwords do not match!\n";
        return;
    }

    // Save user
    ofstream file("user.txt", ios::app);

    if (!file)
    {
        cout << "Error opening user file!\n";
        return;
    }

    file << username << " " << password << endl;

    file.close();

    cout << "Registration Successful!\n";
}


bool User::login()
{
    string user, pass;

    cout << "\n========== Login ==========\n";

    cout << "Username: ";
    cin >> user;

    cout << "Password: ";
    cin >> pass;

    ifstream file("user.txt");

    if (!file)
    {
        cout << "No registered users found.\n";
        return false;
    }

    string fileUser, filePass;

    while (file >> fileUser >> filePass)
    {
        if (user == fileUser && pass == filePass)
        {
            cout << "Login Successful!\n";
            file.close();
            return true;
        }
    }

    file.close();

    cout << "Login Failed!\n";
    return false;
}