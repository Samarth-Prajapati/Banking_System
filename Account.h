#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using namespace std;
class Account
{
private:
    string name;
    double balance;
    int accountNumber, pin;
    long cardNumber;

public:
    Account() {};
    Account(int accountNumber, string name, long cardNumber, int pin);
    Account(string name, double balance, int accountNumber);
    void display();
    friend class Bank;
};
#endif