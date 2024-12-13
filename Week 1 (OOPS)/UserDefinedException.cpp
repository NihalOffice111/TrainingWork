#include<iostream>
using namespace std;
class MyException : public exception{
    private:
        string message;
    public:
        MyException(string message){
            this->message = message;
        }

        const char* what() const noexcept override {
            return message.c_str();
        }
};


int main(){
    try{
        int a = 10;
        int b = 0;

        if(b == 0){
            throw MyException("Division by zero is not allowed");
        }
        else{
        cout<<a/b<<endl;

        }

    }
            catch(exception& e){
            cout<<e.what();
        }
}