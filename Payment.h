#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
using namespace std;

class Payment {
private:
    double amount;
    bool status; // true = paid, false = pending
public:
    Payment(double amt) : amount(amt), status(false) {}

    void processPayment() {
        status = true;
        cout << "Payment of $" << amount << " received.\n";
    }

    bool isPaid() { return status; }
};

#endif
