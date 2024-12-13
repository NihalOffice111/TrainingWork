#include<bits/stdc++.h>
using namespace std;

class MyClass{
    private:
        int *p;
        int data;
    
    public:
        // MyClass(){
        //     p = new int(0);
        //     data = 0;
        // }

        MyClass(){
            p = new int[10];
            data = 10;
        }


        // void display(){
        //     cout<<*p<<endl;
        //     cout<<p<<endl;
        //     cout<<data<<endl;
        // }
        
        void display(){
            for(int i = 0 ; i < 10 ; i++){
                cout<<p[i]<<" Address: "<<&p[i]<<endl;

            }
        }

        ~MyClass(){
            delete [] p;
        }

};

int main(){
    MyClass mc;
    mc.display();

   
    
}