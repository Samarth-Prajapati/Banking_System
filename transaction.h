#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
using namespace std;
class Transaction
{
public:
    int accountNumber;
    string name;
    double amount;
    string type;
    Transaction() {}
    Transaction(int accountNumber, string name, double amount, string type);
};
#endif