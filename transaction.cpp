#include "transaction.h"
Transaction::Transaction(int accountNumber, string name, double amount, string type)
{
    this->accountNumber = accountNumber;
    this->name = name;
    this->amount = amount;
    this->type = type;
}