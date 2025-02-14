#include "Account.h"
Account::Account(int accountNumber, string name, long cardNumber, int pin = 0000)
{
    this->accountNumber = accountNumber;
    this->name = name;
    this->cardNumber = cardNumber;
    this->pin = pin;
}
Account::Account(string name, double balance, int accountNumber)
{
    this->name = name;
    this->balance = balance;
    this->accountNumber = accountNumber;
}
void Account::display()
{
    cout << "Account Number : " << this->accountNumber << endl;
    cout << "Name : " << this->name << endl;
    cout << "Balance : " << this->balance << endl;
}