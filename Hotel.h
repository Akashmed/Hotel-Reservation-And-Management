#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <vector>
#include "Room.h"
#include "Booking.h"
using namespace std;

class Hotel
{
private:
    vector<Room> rooms;
    vector<Booking> bookings;

public:
    void addRoom(int num, string type, double price)
    {
        rooms.push_back(Room(num, type, price));
    }

    void showAvailableRooms()
    {
        for (auto &room : rooms)
        {
            if (room.checkAvailability())
                room.displayRoom();
        }
    }

    void showAllRooms()
    {
        cout << "\n All Rooms in Hotel:\n";
        for (auto &room : rooms)
        {
            room.displayRoom();
        }
    }

    void bookRoom()
    {
        string guestName;
        int roomNumber;
        cout << "Enter your name: ";
        cin >> guestName;
        cout << "Enter room number to book: ";
        cin >> roomNumber;

        for (auto &room : rooms)
        {
            if (room.getRoomNumber() == roomNumber && room.checkAvailability())
            {
                bookings.push_back(Booking(bookings.size() + 1, guestName, &room));
                bookings.back().confirmBooking();
                return;
            }
        }
        cout << "Room not available.\n";
    }

    void showAllBookings() {
        if (bookings.empty()) {
            cout << "\n No bookings found!\n";
            return;
        }
        
        cout << "\n📖 All Bookings:\n";
        for (auto &booking : bookings) {
            booking.displayBooking();
        }
    }

};

#endif
