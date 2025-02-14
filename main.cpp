#include "Bank.h"
#include "Bank.cpp"
#include "Account.h"
#include "Account.cpp"
int main()
{
    cout << "---------Banking System---------" << endl;
    Bank bank;
    bank.loadAccountsFromFile();
    int choice1, accountNumber;
    double amount;
    do
    {
        cout << "--------------------------------" << endl;
        cout << " 1. Open an account\n 2. Balance Enquiry\n 3. Deposit\n 4. Withdraw\n 5. Close an account\n 6. Show all accounts\n 7. Exit" << endl;
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
            bank.balanceEnquiry(accountNumber);
            break;
        case 3:
            cout << "Enter Account Number : " << endl;
            cin >> accountNumber;
            cout << "Enter Amount : " << endl;
            cin >> amount;
            bank.deposit(accountNumber, amount);
            break;
        case 4:
            cout << "Enter Account Number : " << endl;
            cin >> accountNumber;
            cout << "Enter Amount : " << endl;
            cin >> amount;
            bank.withdraw(accountNumber, amount);
            break;
        case 5:
            cout << "Enter Account Number : " << endl;
            cin >> accountNumber;
            bank.closeAccount(accountNumber);
            break;
        case 6:
            bank.showAccounts();
            break;
        case 7:
            cout << "Thank You For Using Our Service." << endl;
            return 0;
        default:
            cout << "Invalid Choice" << endl;
            break;
        }
    } while (true);
}
