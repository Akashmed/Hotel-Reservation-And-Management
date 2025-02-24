#include <iostream>
using namespace std;
#include "User.h"

int main()
{
    Guest guest1("john_doe", "1234", "John Doe");
    guest1.displayInfo();

    bool a = guest1.authenticate("john_doe", "1234");
    cout << a << endl;

    return 0;
}