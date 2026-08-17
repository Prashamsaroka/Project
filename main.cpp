#include <iostream>
#include <limits>
#include "user.h"
#include "Encryption.h"

using namespace std;

int main()
{
    int n;
    User u;
    do
    {
        cout << "\n========== Secure Data Vault ==========" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> n))
        {
            cout << "Invalid choice!\n";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        switch (n)
        {
        case 1:
            u.registerUser();
            break;

        case 2:
            if (u.login())
            {
                Encryption e(u.getUsername()); // Pass the logged-in username to Encryption
                int choice;
                do
                {
                    cout << "\n===== Dashboard =====\n";
                    cout << "1. Encrypt Data\n";
                    cout << "2. Decrypt Data\n";
                    cout << "3. Logout\n";
                    cout << "Enter your choice: ";

                    if (!(cin >> choice))
                    {
                        cout << "Invalid choice!\n";

                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');

                        continue;
                    }
                    switch (choice)
                    {
                    case 1:
                        // Encrypt
                         e.encryptdata();
                        break;

                    case 2:
                        // Decrypt
                        e.decryptdata();
                        break;

                    case 3:
                        cout << "Logged out.\n";
                        break;

                    default:
                        cout << "Invalid choice.\n";
                    }

                } while (choice != 3);
            }
            break;

        case 3:
            cout << "Thank you!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
            break;
        }

    } while (n != 3);

    return 0;
}