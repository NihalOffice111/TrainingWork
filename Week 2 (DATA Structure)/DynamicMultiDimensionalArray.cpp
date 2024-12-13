#include<bits/stdc++.h>
using namespace std;

int main(){
    // int m , n;
    // cout<<"Enter the rows and cols : ";
    // cin>>m>>n;

    // int **arr = new int*[m]; // pointer to array of pointer



    // for(int i = 0 ; i < m ; i++){
    //     arr[i] = new int[n];
    // }

    // cout<<"Enter the elements : "<<endl;
    // for(int i = 0  ;i < m ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         cin>>arr[i][j];
    //     }
    // }

    // cout<<"Display the elements : "<<endl;
    // for(int i = 0  ;i < m ; i++){
    //     for(int j = 0 ; j < n ; j++){
    //         cout<<arr[i][j] <<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i = 0 ; i < m ; i++){
    //     delete[] arr[i];
    // }

    // delete[] arr;


    //3D array

    int m , n , o;
    cout<<"Enter the rows , cols , depth : ";
    cin>>m>>n>>o;

    int *** arr = new  int**[o];

    for(int i = 0 ; i < o ; i++){
        *arr[i] = new int[m];
        for(int j = 0; j < m ; j++){
            arr[i][j] = new int[n];
        }
    }

    cout<<"Enter the elements of 3D array "<<endl;
    for(int i = 0; i < o ; i++){
        for(int j = 0; j < m ; j++){
            for(int k = 0 ; k < n ; k++){
                cin>>arr[i][j][k];
            }
        }
    }

    cout<<"Display elements of 3D array "<<endl;
    for(int i = 0; i < o ; i++){
        for(int j = 0; j < m ; j++){
            for(int k = 0 ; k < n ; k++){
                cout<<arr[i][j][k];
            }
        }
    }


    for(int i = 0 ; i < o ; i++){
        for(int j = 0; j < m ; j++){
            delete [] arr[i][j];
        }
        delete [] arr[i];

    }

    delete [] arr;
}