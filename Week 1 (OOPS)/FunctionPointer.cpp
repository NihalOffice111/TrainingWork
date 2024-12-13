#include<bits/stdc++.h>
using namespace std;

class BankAccount{
    private:
        double balance;
    
    public:
        BankAccount(){

        }

        BankAccount(double bal){
            balance = bal;
        }

        void deposit(int amount){
            if(amount > 0){
                balance = balance + amount;
                cout<<"Balance after deposit : "<<balance<<endl;
            }
            else{
                throw runtime_error("Amount cannot be Negative");
            }
        }

        void withDraw(int amount){
            if(amount > 0 && amount < balance){
                balance = balance - amount;
                cout<<"Balance After withDraw : "<<balance<<endl;
            }
            else{
                throw runtime_error("Amount should not be negative and should be less than balance");
            }
        }

        typedef void(BankAccount::*Operation)(int); // function pointer


       void perform(BankAccount::Operation opr , int amount){
            (this->*opr)(amount);
        }
};
int main(){
    try{

        BankAccount B1(4500.90);

        char ch;
        int amount;


        cout<<"Enter opeartion "<<endl;
        cin>>ch;

        BankAccount::Operation opr;

        if(ch == 'd'){
            opr = BankAccount::deposit; // Pointer to function
        }
        else if(ch == 'w'){
            opr = BankAccount::withDraw;
        }
        else {
            throw runtime_error("Please ENter Valid Operation ");
        }

        cout<<"Enter the amount"<<endl;
        cin>>amount;

        if(opr){
            B1.perform(opr , amount);
        }
    }

    catch(exception& e ){
        cout<<e.what()<<endl;
    }
    return 0;
}