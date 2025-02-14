#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>
using namespace std;
class Account
{
private:
    string name;
    double balance;
    int accountNumber;

public:
    Account() {}
    Account(string name, double balance, int accountNumber);
    void display();
    friend class Bank;
};
#endif