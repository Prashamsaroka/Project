#include "User.h"
#include <iostream>
#include <fstream>
#include <cctype>

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

    // Password validation
    while (true)
    {
        cout << "\nPassword requirements:\n";
        cout << "- At least 8 characters\n";
        cout << "- At least 1 uppercase letter\n";
        cout << "- At least 1 lowercase letter\n";
        cout << "- At least 1 digit\n";
        cout << "- At least 1 special character\n\n";

        cout << "Enter password: ";
        cin >> password;

        bool hasUpper = false;
        bool hasLower = false;
        bool hasDigit = false;
        bool hasSpecial = false;

        for (char ch : password)
        {
            if (isupper(ch))
                hasUpper = true;

            else if (islower(ch))
                hasLower = true;

            else if (isdigit(ch))
                hasDigit = true;

            else
                hasSpecial = true;
        }

        if (password.length() >= 8 &&
            hasUpper &&
            hasLower &&
            hasDigit &&
            hasSpecial)
        {
            break;
        }

        cout << "\nWeak password!\n";
        cout << "Please enter a stronger password.\n";
    }

    // Confirm password
    while (true)
    {
        cout << "Confirm password: ";
        cin >> confirmPassword;

        if (password == confirmPassword)
        {
            break;
        }

        cout << "Passwords do not match!\n";
        cout << "Please try again.\n";
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

    cout << "\nRegistration Successful!\n";
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