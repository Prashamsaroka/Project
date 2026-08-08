#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
class User
{
private:
    string username;
    string password;
    int n;

public:
    void registerUser()
    {
        ofstream file("user.txt", ios::app);
        cout << "Enter username dont give space: ";
      cin>>username;

        cout << "Enter password: ";
        cin >> password;
       cout << "Registration Successful!\n";
        file << username << " " << password << endl;
        file.close();
    }
 int login()
    {
        string user, pass;
        cout << "Username: ";
      cin>>user;

        cout << "Password: ";
        cin >> pass;
        //fstream file;
        //file.open("user.txt",ios::in);
        ifstream file("user.txt",ios::in);
        if (!file)
        {
            cout << "No registered users found.\n";
            return 0;
        }
        string fileUser,filePass;

        while (file >> fileUser >> filePass)
        {
            if (user == fileUser && pass == filePass)
            {
                cout << "Login Successful\n";
                file.close();
                
              
                return 1;
            }
        }
        cout << "Login Failed\n";
        file.close();
        return 0;
    }
    

	};
    int main(){
    	User a;
    	cout<<"--------------------------------------------------------"<<endl;
    	cout<<"--------------------------------------------------------"<<endl;
    	cout<<"Chose one"<<endl;
    	cout<<"--------------------------------------------------------"<<endl;
    	cout<<"--------------------------------------------------------"<<endl;
    	cout<<"1.sign up"<<endl;
    	cout <<"2.login in"<<endl;
    	cout<<"3.login"<<endl;
    	int n;
    	cin>>n;
    	if(n==1){
    		a.registerUser();
		}
		else if(n==2){
			a.login();
		}
		else{
			return 0;
		}
		return 0;
    	    }
    	
