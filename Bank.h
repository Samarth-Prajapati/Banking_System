#ifndef BANK_H
#define BANK_H
#include "Account.h"
#include "transaction.h"
#include <iostream>
#include <map>
#include <fstream>
#define MIN_BALANCE 500
#define PINLENGTH 4
using namespace std;
class Bank
{
private:
    static int totalAccounts;
    static long cardNumber;
    map<long, Account> accounts;
    map<int, bool> closedAccount;
    map<int, Account> card;
    map<int, Transaction> transactionHistory;

public:
    Bank() {}
    void loadAccountsFromFile();
    void updateFile();
    void openAccount();
    void deposit(int accountNumber, double amount, int pin);
    void withdraw(int accountNumber, double amount, int pin);
    void balanceEnquiry(int accountNumber, int pin);
    void closeAccount(int accountNumber, int pin);
    void showAccounts();
    void searchAccount(int accountNumber, int pin);
    void createPin(int accountNumber, int pin);
    void changePin(int accountNumber, int pin, int newPin);
    void itransactionHistory(int accountNumber, int pin);
    void showTransactionHistory();
};
int Bank::totalAccounts = 0;
long Bank::cardNumber = 999;
#endif