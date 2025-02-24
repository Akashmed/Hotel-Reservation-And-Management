#ifndef USER_H
#define USER_H

#include <iostream>
#include <string>
using namespace std;

class User {
protected:
    string name;
    string username;
    string password;
public:
    User(string uname, string pass, string n = "") 
        : username(uname), password(pass), name(n) {}

    virtual void displayInfo() = 0;
    
    string getUsername() { return username; }
    bool authenticate(string uname, string pass) {
        return (username == uname && password == pass);
    }
};

class Guest : public User {
public:
    Guest(string uname, string pass, string n)
        : User(uname, pass, n) {}

    void displayInfo() override {
        cout << "Guest Name: " << name << "\nUsername: " << username << endl;
    }
};

#endif
