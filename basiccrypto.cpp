#include <iostream>
#include <string>

using namespace std;

// The correct key remains confidential inside the system
const int REAL_SECRET_KEY = 4;

//Encryption function 
string Encrypt(string text,int userkey)

{
    for(int i=0;i<text.length();i++)
    {
        text[i]=text[i]+userkey;
    }
    return text;
}
        // Decryption function
string decrypt(string text, int userKey) {
    for (int i = 0; i < text.length(); i++) {
        text[i] = text[i] - userKey; // Shifts down by whatever number the user inputs
    }
    return text;
}

int main() {
    int choice;
     cout<<"choice 1 for decryption\n";
    cout<<"choice 2 for encryption\n";
    cout<<"enter your choice: ";
    cin>>choice;
    if(choice==1)
    {
        int enteredkey;
        cout<<"enter the key for decryption:";
        cin>>enteredkey;
        string encrypted_text;
        cout<<"enter the encrypted text:";
        cin>>encrypted_text;
        string decrypted_result=decrypt(encrypted_text,enteredkey);
        cout<<"decrypted result is:"<<decrypted_result<<endl;
        if(enteredkey==REAL_SECRET_KEY)
        {
            cout<<"decryption successful\n";
        }
        else{
           cout<<"decryption failed\n";
        }
        }
     else if(choice==2)
     {
        int enteredkey;
        cout<<"enter the key for encryption:";
        cin>>enteredkey;
        string decrypted_text;
        cout<<"enter the decrypted text:";
        cin>>decrypted_text;
        string encrypted_result=Encrypt(decrypted_text,enteredkey);
        cout<<"encrypted result is "<<encrypted_result<<endl;
        if(enteredkey==REAL_SECRET_KEY)
        {
            cout<<"encryption successful\n";
        }
        else{
           cout<<"encryption failed\n";
        }
     }
     else{
            cout<<"invalid choice\n";
     }
    return 0;
}
