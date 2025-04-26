#include <iostream>
using namespace std;
#include "User.h"
#include "Room.h"
#include "Booking.h"
#include "Hotel.h"
#include "Payment.h"

Hotel myHotel;
Guest guest;

int adminPanel()
{

    int choice;
    int roomNumber;
    string roomType;
    double roomPrice;

    do
    {
        cout << "\n ADMIN PANEL";
        cout << "\n ----------------- \n";
        cout << "1. View All Rooms\n";
        cout << "2. Add a Room\n";
        cout << "3. Remove a Room\n";
        cout << "4. Free a Room\n";
        cout << "5. Show Available Rooms\n";
        cout << "6. View All Bookings\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            myHotel.showAllRooms();
            break;
        case 2:
            cout << "Enter room number: ";
            cin >> roomNumber;
            cout << "Enter room type: ";
            cin >> roomType;
            cout << "Enter room price: ";
            cin >> roomPrice;
            myHotel.addRoom(roomNumber, roomType, roomPrice);
            cout << "Room added successfully!\n";
            break;
        case 3:
            cout << "Enter room number to remove: ";
            cin >> roomNumber;
            myHotel.removeRoom(roomNumber);
            break;
        case 4:
            cout << "Enter room number to free: ";
            cin >> roomNumber;
            myHotel.freeRoom(roomNumber);
            break;
        case 5:
            cout << "\n Available Rooms:\n";
            myHotel.showAvailableRooms();
            break;
        case 6:
            myHotel.showAllBookings();
            break;
        case 7:
            cout << " Exiting Admin Panel... Thank you!\n";
            break;
        default:
            cout << " Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 7);
    return 0;
}

int UserPanel()
{

    // Add some rooms
    myHotel.addRoom(101, "Single", 50.0);
    myHotel.addRoom(102, "Double", 75.0);
    myHotel.addRoom(103, "Suite", 120.0);

    int choice;

    do
    {
        cout << "\n HOTEL MANAGEMENT SYSTEM";
        cout << "\n ----------------------------- \n";
        cout << "1. View All Rooms\n";
        cout << "2. View Available Rooms\n";
        cout << "3. Book a Room\n";
        cout << "4. View My Bookings\n";
        cout << "5. Cancel Booking\n";
        cout << "6. Create an account\n";
        cout << "7. Login\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            myHotel.showAllRooms();
            break;
        case 2:
            cout << "\n Available Rooms:\n";
            myHotel.showAvailableRooms();
            break;
        case 3:
            myHotel.bookRoom();
            break;
        case 4:
            myHotel.showBookingByGuestName();
            break;
        case 5:
            myHotel.cancelBooking();
            break;
        case 6:
            myHotel.createAccount();
            break;
        case 7:
            myHotel.authenticate();
            break;
        case 8:
            cout << " Exiting... Thank you!\n";
            break;
        case 9:
            cout << "Please verify to access admin panel\n";
            if (guest.isAdmin())
            {
                cout << "Access granted to admin panel\n";
                adminPanel();
            }
            else
            {
                cout << "Access denied! You are not an admin.\n";
                break;
            }
            break;
        default:
            cout << " Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 8);

    return 0;
}

int main()
{
    UserPanel();
    return 0;
}