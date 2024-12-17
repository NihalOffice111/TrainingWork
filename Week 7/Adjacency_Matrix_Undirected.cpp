#include<bits/stdc++.h>
using namespace std;
class AdjancecyMatrixUndirected {
    public:
        int vertex;
        vector<vector<int>> matrix;

    AdjancecyMatrixUndirected(int vertex){
        this->vertex = vertex;
        matrix.resize(vertex , vector<int>(vertex , 0));
    }

    void AddEdges(int u , int v ){
       // int value;
       // cout<<"Enter the value of the Edge : ";
        //cin>>value;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

void deleteEdges(int u, int v) {
    if ((u >= 0 && u < vertex) && (v >= 0 && v < vertex)) {
        if (matrix[u][v] == 1 && matrix[v][u] == 1) {
            matrix[u][v] = 0;
            matrix[v][u] = 0;
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


    void BreadthFirstSearch(int start){
        vector<bool> visited(vertex,false);
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while(!q.empty()){
            int x = q.front();
            q.pop();

            cout<<x<<" ";
            for(int i = 0 ; i < vertex ; i++){
                if(matrix[x][i] == 1 && !visited[i]){
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
};

int main(){
    AdjancecyMatrixUndirected amu(5);
    amu.AddEdges(0,1);
    amu.AddEdges(1,2);
    amu.AddEdges(2,3);
    amu.AddEdges(3,4);
    amu.AddEdges(4,0);


    cout<<endl;
    amu.display();

    amu.deleteEdges(2,3);
    cout<<endl;
    amu.display();

    amu.BreadthFirstSearch(0);
    return 0;
}