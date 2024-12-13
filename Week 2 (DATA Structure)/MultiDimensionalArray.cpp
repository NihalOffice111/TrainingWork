#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cout<<"Enter the rows and columns for Array : ";
    cin>>m>>n;
    int multiArray[m][n];

    cout<<"Enter the Array Elements "<<endl;
    for(int i = 0;  i < m ; i++){
        for(int j  = 0 ; j < n ; j++){
            cin>>multiArray[i][j];
        }
    }

    cout<<endl;
    cout<<"Display the array : "<<endl;
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            cout<<multiArray[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}