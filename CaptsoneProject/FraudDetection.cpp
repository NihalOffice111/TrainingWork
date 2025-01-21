#include <bits/stdc++.h>
using namespace std;

class Transaction
{
    // Transaction class to store the transaction details
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

    // Getters for Easy access of the Member Variables
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

    // friend function to overload the << operator (declaration)
    friend ostream &operator<<(ostream &os, const Transaction &tr);
};

// Overloading the << operator to display the transaction details (definition)
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

// As We Have to Generate Unique Transaction ID for Each Transaction, We are Using a Static Variable to Keep Track of the Transaction ID
int Transaction::transactionIdCounter = 10011;

class Node
{
public:
    // Doubly Linked List Node to store the Transaction Details
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
    // User class to store the user details and transaction history
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

    // getters

    string getUserName()
    {
        return username;
    }

    string getbankName()
    {
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

    // Function For Calculating the Average Transaction Amount
    double getAverageTransactionAmount()
    {
        if (transactionCount == 0)
        {
            return 0.0;
        }
        return totalTransactionAmount / transactionCount;
    }

    // Function to Add a New Transaction to the User's Transaction History (Logic of Inserting at the End of the List)
    void AddTransaction(Transaction tr)
    {
        Node *newTransaction = new Node(tr); // Creating a new Node for the Transaction

        if (head == nullptr) // If the List is Empty
        {
            head = newTransaction;
        }
        else // If the List is Not Empty
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newTransaction;
            newTransaction->prev = temp;
        }

        totalTransactionAmount = totalTransactionAmount + tr.getTransactionAmount(); // Updating the Total Transaction Amount
        transactionCount++;

        cout << "Current Transaction: " << endl;
        cout << newTransaction->transdata << endl; // Displaying the Transaction Details
    }

    // Function to Calculate the Average Risk Rate for the User's Transaction History

    double calculateAverageRisk()
    {
        if (head == nullptr) // If the List is Empty
        {
            return 0.0;
        }

        Node *temp = head;
        double totalRisk = 0.0;
        int count = 0;

        while (temp != nullptr) // Traversing the List and Calculating the Total Risk
        {
            totalRisk += temp->transdata.getriskFactor();
            count++;
            temp = temp->next;
        }

        return count > 0 ? totalRisk / count : 0.0;
    }

    // Function to Find And Display the User Details

    void findUserDetails(User &user)
    {
        cout << "Name : " << user.getUserName() << endl;
        cout << "Account Number : " << user.getAccountNumber() << endl;
        cout << "Bank Name : " << user.getbankName() << endl;
        cout << "User ID : " << user.userId << endl;
    }

    // Function to Display the Transaction History (Logic of Traversing the List and Displaying the Transaction Details)

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

// Transaction Operation Class to Check the Fraud in the Transaction
class TransactionOperation
{
public:
    void checkTransactions(User &uu, string accnum, double Amount, string location, string currdevice, int currenthour, map<string, User> &userDetails);
    bool fraudInAmount(map<string, User> &userDetails, double Amount, string accnum);
    bool fraudInLocation(map<string, User> &userDetails, string location, double Amount, string accnum);
    bool fraudInDevice(map<string, User> &userDetails, string currDevice, string Location, double Amount, string accnum);
    double fraudInTime(int currentHour);
};

// Function to Check the Fraud in the Transaction
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
            risk = risk + 10 * 8.0; // here 10 is the riskFactor and 8.0 is the weightage constant
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
            risk = risk + 2 * 2.0; // here 2 is the riskFactor and 2.0 is the weightage constant
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
            risk = risk + 3 * 5.0; // here 3 is the riskFactor and 5.0 is the weightage constant
        }
    }

    double timerisk = fraudInTime(currenthour);
    if (timerisk > 0.0)
    {
        risk = risk + timerisk * 10.0; // here 10 is the riskFactor and 10.0 is the weightage constant
        if (timerisk >= 10.0)
        {
            flagged = true;
        }
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

// Function to Check Fraud in the Amount
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
    cout << "Hello, Is this you doing transaction for amount Rs.  " << Amount << " (Y/N) :  "; // This message will be displayed to the original Account holder
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

// Function to Check Fraud in the Location
bool TransactionOperation::fraudInLocation(map<string, User> &userDetails, string location, double Amount, string accnum)
{
    char ch;
    cout << "Hello, Is this you doing transaction from Location = " << location << " for Amount = Rs. " << Amount << " (Y/N) :  "; // This message will be displayed to the original Account holder
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

// Function to Check Fraud in the Device
bool TransactionOperation::fraudInDevice(map<string, User> &userDetails, string currDevice, string Location, double Amount, string accnum)
{
    char ch;
    cout << "Hello, Is this you doing transaction from Device = " << currDevice << " from Location = " << Location << " for Amount = Rs. " << Amount << " (Y/N) :  "; // This message will be displayed to the original Account holder
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

// Function to Check Fraud in the Time
double TransactionOperation::fraudInTime(int currentHour)
{
    if (currentHour >= 0 && currentHour <= 5)
    {
        char ch;
        cout << "Hello, Is this you doing a transaction at this time (current time is " << currentHour << " hours)? " << endl; // This message will be displayed to the original Account holder
        cout << "The transaction is happening outside normal hours (12 AM to 5 AM). " << endl;
        cout << "Is this transaction legitimate? (Y/N) : ";
        cin >> ch;
        if (ch == 'y' || ch == 'Y')
        {
            return 5.0;
        }
        else
        {
            cout << "Transaction marked as suspicious due to time of transaction. " << endl;
            return 10.0;
        }
    }
    return 0.0;
}

// this is the main function
int main()
{
    map<string, User> userDetails; // we use map to store the Details of the User
    TransactionOperation tq;       // Object of TransactionOperation Class
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

    // Adding some default users (Samples)
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
            cout << "Enter the account number you wish to find the average risk rate : ";
            cin >> accnum;
            if (userDetails.find(accnum) != userDetails.end())
            {
                User &user = userDetails[accnum];
                double avgRisk = user.calculateAverageRisk();
                if (avgRisk >= 10.0)
                {
                    cout << "ALERT !! Average Risk Factor " << avgRisk << " for User With Account Number => " << user.getAccountNumber() << endl;
                }
                else
                {

                    cout << "Average Risk for User with account " << accnum << ": " << avgRisk << endl;
                }
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
            break;
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