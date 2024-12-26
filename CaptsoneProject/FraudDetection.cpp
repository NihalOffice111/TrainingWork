#include <bits/stdc++.h>
using namespace std;
//
class Transaction
{
private:
    static int transactionIdCounter;
    int transactionId;
    double transactionAmount;
    int transactiontime;
    string place;
    string device;
    double riskfactor;

public:
    Transaction() {}

    Transaction(double amount, int transactiontime, string place, string device, double risk)
    {
        transactionId = ++transactionIdCounter;
        this->transactionAmount = amount;
        this->transactiontime = transactiontime;
        this->place = place;
        this->device = device;
        this->riskfactor = risk;
    }

    int getTransactionId()
    {
        return transactionId;
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

    double getriskFactor()
    {
        return riskfactor;
    }

    friend ostream &operator<<(ostream &os, const Transaction &tr);
};

ostream &operator<<(ostream &os, const Transaction &tr)
{
    os << "Transaction ID: " << tr.transactionId << ", "
       << "Amount: " << tr.transactionAmount << ", "
       << "Time: " << tr.transactiontime << ", "
       << "Place: " << tr.place << ", "
       << "Device: " << tr.device << ", "
       << "Risk: " << tr.riskfactor;
    return os;
}

int Transaction:: transactionIdCounter = 10011;

class Node
{
public:
    Transaction transdata;
    Node *next;
    Node *prev;

    Node() {}

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
    double totalTransactionAmount;
    int transactionCount;

public:
    User()
    {
        head = nullptr;
        totalTransactionAmount = 0.0;
        transactionCount = 0;
    }

    User(string name, string account, string bankname, string userDevice, string location)
    {
        userId = getUserId();
        username = name;
        accountnumber = account;
        this->bankname = bankname;
        this->location = location;
        this->userDevice = userDevice;
        head = nullptr;
    }

    string getUserName(){
        return username;
    }

