#include "User.h"
#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;


// ================= USERNAME VALIDATION =================

bool User::validUsername(string username)
{
    // Minimum 4 characters
    if (username.length() < 4)
        return false;

    // Check every character
    for (char ch : username)
    {
        // Only letters, numbers and underscore allowed
        if (!isalnum(ch) && ch != '_')
            return false;
    }

    return true;
}


// ================= REGISTRATION =================

void User::registerUser()
{
    string confirmPassword;

    cout << "\n========== Registration ==========\n";

    // ---------- Username Validation ----------

    while (true)
    {
        cout << "Enter username: ";
        cin >> username;

        if (!validUsername(username))
        {
            cout << "\nInvalid username!\n";
            cout << "Username must:\n";
            cout << "- Have at least 4 characters\n";
            cout << "- Contain only letters, numbers or _\n\n";

            continue;
        }

        break;
    }


    // ---------- Check Duplicate Username ----------

    ifstream checkFile("user.txt");

    string fileUser, filePass;

    while (checkFile >> fileUser >> filePass)
    {
        if (username == fileUser)
        {
            cout << "\nUsername already exists!\n";
            checkFile.close();
            return;
        }
    }

    checkFile.close();


    // ---------- Password Validation ----------

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


    // ---------- Confirm Password ----------

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


    // ---------- Save User ----------

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


// ================= LOGIN =================

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
            username=user; // Set the username for the logged-in user
            password=pass; // Set the password for the logged-in user
            cout << "Login Successful!\n";
            file.close();
            return true;
        }
    }

    file.close();

    cout << "Login Failed!\n";
    return false;
}