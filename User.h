#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User
{
protected:
    string name;
    string username;
    string password;
    int count = 2;

public:
    virtual void displayInfo() = 0;

    string getUsername() { return username; }

    void createAccount()
    {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter a username: ";
        cin >> username;
        cout << "Enter a password: ";
        cin >> password;
        cout << "Account created successfully!" << endl;
    }

    bool authenticate();
    bool isAdmin()
    {
        if (username == "admin" && password == "admin")
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

    if (inputUsername == username && inputPassword == password)
    {
        cout << "Login successful!" << endl;
        return true;
    }
    else if (count > 0)
    {
        cout << "Invalid username or password. Please try again. " << count << " attempt left" << endl;
        count--;
        authenticate();
    }
    else
    {
        cout << "You have exceeded the maximum number of attempts. Please try again later." << endl;
        return false;
    }
}

class Guest : public User
{
public:
    void displayInfo() override
    {
        cout << "Guest Name: " << name << "\nUsername: " << username << endl;
    }
};

#endif
