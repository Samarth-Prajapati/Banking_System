#include "Bank.h"
void Bank::openAccount()
{
    bool isValid = true;
    string name;
    double balance;
    int defaultPin = 0000;
    cout << "--------------------------------" << endl;
    cout << "Enter your full name : " << endl;
    cin.ignore();
    getline(cin, name);
    for (char c : name)
    {
        if (!isalpha(c) && !isspace(c))
        {
            cout << "Invalid Name, Try again." << endl;
            isValid = false;
            break;
        }
    }
    if (!isValid)
    {
        isValid = true;
        return;
    }
    cout << "Enter initial balance ( Minimum Balance Limit Rs. 500 ) : " << endl;
    cin >> balance;
    if (balance < MIN_BALANCE)
    {
        cout << "Minimum Balance Limit Rs. 500 , Try again ." << endl;
        return;
    }
    totalAccounts++;
    accounts[totalAccounts] = Account(name, balance, totalAccounts);
    ofstream outFileData("database.txt", ios::app);
    outFileData << totalAccounts << " " << name << "," << balance << endl;
    outFileData.close();
    ofstream outFileHistory("accountHistory.txt", ios::app);
    outFileHistory << totalAccounts << " " << name << endl;
    outFileHistory.close();
    cout << "--------------------------------" << endl;
    cout << "Account created successfully ." << endl;
    cout << "Remember your debit card number and generate pin for your account orelse you cant be able to access your account money ." << endl;
    cout << "Your card number is : " << cardNumber << endl;
    card[totalAccounts] = Account(totalAccounts, name, cardNumber, defaultPin);
    ofstream outFilePin("accountPin.txt", ios::app);
    outFilePin << totalAccounts << " " << name << "," << cardNumber << " " << defaultPin << endl;
    outFilePin.close();
    cardNumber++;
    accounts[totalAccounts].display();
}
void Bank::deposit(int accountNumber, double amount, int pin)
{
    cout << "--------------------------------" << endl;
    if (accounts.find(accountNumber) == accounts.end())
    {
        cout << "Account Not Found ! " << endl;
        return;
    }
    else if (pin == 0000)
    {
        cout << "Please create pin for your account to access your account money ." << endl;
        return;
    }
    else if (pin != card[accountNumber].pin)
    {
        cout << "Invalid Pin , Try again ." << endl;
        return;
    }
    else
    {
        accounts[accountNumber].balance += amount;
        cout << "Amount Deposited Successfully ." << endl;
        cout << accounts[accountNumber].balance << " : Current Balance ." << endl;
        updateFile();
        return;
    }
    updateFile();
}
void Bank::withdraw(int accountNumber, double amount, int pin)
{
    cout << "--------------------------------" << endl;
    if (accounts.find(accountNumber) == accounts.end())
    {
        cout << "Account Not Found ! " << endl;
        return;
    }
    else if (pin == 0000)
    {
        cout << "Please create pin for your account to access your account money ." << endl;
        return;
    }
    else if (pin != card[accountNumber].pin)
    {
        cout << "Invalid Pin , Try again ." << endl;
        return;
    }
    else if (closedAccount[accountNumber] == true)
    {
        accounts[accountNumber].balance -= amount;
        cout << "Amount Withdrawn Successfully ." << endl;
        cout << accounts[accountNumber].balance << " : Current Balance ." << endl;
        if (accounts[accountNumber].balance != 0)
        {
            cout << accounts[accountNumber].balance << " Please withdraw this amount for closing your account ." << endl;
            updateFile();
            return;
        }
        else
        {
            cout << accounts[accountNumber].balance << " - Balance , Your Account is closed ." << endl;
            accounts.erase(accountNumber);
            closedAccount[accountNumber] = false;
            updateFile();
            return;
        }
    }
    else if (accounts[accountNumber].balance - amount < MIN_BALANCE)
    {
        cout << "Sorry Minimum balance 500 is required , try again with different values ." << endl;
        return;
    }
    else
    {
        accounts[accountNumber].balance -= amount;
        cout << "Amount Withdrawn Successfully ." << endl;
        cout << accounts[accountNumber].balance << " : Current Balance ." << endl;
        updateFile();
        return;
    }
    updateFile();
}
void Bank::balanceEnquiry(int accountNumber, int pin)
{
    cout << "--------------------------------" << endl;
    if (accounts.find(accountNumber) == accounts.end())
    {
        cout << "Account Not Found ! " << endl;
        return;
    }
    else if (pin == 0000)
    {
        cout << "Please create pin for your account to access your account money ." << endl;
        return;
    }
    else if (pin != card[accountNumber].pin)
    {
        cout << "Invalid Pin , Try again ." << endl;
        return;
    }
    cout << "Current Balance : " << accounts[accountNumber].balance << endl;
}
void Bank::closeAccount(int accountNumber, int pin)
{
    cout << "--------------------------------" << endl;
    if (accounts.find(accountNumber) == accounts.end())
    {
        cout << "Account Not Found ! " << endl;
        return;
    }
    else if (pin == 0000)
    {
        cout << "Please create pin for your account to access your account money ." << endl;
        return;
    }
    else if (pin != card[accountNumber].pin)
    {
        cout << "Invalid Pin , Try again ." << endl;
        return;
    }
    else if (accounts[accountNumber].balance != 0)
    {
        cout << "Account cannot be closed with balance , your account has been highlighted please withdraw your money and return back ." << endl;
        closedAccount[accountNumber] = true;
        updateFile();
        return;
    }
    else
    {
        accounts.erase(accountNumber);
        cout << "Account Closed Successfully ." << endl;
        updateFile();
    }
    updateFile();
}
void Bank::showAccounts()
{
    cout << "--------------------------------" << endl;
    ifstream inFile("database.txt");

    if (!inFile)
    {
        cout << "No accounts found!" << endl;
        return;
    }

    cout << "All Accounts: " << endl;
    cout << "--------------------------------" << endl;

    int accNo;
    string name;
    double balance;

    while (inFile >> accNo)
    {
        inFile.ignore();
        getline(inFile, name, ',');
        inFile >> balance;
        inFile.ignore();

        cout << "Account No: " << accNo << ", Name: " << name << ", Balance: " << balance << endl;
    }

    inFile.close();
}
void Bank::searchAccount(int accountNumber, int pin)
{
    cout << "--------------------------------" << endl;
    if (accounts.find(accountNumber) == accounts.end())
    {
        cout << "Account Not Found ! " << endl;
        return;
    }
    else if (pin == 0000)
    {
        cout << "Please create pin for your account to access your account money ." << endl;
        return;
    }
    else if (pin != card[accountNumber].pin)
    {
        cout << "Invalid Pin , Try again ." << endl;
        return;
    }
    cout << "Account Found : " << endl;
    accounts[accountNumber].display();
}
void Bank::createPin(int accountNumber, int pin)
{
    cout << "--------------------------------" << endl;
    if (accounts.find(accountNumber) == accounts.end())
    {
        cout << "Account Not Found ! " << endl;
        return;
    }
    else if (card[accountNumber].pin != 0000)
    {
        cout << "Pin already created for this account ." << endl;
        return;
    }
    else
    {
        card[accountNumber].pin = pin;
        cout << "Pin created successfully ." << endl;
        updateFile();
    }
    updateFile();
};
void Bank::changePin(int accountNumber, int pin, int newPin)
{
    cout << "--------------------------------" << endl;
    if (accounts.find(accountNumber) == accounts.end())
    {
        cout << "Account Not Found ! " << endl;
        return;
    }
    else if (card[accountNumber].pin == 0000)
    {
        cout << "Please create pin for your account to access your account money ." << endl;
        return;
    }
    else if (pin != card[accountNumber].pin)
    {
        cout << "Invalid Pin , Try again ." << endl;
        return;
    }
    else if (newPin == card[accountNumber].pin)
    {
        cout << "New Pin cannot be same as old pin ." << endl;
        return;
    }
    else
    {
        card[accountNumber].pin = newPin;
        cout << "Pin changed successfully ." << endl;
        updateFile();
    }
    updateFile();
};
void Bank::loadAccountsFromFile()
{
    ifstream inFileHistory("accountHistory.txt");
    if (!inFileHistory)
    {
        return;
    }
    int number, acc;
    string name1;
    while (inFileHistory >> number)
    {
        inFileHistory.ignore();
        getline(inFileHistory, name1);
        acc = number;
    }
    inFileHistory.close();
    ifstream inFileData("database.txt");
    if (!inFileData)
    {
        cout << "No existing accounts found." << endl;
        return;
    }

    int accNo;
    string name;
    double balance;

    while (inFileData >> accNo)
    {
        inFileData.ignore();

        getline(inFileData, name, ',');
        inFileData >> balance;

        accounts[accNo] = Account(name, balance, accNo);
        totalAccounts = acc;
    }
    inFileData.close();
    ifstream inFilePin("accountPin.txt");
    if (!inFilePin)
    {
        cout << "No existing accounts found." << endl;
        return;
    }

    int accN;
    string fname;
    long cardNum;
    int pin;
    while (inFilePin >> accN)
    {
        inFilePin.ignore();

        getline(inFilePin, fname, ',');
        inFilePin >> cardNum;
        inFilePin.ignore();
        inFilePin >> pin;
        card[accN] = Account(accN, fname, cardNum, pin);
        cardNumber = cardNum;
        totalAccounts = acc;
    }
    inFilePin.close();
}
void Bank::updateFile()
{
    ofstream outFile("database.txt");
    for (auto &pair : accounts)
    {
        outFile << pair.first << " " << pair.second.name << "," << pair.second.balance << endl;
    }
    outFile.close();
    ofstream outPin("accountPin.txt");
    for (auto &pair : card)
    {
        outPin << pair.first << " " << pair.second.name << "," << pair.second.cardNumber << " " << pair.second.pin << endl;
    }
    outPin.close();
}
