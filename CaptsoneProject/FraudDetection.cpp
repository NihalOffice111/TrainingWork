#include <bits/stdc++.h>
using namespace std;

class Transaction
{
private:
    static int transactionId;
    double transactionAmount;
    int transactiontime;
    string place;
    string device;

public:
    Transaction()
    {
    }

    Transaction(double amount, int transactiontime, string place, string device)
    {
        transactionId = getTransactionId();
        this->transactionAmount = amount;
        this->transactiontime = transactiontime;
        this->place = place;
        this->device = device;
    }

    static int getTransactionId()
    {
        return ++transactionId;
    }
    double getTransactionAmount()
    {
        return transactionAmount;
    }
    int getTransactionTime()
    {
        return transactiontime;
    }
    string getLocation()
    {
        return place;
    }
    string getDevice()
    {
        return device;
    }

    friend std::ostream &operator<<(std::ostream &os, const Transaction &tr);
};

std::ostream &operator<<(std::ostream &os, const Transaction &tr)
{
    os << "Transaction ID: " << tr.getTransactionId() << ", "
       << "Amount: " << tr.transactionAmount << ", "
       << "Time: " << tr.transactiontime << ", "
       << "Place: " << tr.place << ", "
       << "Device: " << tr.device;
    return os;
}

int Transaction ::transactionId = 10011;

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

