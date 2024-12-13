#include<bits/stdc++.h>
using namespace std;

class ShallowCopy{

    public:
        char * str;
    
    ShallowCopy(const char* text){
        str = new char[strlen(text) + 1];
        strcpy(str,text);
    }

    ~ShallowCopy(){

    }
};

int main(){
    
    ShallowCopy sc("Hello World ");
    ShallowCopy sc1 = sc;

    cout<<&sc<<endl;
    cout<<&sc1<<endl;

    cout<<sc.str<<endl;
    cout<<sc1.str<<endl;

    char * str = "Hello";

    ShallowCopy sc2(str);
    sc1 = sc2;

    cout<<&sc1<<endl;
    cout<<sc1.str<<endl;
    cout<<sc2.str<<endl;


    return 0;
}