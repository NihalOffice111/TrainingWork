#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

class BankAccount {
protected:
    int accountNumber;         // Unique account number
    string accountHolder;      // Name of the account holder
    double balance;            // Account balance

public:
    // Constructor
    BankAccount(int accNum, string holder, double initialBalance)
        : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {
        cout << "BankAccount created for " << accountHolder << " with initial balance $" << balance << endl;
    }

    // Method to deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << ". New balance: $" << balance << endl;
        } else {
            cout << "Deposit amount must be positive!" << endl;
        }
    }

    // Method to withdraw money from the account
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds. Withdrawal of $" << amount << " failed." << endl;
        } else if (amount <= 0) {
            cout << "Withdrawal amount must be positive!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: $" << amount << ". New balance: $" << balance << endl;
        }
    }

    // Method to display account information
    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Balance: $" << balance << endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    int getBalance() {
        return balance;
    }
};

class BankBranch {
private:
    string branchName;
    string branchAddress;
    vector<BankAccount> accounts;

public:
    BankBranch(const string& name, const string& address) :
        branchName(name), branchAddress(address) {}

    void addAccount(int accountNum, const string& accountName, double balance) {
        BankAccount newAcc(accountNum, accountName, balance);
        accounts.push_back(newAcc);
        cout << "Account created for " << accountName << " with account number: " << accountNum << endl;
    }

    // Find an account number
    BankAccount* findAccount(int accountNum) {
        for (auto& account : accounts) {
            if (account.getAccountNumber() == accountNum) {
                return &account;
            }
        }
        cout << "Account number: " << accountNum << " not found." << endl;
        return nullptr;
    }

    // Display all accounts
    void displayAllAccs() const {
        cout << "All bank accounts: " << endl;
        for (const auto& account : accounts) {
            account.display();
        }
    }

    string getBranch() const {
        return branchName;
    }
};

class BankSystem {
private:
    //vector<BankBranch> branches;
    vector<vector<BankAccount>> branches;

public:

    BankSystem(int noOfBranches){
        branches.resize(noOfBranches);
    }
    // Add new branch to the system
    // void addBranch(const string& branchName, const string& branchAddress) {
    //     branches.emplace_back(branchName, branchAddress);
    //     cout << "Branch created: " << branchName << endl;
    // }

    void addAccountToBranch(int branchIndex , BankAccount account){
        if(branchIndex < branches.size()){
            branches[branchIndex].push_back(account);

        }
        else{
            cout<<"Branch index out of range "<<endl;
        }
    }

    void depositToAccount(int branchIndex , int accountNumber , double amount){
        if(branchIndex < branches.size()){
            for(auto account : branches[branchIndex]){
                if(account.getAccountNumber() == accountNumber){
                    account.deposit(amount);
                    cout<<"Depoisted Amount IS "<<amount<<" Total Balance: "<<account.getBalance()<<endl;
                    return;
                }
                else{
                    cout<<"Please Enter the correct Account Number "<<endl;
                }
                
            }
        }
        else{
            cout<<"Please Give Correct Index Number "<<endl;
        }
    }

    void withDrawFromAccount(int branchIndex , int accountNumber , double amount){
         if(branchIndex < branches.size()){
            for(auto account : branches[branchIndex]){
                if(account.getAccountNumber() == accountNumber){
                    account.deposit(amount);
                    cout<<"Withdraw Amount IS "<<amount<<" Total Balance: "<<account.getBalance()<<endl;
                    return;
                }
                else{
                    cout<<"Please Enter the correct Account Number "<<endl;
                }
                
            }
        }
        else{
            cout<<"Please Give Correct Index Number "<<endl;
        }
    }






    // BankBranch* findBranch(const string& name) {
    //     for (auto& branch : branches) {
    //         if (branch.getBranch() == name) {
    //             return &branch;
    //         }
    //     }
    //     cout << "Branch: " << name << " not found." << endl;
    //     return nullptr;
    // }

    // Display all branches
    // void displayAllBranches() const {
    //     cout << "Bank Branches: " << endl;
    //     for (const auto& branch : branches) {
    //         cout << "Branch Name: " << branch.getBranch() << endl;
    //         branch.displayAllAccs();
    //         cout << endl;
    //     }
    // }
};

int main() {
    // BankSystem bank;
    // bank.addBranch("HitechCity", "Opposite HitechCity");
    // bank.addBranch("Jubilee Hills", "Road No 45");

    // BankBranch* branch1 = bank.findBranch("Jubilee Hills");
    // if (branch1) {
    //     branch1->addAccount(123456, "ABC", 10000);
    //     branch1->addAccount(87684364, "User3", 300);
    //     branch1->addAccount(7647343, "user4", 90000);
    // }
    // bank.displayAllBranches();

    // if (branch1) {
    //     BankAccount* account = branch1->findAccount(123456);
    //     if (account) {
    //         account->deposit(3000);
    //         account->display();
    //         account->withdraw(6000.00);
    //     }
    // }


    return 0;
}
