#include<bits/stdc++.h>
using namespace std;

template<typename T> 
class SparseArray {
    private:
        map<int,T> mp;
        int size;

    public:
        SparseArray(int size){
            this->size = size;
        }

    void setElementAtIndex(int index , T value){
        // if(index < 0 || index >= size){
        //     cerr<<"Index out of Bound "<<endl;
        // }

        if(value != 0){
             mp[index] = value;
        }
        else{
            mp.erase(index);
        }

       
    }

    T getElementAtIndex(int index){
        // if(index < 0 || index >= size){
        //     cerr<<"Index out of Bound "<<endl;
        // }

        if(mp.find(index) != mp.end()){
            return mp[index] ;
        }
        else{
            return 0;
        }       
    }

    void display(){
        for(auto x : mp){
            cout<<x.first<<" -> " << x.second<<endl;
        }
    }

    int getSize(){
        return size;
    }
};

int main(){
    SparseArray<int> SA (5);
    int key,value;
    cout<<"Enter the Key and Value for Map "<<endl;
    for(int i = 0  ; i < SA.getSize() ; i++){
       cin>>key>>value;

        SA.setElementAtIndex(key,value);
    }

    SA.display();
    cout<<endl;

    auto y = SA.getElementAtIndex(22);
    cout<<y<<endl;

    cout<<SA.getSize();
    return 0;
}