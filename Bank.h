#ifndef BANK_H
#define BANK_H
#include "Account.h"
#include <iostream>
#include <map>
#include <fstream>
#define MIN_BALANCE 500
using namespace std;
class Bank
{
private:
    static int totalAccounts;
    map<long, Account> accounts;
    map<int, bool> closedAccount;

public:
    Bank() {}
    void loadAccountsFromFile();
    void updateFile();
    void openAccount();
    void deposit(int accountNumber, double amount);
    void withdraw(int accountNumber, double amount);
    void balanceEnquiry(int accountNumber);
    void closeAccount(int accountNumber);
    void showAccounts();
};
int Bank::totalAccounts = 0;
#endif