#include <bits/stdc++.h>
using namespace std;

enum TransactionType
{
    WITHDRAW,
    DEPOSIT
};


class Transaction
{
private:
   static int transactionId;
    double transactionAmount;
    TransactionType tt;
    string time;
    string place;
    string device;

public:
    Transaction()
    {
    }

    Transaction(int id, double amount, Transaction t, string time, string place, string device)
    {
        transactionId = id++;
        amount = transactionAmount;

        this->time = time;
        this->place = place;
        this->device = device;
    }
};

int Transaction :: transactionId = 10011;

class Node
{
public:
    Transaction transdata;
    Node *next;
    Node *prev;

    Node()
    {
    }

    Node(Transaction transdata)
    {
        this->transdata = transdata;
        next = nullptr;
        prev = nullptr;
    }
};

class User
{
private:
    int userId;
    string username;
    string accountnumber;
    string bankname;
    string userDevice;
    string location;

    vector<Transaction> transaction;

public:
    User(int id, string name, string account, string bankname, string userDevice, string location)
    {
        userId = id;
        username = name;
        accountnumber = account;
        this->bankname = bankname;
        this->location = location;
        this->userDevice = userDevice;
    }

    string getuserDevice()
    {
        return userDevice;
    }

    string getlocation()
    {
        return location;
    }

    int getUserID()
    {
        return userId;
    }

    string getAccountNumber()
    {
        return accountnumber;
    }


    //need to addTrasnsaction method for specific user

    // display user Tranasction if he wants 
};

class TransactionOperation
{
public:
    Node *head;

    TransactionOperation()
    {
        head = nullptr;
    }

    void checkTransactions(string accnum, double Amount, string location, string currdevice, vector<User> userDetails);
};

void TransactionOperation :: checkTransactions(string accnum, double Amount, string location, string currdevice, vector<User> userDetails)
{
    for (auto x : userDetails)
    {
        if (x.getAccountNumber() == accnum)
        {

            if (Amount > 20000)
            {
                fraudInAmount(userDetails);
            }

            if (x.getlocation() != location)
            {
                fraudInLocation(userDetails, location);
            }

            if (x.getuserDevice() != currdevice)
            {
                fraudInDevice(userDetails, currdevice);
            }

            //need to add time fraud
            
            //add transaction;
            
        }
    }
}

int main()
{
    string accnum;
    string currdevice;
    string location;
    double Amount;

    vector<User> userDetails;

    userDetails.push_back(User(101, "Honour", "SBI123456", "STATE_BANK_OF_INDIA", "PC", "Nagpur"));
    userDetails.push_back(User(102, "Edward", "HDFC987654", "HDFC_BANK", "Mobile", "Hyderabad"));
    userDetails.push_back(User(103, "Arno", "ICICI763242", "ICICI_BANK", "PC", "Raipur"));
    userDetails.push_back(User(104, "Shay", "BOI343422", "BANK_OF_INDIA", "Tablet", "Pune"));
    userDetails.push_back(User(105, "Jacob", "UN987654", "UNION_BANK", "Mobile", "London"));
    userDetails.push_back(User(106, "Kassandra", "SBI1235678", "STATE_BANK_OF_INDIA", "Tablet", "Greece"));

    cout << "Welcome to Transaction" << endl;

    cout << "Enter the Account Number: ";
    cin >> accnum;

    cout << "Enter the amount to be withDraw: ";
    cin >> Amount;

    cout << "Enter the cuurent location:  ";
    cin >> location;

    cout << "Enter the current Device: ";
    cin >> currdevice;

    TransactionOperation tq;
    tq.checkTransactions(accnum, Amount, location, currdevice, userDetails);

    return 0;
}