#include<bits/stdc++.h>
using namespace std;

class BankAccount{
    private:
        struct CustomerInfo{
            string name;
            int age;
            string address;
        };
        CustomerInfo CI;
        double balance;

    public:
        BankAccount(const string& name,int age , const string& address , double bal){
            CI.name = name;
            CI.age = age;
            CI.address = address;

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
        void displayInfo(){
            cout<<"NAME: "<<CI.name<<endl;
            cout<<"Age: "<<CI.age<<endl;
            cout<<"Address: "<<CI.address<<endl;
        }

};

int main(){

    try{
        BankAccount B1("John",23,"Nagpur",13000.90);
        B1.displayInfo();
        B1.deposit(1000);
        B1.withDraw(9000);
    }
    catch(exception& e){
        cout<<e.what()<<endl;
    }
    
    return 0;
}