static int nextUsedId = 1111;
class User
{
private:
    int userId;
    string username;
    string accountnumber;
    string bankname;
    string userDevice;
    string location;
    Node *head;

public:
    User()
    {
        head = nullptr;
    }
    User(string name, string account, string bankname, string userDevice, string location)
    {
        userId = getUserId();
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

    static int getUserId()
    {
        return ++nextUsedId;
    }

    string getAccountNumber()
    {
        return accountnumber;
    }

    void AddTransaction(Transaction tr)
    {
        cout << "Hello From Add trasnc " << endl;
        Node *newTransaction = new Node(tr);
        cout<<"AFter the newTrasaction "<<endl;

        if (head == nullptr)
        {
            cout << "Is head Null" << endl;
            head = newTransaction;
            
        }
        else
        {
            Node *temp = head;

            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newTransaction;
            newTransaction->prev = temp;
            cout << "Trasaction Added to History " << endl;
        }

        cout << "Current Transaction : " << endl;
        cout << newTransaction->transdata << endl;
        return;
    }

    // need to addTrasnsaction method for specific user

    // display user Tranasction if he wants

    void showHistory()
    {
        if (head == NULL)
        {
            cout << "No transaction hstory available " << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << "TransactionId : " << temp->transdata.getTransactionId() << endl;
            cout << "Transaction Amount : " << temp->transdata.getTransactionAmount() << endl;
            cout << "Transaction time : " << temp->transdata.getTransactionTime() << endl;
            cout << "Transaction location: " << temp->transdata.getLocation() << endl;
            cout << "Transaction device: " << temp->transdata.getDevice() << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

class TransactionOperation
{
public:
    Node *head;

    TransactionOperation()
    {
        head = nullptr;
    }

    void checkTransactions(User &uu, string accnum, double Amount, string location, string currdevice, int currenthour, vector<User> userDetails);
    bool fraudInAmount(vector<User> userDetails, double Amount);
    bool fraudInLocation(vector<User> userDetails, string location, double Amount);
    bool fraudInDevice(vector<User> userDetails, string currDevice, string Location, double Amount);
    bool fraudInTime(int currentHour);
};

void TransactionOperation ::checkTransactions(User &uu, string accnum, double Amount, string location, string currdevice, int currenthour, vector<User> userDetails)
{

    bool flagged = false;

    if (Amount > 20000)
    {
        if (!fraudInAmount(userDetails, Amount))
        {
            flagged = true;
        }
    }

    if (uu.getlocation() != location)
    {
        if (!fraudInLocation(userDetails, location, Amount))
        {
            flagged = true;
        }
    }

    if (uu.getuserDevice() != currdevice)
    {
        if (!fraudInDevice(userDetails, currdevice, location, Amount))
        {
            flagged = true;
        }
    }

    if (!fraudInTime(currenthour))
    {
        flagged = true;
    }

    // add transaction;

    if (flagged)
    {
        cout << "Fraud Detected Transaction Aborted " << endl;
    }
    else
    {

        Transaction tr(Amount, currenthour, location, currdevice);
        cout << "Transaction Successful" << endl;
        uu.AddTransaction(tr);
    }
}

bool TransactionOperation ::fraudInAmount(vector<User> userDetails, double Amount)
{
    char ch;
    cout << "Hello, Is this you doing transaction for amount Rs. " << Amount;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        return true;
    }
    else
    {
        cout << "A transaction exceeding the limit of Rs. 20000 has been attempted on your account by someone other than the account owner. Please review your account activity immediately.";
        return false;
    }
}

bool TransactionOperation ::fraudInLocation(vector<User> userDetails, string location, double Amount)
{
    char ch;
    cout << "Hello, Is this you doing transaction from Location = " << location << " for Amount = Rs. " << Amount;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        return true;
    }
    else
    {
        cout << "A transaction exceeding Rs. 20000 was attempted on your account by someone other than the account owner, from a different location.";
        return false;
    }
}

bool TransactionOperation ::fraudInDevice(vector<User> userDetails, string currDevice, string Location, double Amount)
{
    char ch;
    cout << "Hello, Is this you doing transaction from Device = " << currDevice << "form Location = " << Location << " for Amount = Rs. " << Amount;
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        return true;
    }
    else
    {
        cout << "A transaction exceeding Rs. 20000 was attempted on your account by someone other than the account owner, from a different location and device.";
        return false;
    }
}

bool TransactionOperation ::fraudInTime(int currentHour)
{

    if (currentHour >= 0 && currentHour <= 5)
    {
        char ch;
        cout << "Hello, Is this you doing a transaction at this time (current time is " << currentHour << " hours)?\n";
        cout << "The transaction is happening outside normal hours (12 AM to 5 AM).\n";
        cout << "Is this transaction legitimate? (y/n): ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
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
    string uname;
    string userAccountnumber;
    string bankname;
    string trustedDevice;
    string trustedlocation;

    string accnum;
    string currdevice;
    string location;
    double Amount;
    int count = 0;

    vector<User> userDetails;
    char ch;
    int choice;
    User user;
    User uu;
    string tempnum;

    time_t now;
    tm *ltm;
    int currentHour;

    cout << "***********************************************************MAIN MENU**************************************************************" << endl;
    cout << "1. ADD NEW USER " << endl;
    cout << "2. DO TRANSACTIONS " << endl;
    cout << "3. SHOW TRANSACTION HISTORY " << endl;
    cout << "4. EXIT " << endl;

    do
    {
        cout << "Enter the choice from the Main Menu " << endl;
        cin >> choice;
        TransactionOperation tq;


        switch (choice)
        {
        case 1:
            // cout << "Enter the User  Detials  " << endl;
            // cout << "Enter the Name : ";
            // cin >> uname;
            // cout << "Enter user Account number : ";
            // cin >> userAccountnumber;
            // cout << "Enter user bankname : ";
            // cin >> bankname;
            // cout << "Enter user trusted Device : ";
            // cin >> trustedDevice;
            // cout << "Enter user trusted location: ";
            // cin >> trustedlocation;

            // userDetails.push_back(User(uname, userAccountnumber, bankname, trustedDevice, trustedlocation));
            // cout << "User Details Registered " << endl;
            // break;

            userDetails.push_back(User("Honour", "SBI123456", "STATE_BANK_OF_INDIA", "PC", "Nagpur"));
            userDetails.push_back(User("Edward", "HDFC987654", "HDFC_BANK", "Mobile", "Hyderabad"));
            userDetails.push_back(User("Arno", "ICICI763242", "ICICI_BANK", "PC", "Raipur"));
            userDetails.push_back(User("Shay", "BOI343422", "BANK_OF_INDIA", "Tablet", "Pune"));
            userDetails.push_back(User("Jacob", "UN987654", "UNION_BANK", "Mobile", "London"));
            userDetails.push_back(User("Kassandra", "SBI1235678", "STATE_BANK_OF_INDIA", "Tablet", "Greece"));
            break;

        case 2:

            cout << "Welcome to Transaction" << endl;

            do
            {
                cout << "Enter the Account number :";
                cin >> accnum;
                for (auto &x : userDetails)
                {
                    if (x.getAccountNumber() == accnum)
                    {
                        uu = x;
                        tempnum = x.getAccountNumber();
                        break;
                    }
                }

                count++;

            } while (tempnum != accnum && count != 3);

            if (count == 3)
            {
                cout << "Your Account has been blocked for 24hrs for not Entering Correct Account number " << endl;
                exit(0);
            }

            cout << "Enter the amount to be withDraw: ";
            cin >> Amount;

            cout << "Enter the cuurent location:  ";
            cin >> location;

            cout << "Enter the current Device: ";
            cin >> currdevice;

            now = time(0);
            ltm = localtime(&now);
            currentHour = ltm->tm_hour;

            tq.checkTransactions(uu, accnum, Amount, location, currdevice, currentHour, userDetails);

            break;


        case 3:
            cout << "Showing Transaction History " << endl;
            cout<<"Enter the Account ID : ";
            cin>>userAccountnumber;
            User u;
            for(auto x : userDetails){
                if(x.getAccountNumber() == userAccountnumber){
                    u = x;
                    u.showHistory();
                    break;
                }
            }
           
                
            
            
            break;
        }

        cout << "Do you want to Continue " << endl;
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');
}
