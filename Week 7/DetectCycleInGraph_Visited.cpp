#include<bits/stdc++.h>
using namespace std;

class DetectCycle{
    public:
        int vertex;
        vector<vector<int>> graph;

    DetectCycle(int vertex){
        this->vertex = vertex;
        graph.resize(vertex);
    }

    void AddEdge(int u,int v){
        graph[u].push_back(v);
    }

    bool HasCycle(){
        vector<int> visited(vertex,0);

        
      for(int i = 0; i < vertex; i++){
            if(visited[i] == 0){ 
                queue<int> q;
                q.push(i);
                visited[i] = 1; 

                while(!q.empty()){
                    int x = q.front();
                    q.pop();

                    for(int y : graph[x]){
                        if(visited[y] == 0){
                            q.push(y);
                            visited[y] = 1;
                        }
                        else if(visited[y] == 1){
                            return true;
                        }
                    }

                    visited[x] = 2; 
                }
            }
        }

        return false; 
    }


};


int main(){
    DetectCycle DC(6);
    DC.AddEdge(2, 3);
    DC.AddEdge(5, 2);
    DC.AddEdge(3, 1);
    DC.AddEdge(4, 1);
    DC.AddEdge(3, 0);
    DC.AddEdge(4, 0);

    bool x = DC.HasCycle();
    if(x){
        cout<<"Graph Contain Cycle"<<endl;
    }
    else{
        cout<<"Graph Does not Contain Cycle"<<endl;
    }
    return 0;
}