    string getbankName(){
        return bankname;
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

    


    double getAverageTransactionAmount()
    {
        if (transactionCount == 0)
        {
            return 0.0;
        }
        return totalTransactionAmount / transactionCount;
    }

    void AddTransaction(Transaction tr)
    {
        Node *newTransaction = new Node(tr);

        if (head == nullptr)
        {
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
        }

        totalTransactionAmount = totalTransactionAmount + tr.getTransactionAmount();
        transactionCount++;

        cout << "Current Transaction: " << endl;
        cout << newTransaction->transdata << endl;
    }

    double calculateAverageRisk()
    {
        if (head == nullptr)
        {
            return 0.0;
        }

        Node *temp = head;
        double totalRisk = 0.0;
        int count = 0;

        while (temp != nullptr)
        {
            totalRisk += temp->transdata.getriskFactor();
            count++;
            temp = temp->next;
        }

        return count > 0 ? totalRisk / count : 0.0;
    }

    void findUserDetails(User &user){
        cout<<"Name : "<< user.getUserName()<<endl;
        cout<<"Account Number : "<<user.getbankName()<<endl;
        cout<<"User ID : "<<user.userId<<endl;
    }


    void showHistory()
    {
        if (head == nullptr)
        {
            cout << "No transaction history available." << endl;
            return;
        }
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << "TransactionId : " << temp->transdata.getTransactionId() << endl;
            cout << "Transaction Amount : " << temp->transdata.getTransactionAmount() << endl;
            cout << "Transaction time : " << temp->transdata.getTransactionTime() << endl;
            cout << "Transaction location: " << temp->transdata.getLocation() << endl;
            cout << "Transaction device: " << temp->transdata.getDevice() << endl;
            cout << "Transaction Risk: " << temp->transdata.getriskFactor() << endl;
            cout << endl;
            cout << endl;
            temp = temp->next;
        }
        cout << endl;
        cout << endl;
    }
};

class TransactionOperation
{
public:
    void checkTransactions(User &uu, string accnum, double Amount, string location, string currdevice, int currenthour, map<string, User> &userDetails);
    bool fraudInAmount(map<string, User> &userDetails, double Amount, string accnum);
    bool fraudInLocation(map<string, User> &userDetails, string location, double Amount, string accnum);
    bool fraudInDevice(map<string, User> &userDetails, string currDevice, string Location, double Amount, string accnum);
    bool fraudInTime(int currentHour);
};

void TransactionOperation::checkTransactions(User &uu, string accnum, double Amount, string location, string currdevice, int currenthour, map<string, User> &userDetails)
{
    bool flagged = false;
    double risk = 0.0;

    if (Amount > 20000)
    {
        if (!fraudInAmount(userDetails, Amount, accnum))
        {
            flagged = true;
        }
        else
        {
            risk = risk + 10 * 8.0;
        }
    }

    if (uu.getlocation() != location)
    {
        if (!fraudInLocation(userDetails, location, Amount, accnum))
        {
            flagged = true;
        }
        else
        {
            risk = risk + 2 * 2.0;
        }
    }

    if (uu.getuserDevice() != currdevice)
    {
        if (!fraudInDevice(userDetails, currdevice, location, Amount, accnum))
        {
            flagged = true;
        }
        else
        {
            risk = risk + 3 * 5.0;
        }
    }

    if (!fraudInTime(currenthour))
    {
        flagged = true;
    }

    if (flagged)
    {
        cout << "Fraud Detected. Transaction Aborted." << endl;
    }
    else
    {
        Transaction tr(Amount, currenthour, location, currdevice, risk);
        cout << "Transaction Successful" << endl;
        uu.AddTransaction(tr);
    }
}

bool TransactionOperation::fraudInAmount(map<string, User> &userDetails, double Amount, string accnum)
{
    User &u = userDetails[accnum];
    double averageAmount = u.getAverageTransactionAmount();
    if (Amount > 2 * averageAmount)
    {
        cout << "Suspicious transaction: Amount exceeds twice the user's average transaction amount." << endl;
        // return false;
    }
    char ch;
    cout << "Hello, Is this you doing transaction for amount Rs.  " << Amount << " (Y/N) :  ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        return true;
    }
    else
    {
        cout << "A transaction exceeding the limit of Rs. 20000 has been attempted on your account by someone other than the account owner. Please review your account activity immediately." << endl;
        return false;
    }
}

bool TransactionOperation::fraudInLocation(map<string, User> &userDetails, string location, double Amount, string accnum)
{
    char ch;
    cout << "Hello, Is this you doing transaction from Location = " << location << " for Amount = Rs. " << Amount << " (Y/N) :  ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        return true;
    }
    else
    {
        cout << "A transaction exceeding Rs. 20000 was attempted on your account by someone other than the account owner, from a different location." << endl;
        return false;
    }
}

bool TransactionOperation::fraudInDevice(map<string, User> &userDetails, string currDevice, string Location, double Amount, string accnum)
{
    char ch;
    cout << "Hello, Is this you doing transaction from Device = " << currDevice << " from Location = " << Location << " for Amount = Rs. " << Amount << " (Y/N) :  ";
    cin >> ch;
    if (ch == 'y' || ch == 'Y')
    {
        return true;
    }
    else
    {
        cout << "A transaction exceeding Rs. 20000 was attempted on your account by someone other than the account owner, from a different location and device." << endl;
        return false;
    }
}

bool TransactionOperation::fraudInTime(int currentHour)
{
    if (currentHour >= 0 && currentHour <= 5)
    {
        char ch;
        cout << "Hello, Is this you doing a transaction at this time (current time is " << currentHour << " hours)? " << endl;
        cout << "The transaction is happening outside normal hours (12 AM to 5 AM). " << endl;
        cout << "Is this transaction legitimate? (Y/N) : ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            return true;
        }
        else
        {
            cout << "Transaction marked as suspicious due to time of transaction. " << endl;
            return false;
        }
    }
    return true;
}

