#include<bits/stdc++.h>
using namespace std;

class BankAccount{
    public:
        char*  accno;
        double balance;
    
    
        BankAccount(const char* accno , double balance){
            try{
                this->accno = new char[strlen(accno)+1];
                if(accno == nullptr){
                    throw "error allocating memory";
                }
                strcpy(this->accno,accno);
                this->balance = balance;
            }
            catch(exception e){
                cout<<e.what()<<endl;
            }

        }

        BankAccount(const BankAccount& temp){
            accno = new char[strlen(temp.accno)+1];
            //*accno = *(temp.accno);
            strcpy(accno,temp.accno);
            this->balance = temp.balance;

        }

        void displayDetails(){
            cout<<"Account Number: "<<accno<<" Balance : "<<balance<<endl;
            cout<<"Address of accno : "<<&accno<<endl;
        }

        ~BankAccount(){
            delete[] accno;
        }
};

int main(){
    BankAccount b1("GT43464" , 23533.90);
    b1.displayDetails();
    //cout<<"Address of b1:  "<<&b1<<endl;
    //b1.accno = "TY4535";

    BankAccount b2(b1);
    b2.displayDetails();
    //cout<<"Address of b2: "<<&b2<<endl;
    
    return 0;
}