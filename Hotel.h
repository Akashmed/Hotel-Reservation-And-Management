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
    string guestName = "Guest";

public:
    Guest guest;
    void addRoom(int num, string type, double price)
    {
        rooms.push_back(Room(num, type, price));
    }

    void removeRoom(int num)
    {
        for (auto it = rooms.begin(); it != rooms.end(); ++it)
        {
            if (it->getRoomNumber() == num)
            {
                if (it->checkAvailability())
                {
                    rooms.erase(it);
                    cout << "Room " << num << " removed successfully!\n";
                }
                else
                {
                    cout << "Room is currently booked and cannot be removed!\n";
                }
                return;
            }
        }
        cout << "Room not found!\n";
    }

    void freeRoom(int num)
    {
        for (auto &room : rooms)
        {
            if (room.getRoomNumber() == num)
            {
                if (!room.checkAvailability())
                {
                    cout << "Room is currently occupied. Do you want to free it? (y/n): ";
                    char choice;
                    cin >> choice;
                    if (choice == 'y' || choice == 'Y')
                    {
                        room.freeRoom();
                        cout << "Room " << num << " is now available!\n";
                    }
                    else
                    {
                        cout << "Room " << num << " remains booked.\n";
                    }
                    return;
                }
                else
                {
                    cout << "Room is already available!\n";
                }
                return;
            }
        }
        cout << "Room not found!\n";
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
        else
        {
            cout << "\n All Bookings:\n";
            for (auto &booking : bookings)
            {
                booking.displayBooking();
            }
        }
    }

    void showBookingByGuestName()
    {
        if (guest.getLoggedIn() == false)
        {
            cout << "Oops, you're not logged in! Please login to continue" << endl;
            guest.authenticate();
        }
        if (guestName == "Guest")
        {
            cout << "Seems you don't have any bookings yet!" << endl;
            return;
        }
        else
        {
            cout << "\n Bookings for " << guestName << ":\n";
            for (auto &booking : bookings)
            {
                if (booking.getGuestName() == guestName)
                {
                    booking.displayBooking();
                }
            }
        }
    }
};

#endif
