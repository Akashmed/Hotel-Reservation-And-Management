#include <iostream>
using namespace std;
#include "User.h"

int main()
{
    Guest guest1;
    guest1.createAccount();
    cout<<"Please login to your account"<<endl;
    guest1.authenticate();
    return 0;
}