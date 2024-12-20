#include<bits/stdc++.h>
using namespace std;

class PrimsAlgorithm{
    public:
        int vertex;
        vector<vector<pair<int,int>>> graph;

    PrimsAlgorithm(int vertex){
        this->vertex = vertex;
        graph.resize(vertex);
    }

    void AddEdges(int u,int v , int weight){
        graph[u].push_back({v,weight});
        graph[v].push_back({u,weight});
    }

    void primsAlgorithm(){
        vector<int> MST(vertex,-1);
        vector<int> minimumEdge(vertex,INT_MAX);
        vector<bool> inMST(vertex,false);

        minimumEdge[0] = 0;
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0,0});

        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            inMST[u] = true;

            for(auto edge : graph[u]){
                int v = edge.first;
                int weight = edge.second;

                if(!inMST[v] && weight < minimumEdge[v]){
                    minimumEdge[v] = weight;
                    pq.push({minimumEdge[v],v});
                    MST[v]= u;
                }
            }

        }

        cout << "Edges in the Minimum Spanning Tree (MST):" << endl;
        for (int i = 1; i < vertex; i++) {
            cout << "Edge: " << MST[i] << " - " << i << " with weight: " << minimumEdge[i] << endl;
        }
    }
};


int main(){
    PrimsAlgorithm pa(5);
    pa.AddEdges(0,1,2);
    pa.AddEdges(0,2,6);
    pa.AddEdges(0,4,5);
    pa.AddEdges(1,3,3);
    pa.AddEdges(1,4,1);
    pa.AddEdges(2,4,8);
    pa.AddEdges(3,4,7);

    cout<<endl;
    pa.primsAlgorithm();
    return 0;
}