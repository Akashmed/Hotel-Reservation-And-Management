#ifndef BOOKING_H
#define BOOKING_H

#include <iostream>
using namespace std;
#include "Room.h"

class Booking {
private:
    int bookingID;
    string guestName;
    Room* room;
    bool isPaid;
public:
    Booking(int id, string name, Room* r) 
        : bookingID(id), guestName(name), room(r), isPaid(false) {}

    void confirmBooking() {
        if (room->checkAvailability()) {
            room->bookRoom();
            cout << "Booking confirmed for " << guestName 
                      << " in Room " << room->getRoomNumber() << endl;
        } else {
            cout << "Room is not available!" << endl;
        }
    }

    void cancelBooking() {
        room->freeRoom();
        cout << "Booking canceled for " << guestName << endl;
    }

    void markPaid() { isPaid = true; }

    void displayBooking() {
        cout << "Booking ID: " << bookingID << " - " << guestName 
                  << " - Room " << room->getRoomNumber() 
                  << (isPaid ? " - Paid" : " - Pending") << endl;
    }
};

#endif
