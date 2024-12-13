#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class BankAccount{
    protected:
        string accno;
        double balance;

    public:
        BankAccount(){

        }
        BankAccount(string accno , double balance) {
            this->accno = accno;
            this->balance = balance;
        }

        //copy Constructor


        virtual void deposit(double amount) = 0;
        virtual void withDraw(double amount) = 0;
        virtual double getBalance() = 0;

        virtual ~BankAccount(){

        }

        //friend function
        friend void displayBalance(const BankAccount& acc);

        //friend class
        friend class BankManager;
};


class SavingAccount : public BankAccount{
    public:
        int rate;
        int *r;
    

        SavingAccount(){
            r = new int;
        }

        SavingAccount(string accno,double balance ,double rate): BankAccount(accno,balance) , rate(rate){

        }

        //deep Copy
        SavingAccount(const SavingAccount &temp){
            this->rate = temp.rate;
            r = new int;

            *r = *(temp.r);
            
            
        }

        void deposit(double amount) override{
            if(amount > 0){
                balance = balance + amount;
                cout<<"Amount deposited to saving account : "<<amount<<" ,New balance:  "<<balance<<endl;
            }
            else{
                cout<<"Deposit amount must be positive "<<endl;
            }
        }


        void withDraw(double amount) override{
            if(amount > 0 && amount <= balance){
                balance = balance - amount;
                cout<<"Amount withdraw to saving account : "<<amount<<" ,New balance:  "<<balance<<endl;

            }
            else{
                cout<<"Withdraw amount must be less than balance "<<endl;
            }
        }


        double getBalance() override {
            return balance;
        }


};



class CurrentAccount : public BankAccount{
    private :
        int transFee;

    public:
        CurrentAccount(string accno,double balance ,double rate): BankAccount(accno,balance) , transFee(transFee){

        }

    void deposit(double amount) override {
        if(amount > 0){
                balance = balance + amount;
                cout<<"Amount deposited to Current account : "<<amount<<" ,New balance:  "<<balance<<endl;
            }
            else{
                cout<<"Deposit amount must be positive "<<endl;
            }
    }


    void withDraw(double amount) override{
        if (amount > 0 && amount + transFee <= getBalance()) {
            //BankAccount::withDraw(amount + transFee); 
            amount = amount + transFee;
            cout << "Withdraw from Current: " << amount << " with fee: " << transFee << endl;
        } else {
            cout << "Insufficient Funds including transaction fee" << endl;
        }
    }

    double getBalance() override{
        return balance;
    }
};


// friend Function Defination

void displayBalance( const BankAccount& acc){
    cout<<"Account Number: "<<acc.accno<<" Balance is : "<<acc.balance<<endl;
    
}

class BankManager{
    public:
        void displayBalance( BankAccount& acc){
            cout<<"Account Balance : "<<acc.accno <<" Having Money balance : "<<acc.balance<<endl;
        }

        void adjustBalance(BankAccount& acc, int amount){
            acc.balance = acc.balance + amount;
            cout<<"Updated balance is : "<<acc.balance<<endl;
        }

};



int main(){

    //Saving Account;
//     BankAccount* ba = new SavingAccount("A436453S",1000.0,2);
//     ba->deposit(1234);
//     ba->withDraw(2000);
//     cout<<"Saving account  balance "<<ba->getBalance()<<endl;
    
//     displayBalance(*ba);
    
//    // delete ba;
//     cout<<endl;
    
//     BankManager bm;
//     bm.adjustBalance(*ba,25000);
//     bm.displayBalance(*ba);
    
    cout<<endl;
    
    //Current Account
    // ba = new CurrentAccount("GF32353",15000,9);
    // ba->deposit(2500);
    // ba->withDraw(7000);
    // cout<<"Current Account balance "<<ba->getBalance()<<endl;

    // displayBalance(*ba);

    //delete ba;

SavingAccount sa("23GH34", 10000, 3);
    SavingAccount cas(sa); // Deep copy

    cout << &sa.r << endl; // Address of sa's r pointer
    cout << &cas.r << endl; // Address of cas's r pointer

    cas.deposit(1000);
    cas.withDraw(2000);

    cout << "Balance in Saving Account when using Copy: " << cas.getBalance() << endl;


   // cas.deposit(1000);
    //cas.withDraw(2000);
    
    //cout<<"Balance in Saving Account when using Copy : "<<cas.getBalance()<<endl;
    




    
}