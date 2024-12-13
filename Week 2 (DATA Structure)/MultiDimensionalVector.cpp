#include<bits/stdc++.h>
using namespace std;



int main(){
    int m , n;
    cout<<"Enter the Row and cols : ";
    cin>>m>>n;

    vector<vector<int>> v (m,vector<int>(n));

    cout<<"Enter the element "<<endl;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cin>>v[i][j];
        }
    }
    
    cout<<endl;
    cout<<"Display the element "<<endl;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Using iterators "<<endl;
    for(auto i = v.begin() ; i != v.end() ; i++){
        for(auto j = i->begin() ; j != i->end() ; j++){
            cout<<*j<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    cout<<"USing Foreach Loop"<<endl;
    for(auto i : v){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }



    return 0;
}


    
