#ifndef ROOM_H
#define ROOM_H

#include <iostream>
using namespace std;

class Room {
private:
    int roomNumber;
    string type;  // Single, Double, Suite
    double price;
    bool isAvailable;
public:
    Room(int num, string t, double p) 
        : roomNumber(num), type(t), price(p), isAvailable(true) {}

    void displayRoom() {
        cout << "Room " << roomNumber << " (" << type << ") - $" 
                  << price << " per night - " 
                  << (isAvailable ? "Available" : "Occupied") << endl;
    }

    bool checkAvailability() { return isAvailable; }
    void bookRoom() { isAvailable = false; }
    void freeRoom() { isAvailable = true; }

    int getRoomNumber() { return roomNumber; }
    double getPrice() { return price; }
};

#endif
