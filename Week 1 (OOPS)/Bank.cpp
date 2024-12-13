#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Bank
{
private:
    string bankAccNo;
    double balance;

public:
    Bank()
    {
    }
    Bank(string acc, double bal)
    {
        bankAccNo = acc;
        balance = bal;
    }

    virtual void deposit(double amount)
    {

        if (amount > 0)
        {
            balance = balance + amount;
            cout << "Deposited : " << balance << endl;
        }
        else
        {
            // cout<<"Deposit Amount must be positive "<<endl;
            throw runtime_error("Deposite Amount Cannot be Negative");
        }
    }

    virtual void withDraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance = balance - amount;
            cout << "Withdraw from Parent : " << amount << endl;
        }
        else
        {
            cout << "Insufficent Funds " << endl;
        }
    }

    double getBalance()
    {
        return balance;
    }

    virtual ~Bank()
    {
    }
};

class CurrentAccount : public Bank
{

private:
    int transfee;

public:
    CurrentAccount(string Acc, double balance, int Transfee) : Bank(Acc, balance), transfee(Transfee)
    {
    }

    void withDraw(double amount) override
    {
        if (amount > 0 && amount + transfee <= getBalance())
        {
            Bank::withDraw(amount + transfee);
            cout << "Withdraw from Current: " << amount << " with fee: " << transfee << endl;
        }
        else
        {
            cout << "Insufficient Funds including transaction fee" << endl;
        }
    }
};

int main()
{
    int amount;

    try
    {

        Bank B1("2313513NB", 31000); // basically Instializing and Good way of Intializing
                                     // Bank b1  = new Bank("34345GD",6000);

        // cout<<"Enter the amount : ";
        // cin>>amount;

        B1.deposit(1200);
    }
    catch (exception &e)
    {
        cout << e.what() << endl;
    }
    // B1.withDraw(7500);

    // CurrentAccount ca ("7923235BC",90000,4000);
    // Bank *B = &ca;

    // CurrentAccount *cb = dynamic_cast<CurrentAccount*>(B);
    // cb->withDraw(amount);

    // cout<<"Final Balance : "<<cb->getBalance()<<endl;

    // vector<Bank*> vb;

    // vb.push_back(new CurrentAccount("SA23523",1000,1.25));

    // Bank * b  = new CurrentAccount("SA09234",21344,54);
    // b->deposit(1000);

    // b->withDraw(2000);

    // b->getBalance();

    return 0;
}
