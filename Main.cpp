#include <iostream>
using namespace std;
#include "User.h"
#include "Room.h"
#include "Booking.h"
#include "Hotel.h"
#include "Payment.h"

int UserPanel()
{
    Hotel myHotel;

    // Add some rooms
    myHotel.addRoom(101, "Single", 50.0);
    myHotel.addRoom(102, "Double", 75.0);
    myHotel.addRoom(103, "Suite", 120.0);

    int choice;

    do
    {
        cout << "\n HOTEL MANAGEMENT SYSTEM \n";
        cout << "1. View All Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. View All Bookings\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            myHotel.showAllRooms();
            break;
        case 2:
            myHotel.bookRoom();
            break;
        case 3:
            myHotel.showAllBookings();
            break;
        case 4:
            cout << " Exiting... Thank you!\n";
            break;
        default:
            cout << " Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 4);

    return 0;
}

int main()
{
    UserPanel();

    // Guest guest1;
    // guest1.createAccount();
    // cout << "Please login to your account" << endl;
    // guest1.authenticate();

    // cout << endl
    //      << "is admin :" << guest1.isAdmin() << endl;
    

    // Payment payment1(100.10);
    // payment1.processPayment();
    // cout << "Payment status: " << (payment1.isPaid() ? "Paid" : "Pending") << endl;
    // return 0;
}