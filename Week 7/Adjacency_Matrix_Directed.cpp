#include<bits/stdc++.h>
using namespace std;

class AdjancecyMatrixDirected {
    public:
        int vertex;
        vector<vector<int>> matrix;

    AdjancecyMatrixDirected(int vertex){
        this->vertex = vertex;
        matrix.resize(vertex , vector<int>(vertex , 0));
    }

    void AddEdges(int u , int v ){
       // int value;
       // cout<<"Enter the value of the Edge : ";
        //cin>>value;
        matrix[u][v] = 1;
        
    }

void deleteEdges(int u, int v) {
    if ((u >= 0 && u < vertex) && (v >= 0 && v < vertex)) {
        if (matrix[u][v] == 1) {
            matrix[u][v] = 0;
            
            cout << "Edge Deleted" << endl;
        } else {
            cout << "Invalid Edge" << endl;
        }
    }
}

    void display(){
        for(int i = 0 ; i < vertex ; i++){
            for(int j = 0 ; j < vertex ; j++){
                cout<<matrix[i][j]<<" ";
            }
            cout<<endl;
        }

    }
};

int main(){
    AdjancecyMatrixDirected amd(5);
    amd.AddEdges(0,1);
    amd.AddEdges(1,2);
    amd.AddEdges(2,3);
    amd.AddEdges(3,4);
    amd.AddEdges(4,0);


    cout<<endl;
    amd.display();

    amd.deleteEdges(2,3);
    cout<<endl;
    amd.display();
    return 0;
}