#include <iostream>
using namespace std;
#include "User.h"

int main()
{
    Guest guest1("istiak_ahmed", "123456", "Istiak Ahmed");
    guest1.displayInfo();

    bool a = guest1.authenticate("istiak_ahmed", "123456");
    cout << a << endl;

    return 0;
}