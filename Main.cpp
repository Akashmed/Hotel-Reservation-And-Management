#include <iostream>
using namespace std;
#include "User.h"
#include "Room.h"
#include "Booking.h"

int main()
{
    Guest guest1;
    guest1.createAccount();
    cout << "Please login to your account" << endl;
    guest1.authenticate();

    cout << "is admin :" << guest1.isAdmin() << endl;
    Room room1(101, "Single", 100);
    Room room2(102, "Double", 150);
    room1.displayRoom();
    room2.displayRoom();

    Booking booking1(1, "Alice", &room1);
    Booking booking2(2, "Bob", &room2);
    booking1.confirmBooking();
    booking2.confirmBooking();
    cout << "Room info after booking" << endl;
    room1.displayRoom();
    room2.displayRoom();
    return 0;
}