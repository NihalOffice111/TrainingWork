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
    tm time;
    string place;
    string device;

public:
    Transaction()
    {
    }

    Transaction(int id, double amount, TransactionType t, string place, string device, tm time)
    {
        transactionId = id++;
        amount = transactionAmount;
        this->time = time;
        this->tt = t;
        this->place = place;
        this->device = device;
    }
    tm getTransactionTime()
    {
        return time;
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
                if(fraudInAmount(userDetails, Amount))
                {
                    
                }
                else
                {
                    break;
                }
            }

            if (x.getlocation() != location)
            {
                if(fraudInLocation(userDetails, location, Amount))
                {

                }
                else
                {
                    break;
                }
            }

            if (x.getuserDevice() != currdevice)
            {
                if(fraudInDevice(userDetails, currdevice, location, Amount))
                {

                }
                else
                {
                    break;
                }
            }

            if(fraudInTime())
            {
                
            }
            else
            {
                break;
            }
            
            //add transaction;
            
        }
    }
}

bool fraudInAmount(vector<User> userDetails, double Amount)
{
    char ch;
    cout<<"Hello, Is this you doing transaction for amount Rs. "<<Amount;
    cin>>ch;
    if(ch == 'y' || ch == 'Y')
    {
        return true;
    }
    else
    {
        cout<<"A transaction exceeding the limit of Rs. 20000 has been attempted on your account by someone other than the account owner. Please review your account activity immediately.";
        return false;
    }
}

bool fraudInLocation(vector<User> userDetails, string location, double Amount)
{
    char ch;
    cout<<"Hello, Is this you doing transaction from Location = "<<location<<" for Amount = Rs. "<<Amount;
    cin>>ch;
    if(ch == 'y' || ch == 'Y')
    {
        return true;
    }
    else
    {
        cout<<"A transaction exceeding Rs. 20000 was attempted on your account by someone other than the account owner, from a different location.";
        return false;
    }
}

bool fraudInDevice(vector<User> userDetails, string currDevice, string Location, double Amount)
{
    char ch;
    cout<<"Hello, Is this you doing transaction from Device = "<<currDevice<<"form Location = "<<Location<<" for Amount = Rs. "<<Amount;
    cin>>ch;
    if(ch == 'y' || ch == 'Y')
    {
        return true;
    }
    else
    {
        cout<<"A transaction exceeding Rs. 20000 was attempted on your account by someone other than the account owner, from a different location and device.";
        return false;
    }
}

bool fraudInTime()
{
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentHour = ltm->tm_hour;
    if(currentHour >= 0 || currentHour <= 5)
    {
        char ch;
        cout << "Hello, Is this you doing a transaction at this time (current time is " << currentHour << " hours)?\n";
        cout << "The transaction is happening outside normal hours (9 AM to 9 PM).\n";
        cout << "Is this transaction legitimate? (y/n): ";
        cin >> ch;
        if(ch =='y' || ch =='Y')
        {
            return true;
        }
        else
        {
            cout << "Transaction marked as suspicious due to time of transaction.\n";
            return false;
        }
    }
    return true;
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