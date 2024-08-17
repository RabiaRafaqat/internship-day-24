#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;

void createAccount(string accountNumbers[], string names[], double balances[], int& numAccounts);
void depositMoney(string accountNumbers[], double balances[], int numAccounts);
void withdrawMoney(string accountNumbers[], double balances[], int numAccounts);
void checkBalance(string accountNumbers[], double balances[], int numAccounts);
int findAccountIndex(string accountNumbers[], int numAccounts, string accountNumber);

int main() {
    string accountNumbers[MAX_ACCOUNTS];
    string names[MAX_ACCOUNTS];
    double balances[MAX_ACCOUNTS] = {0.0};
    int numAccounts = 0;
    int choice;

    while (true) {
        cout << "\nBanking System Menu:" << endl;
        cout << "1. Create a new account" << endl;
        cout << "2. Deposit money" << endl;
        cout << "3. Withdraw money" << endl;
        cout << "4. Check balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Please enter your choice (1-5): ";
        
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
                createAccount(accountNumbers, names, balances, numAccounts);
                break;
            case 2:
                depositMoney(accountNumbers, balances, numAccounts);
                break;
            case 3:
                withdrawMoney(accountNumbers, balances, numAccounts);
                break;
            case 4:
                checkBalance(accountNumbers, balances, numAccounts);
                break;
            case 5:
                cout << "Thank you for using the banking system. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please select a number between 1 and 5." << endl;
                break;
        }
    }

    return 0;
}

void createAccount(string accountNumbers[], string names[], double balances[], int& numAccounts) {
    if (numAccounts >= MAX_ACCOUNTS) {
        cout << "Sorry, the account limit has been reached. Cannot create more accounts." << endl;
        return;
    }

    cout << "Enter a new account number: ";
    getline(cin, accountNumbers[numAccounts]);

    cout << "Enter the account holder's name: ";
    getline(cin, names[numAccounts]);

    cout << "Enter the initial balance: ";
    double initialBalance;
    cin >> initialBalance;
    cin.ignore();  

    if (initialBalance < 0) {
        cout << "Initial balance cannot be negative. Setting balance to $0." << endl;
        initialBalance = 0;
    }

    balances[numAccounts] = initialBalance;
    numAccounts++;
    cout << "Account created successfully!" << endl;
}

void depositMoney(string accountNumbers[], double balances[], int numAccounts) {
    cout << "Enter the account number to deposit into: ";
    string accountNumber;
    getline(cin, accountNumber);

    int index = findAccountIndex(accountNumbers, numAccounts, accountNumber);
    if (index == -1) {
        cout << "Account number not found. Please check and try again." << endl;
        return;
    }

    cout << "Enter the amount to deposit: ";
    double amount;
    cin >> amount;
    cin.ignore();  

    if (amount <= 0) {
        cout << "Deposit amount must be positive." << endl;
        return;
    }

    balances[index] += amount;
    cout << "Deposit successful. New balance: $" << balances[index] << endl;
}

void withdrawMoney(string accountNumbers[], double balances[], int numAccounts) {
    cout << "Enter the account number to withdraw from: ";
    string accountNumber;
    getline(cin, accountNumber);

    int index = findAccountIndex(accountNumbers, numAccounts, accountNumber);
    if (index == -1) {
        cout << "Account number not found. Please check and try again." << endl;
        return;
    }

    cout << "Enter the amount to withdraw: ";
    double amount;
    cin >> amount;
    cin.ignore();  

    if (amount <= 0) {
        cout << "Withdrawal amount must be positive." << endl;
        return;
    }

    if (amount > balances[index]) {
        cout << "Insufficient funds. Please enter a smaller amount." << endl;
        return;
    }

    balances[index] -= amount;
    cout << "Withdrawal successful. New balance: $" << balances[index] << endl;
}

void checkBalance(string accountNumbers[], double balances[], int numAccounts) {
    cout << "Enter the account number to check the balance: ";
    string accountNumber;
    getline(cin, accountNumber);

    int index = findAccountIndex(accountNumbers, numAccounts, accountNumber);
    if (index == -1) {
        cout << "Account number not found. Please check and try again." << endl;
        return;
    }

    cout << "Current balance for account number " << accountNumber << " is: $" << balances[index] << endl;
}

int findAccountIndex(string accountNumbers[], int numAccounts, string accountNumber) {
    for (int i = 0; i < numAccounts; ++i) {
        if (accountNumbers[i] == accountNumber) {
            return i;
        }
    }
    return -1;  
}
