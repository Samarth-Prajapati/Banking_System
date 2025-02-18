#include "Bank.h"
#include "Bank.cpp"
#include "Account.h"
#include "Account.cpp"
#include "transaction.h"
#include "transaction.cpp"
int main()
{
    cout << "---------Banking System---------" << endl;
    Bank bank;
    bank.loadAccountsFromFile();
    int choice1, accountNumber, pin, newPin, card;
    double amount;
    do
    {
        cout << "--------------------------------" << endl;
        cout << " 1. Open an account\n 2. Balance Enquiry\n 3. Deposit\n 4. Withdraw\n 5. Close an account\n 6. Show all accounts\n 7. Search Account\n 8. Create Pin\n 9. Change Pin\n 10. Transaction history\n 11. Exit" << endl;
        cout << "--------------------------------" << endl;
        cin >> choice1;
        switch (choice1)
        {
        case 1:
            bank.openAccount();
            break;
        case 2:
            cout << "Enter Account Number : " << endl;
            cin >> accountNumber;
            cout << "Enter Pin : " << endl;
            cin >> pin;
            bank.balanceEnquiry(accountNumber, pin);
            break;
        case 3:
            cout << "Enter Account Number : " << endl;
            cin >> accountNumber;
            cout << "Enter Amount : " << endl;
            cin >> amount;
            cout << "Enter Pin : " << endl;
            cin >> pin;
            bank.deposit(accountNumber, amount, pin);
            break;
        case 4:
            cout << "Enter Account Number : " << endl;
            cin >> accountNumber;
            cout << "Enter Amount : " << endl;
            cin >> amount;
            cout << "Enter Pin : " << endl;
            cin >> pin;
            bank.withdraw(accountNumber, amount, pin);
            break;
        case 5:
            cout << "Enter Account Number : " << endl;
            cin >> accountNumber;
            cout << "Enter Pin : " << endl;
            cin >> pin;
            bank.closeAccount(accountNumber, pin);
            break;
        case 6:
            bank.showAccounts();
            break;
        case 7:
            cout << "Enter Account Number : " << endl;
            cin >> accountNumber;
            cout << "Enter Pin : " << endl;
            cin >> pin;
            bank.searchAccount(accountNumber, pin);
            break;
        case 8:
            cout << "Enter Account Number : " << endl;
            cin >> accountNumber;
            cout << "Enter Card Number : " << endl;
            cin >> card;
            cout << "Create Pin : " << endl;
            cin >> pin;
            bank.createPin(accountNumber, card, pin);
            break;
        case 9:
            cout << "Enter Account Number : " << endl;
            cin >> accountNumber;
            cout << "Enter Pin : " << endl;
            cin >> pin;
            cout << "Enter New Pin : " << endl;
            cin >> newPin;
            bank.changePin(accountNumber, pin, newPin);
            break;
        case 10:
            cout << "Enter Account Number : " << endl;
            cin >> accountNumber;
            cout << "Enter Pin : " << endl;
            cin >> pin;
            bank.itransactionHistory(accountNumber, pin);
            break;
        case 11:
            cout << "Thank You For Using Our Service." << endl;
            return 0;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (true);
}
