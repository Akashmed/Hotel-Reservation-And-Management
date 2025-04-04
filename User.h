#ifndef USER_H
#define USER_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User
{
protected:
    string username;
    string password;
    int count = 2;
    bool loggedIn;

public:
    virtual void displayInfo() = 0;

    string getUsername() { return username; }

    void createAccount()
    {
        cout << "Enter your name: ";
        cin >> username;
        cout << "Enter a password: ";
        cin >> password;

        ofstream file("users.txt", ios::app); // append mode
        if (file.is_open())
        {
            file << username << " " << password << endl;
            file.close();
            cout << "Account created successfully!" << endl;
            loggedIn = true;
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
    }

    bool authenticate();
    bool isAdmin()
    {
        string adminName, adminPass;
        cout << "Enter admin username: ";
        cin >> adminName;
        cout << "Enter admin password: ";
        cin >> password;
        if (adminName == "admin" && adminPass == "admin")
        {
            return true;
        }
    }
};

bool User::authenticate()
{
    string inputUsername, inputPassword;
    cout << "Enter your username: ";
    cin >> inputUsername;
    cout << "Enter your password: ";
    cin >> inputPassword;

    ifstream file("users.txt");
    string fileUsername, filePassword;

    if (file.is_open())
    {
        while (file >> fileUsername >> filePassword)
        {
            if (fileUsername == inputUsername && filePassword == inputPassword)
            {
                cout << "-------------Login successful!--------------" << endl;
                loggedIn = true;
                cout << "Welcome, " << fileUsername << "!" << endl;
                file.close();
                return true;
            }
        }
        file.close();
    }
    else
    {
        cout << "Error opening file!" << endl;
        return false;
    }

    // Retry logic
    if (count > 1)
    {
        count--;
        cout << "Invalid username or password. Please try again. " << count << " attempts left." << endl;
        return authenticate(); // recursive retry
    }
    else
    {
        cout << "You have exceeded the maximum number of attempts. Want to create an account? (y/n)" << endl;
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            createAccount();
            return true;
        }
        else
        {
            cout << "Exiting..." << endl;
            return false;
        }
    }
}

class Guest : public User
{
public:
    void displayInfo() override
    {
        cout << "Guest Name: " << username << endl;
    }

    bool getLoggedIn()
    {
        return loggedIn;
    };
};

#endif