int main()
{
    map<string, User> userDetails;
    TransactionOperation tq;
    int choice;
    char ch;
    string accnum, currdevice, location;
    double Amount;
    int currentHour;

    string uname;
    string userAccountnumber;
    string bankname;
    string trustedDevice;
    string trustedlocation;

    userDetails["SBI123456"] = User("Honour", "SBI123456", "STATE_BANK_OF_INDIA", "PC", "Nagpur");
    userDetails["HDFC987654"] = User("Edward", "HDFC987654", "HDFC_BANK", "Mobile", "Hyderabad");
    userDetails["ICICI763242"] = User("Arno", "ICICI763242", "ICICI_BANK", "PC", "Raipur");
    userDetails["BOI343422"] = User("Shay", "BOI343422", "BANK_OF_INDIA", "Tablet", "Pune");
    userDetails["UN987654"] = User("Jacob", "UN987654", "UNION_BANK", "Mobile", "London");
    userDetails["SBI1235678"] = User("Kassandra", "SBI1235678", "STATE_BANK_OF_INDIA", "Tablet", "Greece");

    do
    {
        cout << "********************MAIN MENU*********************" << endl;
        cout << "1. ADD NEW USER " << endl;
        cout << "2. DO TRANSACTIONS " << endl;
        cout << "3. SHOW TRANSACTION HISTORY " << endl;
        cout << "4. CALCULATE AVERAGE RISK RATE FOR SPECIFIC USER TRANSACTION " << endl;
        cout << "5. SHOW SPECIFIC USER DETAILS " << endl;
        cout << "6. EXIT " << endl;

        cout << "Enter the choice from the Main Menu: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the User  Detials  " << endl;
            cout << "Enter the Name : ";
            cin >> uname;
            cout << "Enter user Account number : ";
            cin >> userAccountnumber;
            cout << "Enter user bankname : ";
            cin >> bankname;
            cout << "Enter user trusted Device : ";
            cin >> trustedDevice;
            cout << "Enter user trusted location: ";
            cin >> trustedlocation;

            userDetails[userAccountnumber] = User(uname, userAccountnumber, bankname, trustedDevice, trustedlocation);
            cout << "User Details Registered " << endl;
            break;

        case 2:
            cout << "Enter account number: ";
            cin >> accnum;

            if (userDetails.find(accnum) != userDetails.end())
            {
                User &user = userDetails[accnum];

                cout << "Enter amount: ";
                cin >> Amount;
                cout << "Enter location: ";
                cin >> location;
                cout << "Enter device: ";
                cin >> currdevice;

                time_t now = time(0);
                tm *ltm = localtime(&now);
                currentHour = ltm->tm_hour;

                tq.checkTransactions(user, accnum, Amount, location, currdevice, currentHour, userDetails);
                // user.showHistory();
            }
            else
            {
                cout << "Account not found!" << endl;
            }
            break;
        case 3:
            cout << "Enter account number to view transaction history: ";
            cin >> accnum;

            if (userDetails.find(accnum) != userDetails.end())
            {
                User &user = userDetails[accnum];
                user.showHistory();
            }
            else
            {
                cout << "Account not found!" << endl;
            }
            break;

        case 4:
            cout << "Enter the accoutn number you wish to find the average risk rate : ";
            cin >> accnum;
            if (userDetails.find(accnum) != userDetails.end())
            {
                User &user = userDetails[accnum];
                double avgRisk = user.calculateAverageRisk();
                if(avgRisk >= 10.0){
                    cout<<"ALERT !! Average Risk Factor for User With Account Number => "<<user.getAccountNumber()<<endl;
                }

                //cout << "Average Risk for User with account " << accnum << ": " << avgRisk << endl;
            }
            else
            {
                cout << "Account number not found." << endl;
            }

            

            break;

        case 5:
            cout << "Enter the account Number you wish to find : ";
            cin >> accnum;

            if (userDetails.find(accnum) != userDetails.end())
            {
                User &user = userDetails[accnum];
                user.findUserDetails(user);
            }
            else
            {
                cout << "Account number not found " << endl;
            }

        case 6:
            cout << "Exiting program." << endl;
            break;
        default:
            cout << "Invalid choice, please try again!" << endl;
            break;
        }

        cout << "Do you want to continue? (Y/N): ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}