#include<bits/stdc++.h>
using namespace std;

class Add{
    private:
        int x;
    public:
        Add(int x){
            this->x = x;
        }

        int operator()(int x){
            return x + x; 
        }
};
int main(){
    vector<int> v = {1 ,2 , 3};
    Add a(5);
    for_each(v.begin(),v.end(),a);

    for(int i = 0 ; i < v.size() ; i++){
        cout<<v[i]<<" ";
    }
 }