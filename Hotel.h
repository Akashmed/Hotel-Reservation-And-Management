#ifndef HOTEL_H
#define HOTEL_H

#include <iostream>
#include <vector>
#include "Room.h"
#include "User.h"
#include "Payment.h"
#include "Booking.h"
using namespace std;

class Hotel
{
private:
    vector<Room> rooms;
    vector<Booking> bookings;

public:
    Guest guest;
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

        if (guest.getLoggedIn() == false)
        {
            cout << "Oops, you're not logged in! Please login to continue" << endl;
            guest.authenticate();
        }
        string guestName;
        int roomNumber;
        cout << "\n Book a Room:\n";
        cout << "------------------------\n";
        cout << "Enter your name: ";
        cin >> guestName;
        cout << "Enter room number to book: ";
        cin >> roomNumber;

        for (auto &room : rooms)
        {
            if (room.getRoomNumber() == roomNumber && room.checkAvailability())
            {
                cout << "Room is reserved for " << guestName << endl;
                bookings.push_back(Booking(bookings.size() + 1, guestName, &room));
                cout << "Payable amount of room " << roomNumber << " is $" << room.getPrice() << endl
                     << "Confirm booking? (y/n): ";
                char choice;
                cin >> choice;
                if (choice == 'y' || choice == 'Y')
                {
                    Payment payment(room.getPrice());
                    payment.processPayment();
                    bookings.back().markPaid();
                    bookings.back().confirmBooking();
                    bookings.back().displayBooking();
                }
                else
                {
                    bookings.back().cancelBooking();
                    cout << "Booking canceled!\n";
                }
                return;
            }
        }
        cout << "Room not available.\n";
    }

    void showAllBookings()
    {
        if (bookings.empty())
        {
            cout << "\n No bookings found!\n";
            return;
        }

        cout << "\n All Bookings:\n";
        for (auto &booking : bookings)
        {
            booking.displayBooking();
        }
    }
};

#endif
