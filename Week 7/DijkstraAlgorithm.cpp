#include<bits/stdc++.h>
using namespace std;
class DijkstraAlgorithm{
    public:
        int vertex;
        vector<vector<pair<int,int>>> graph;

    DijkstraAlgorithm(int vertex){
        this->vertex = vertex;
        graph.resize(vertex);
    }

    void AddEdges(int u,int v, int weight){
        graph[u].push_back({v,weight});
    }

    void dijkstraAlgorithm(int start){
        vector<int> distance(vertex,INT_MAX);
        distance[start] = 0;

        set<pair<int,int>> sett;
        sett.insert({0,start});

        while(!sett.empty()){
            int u = sett.begin()->second;
            sett.erase(sett.begin());

            for(auto ver : graph[u]){
                int v = ver.first;
                int weight = ver.second;

                if(distance[u] + weight  < distance[v]){
                    if(distance[v] != INT_MAX ){
                        sett.erase(sett.find({distance[v],v}));
                    }

                    distance[v] = distance[u] + weight;
                    sett.insert({distance[v],v});
                }
            }
        }

        for(int i= 0 ;i < vertex ; i++){
            if(distance[i] == INT_MAX){
                cout<<" INF "<<endl;
            }
            else{
                cout<<distance[i]<<" ";
            }
        }
    }
};


int main(){
    DijkstraAlgorithm DA(5);

    // DA.AddEdges(0, 1, 5);
    // DA.AddEdges(0, 2, 3);
    // DA.AddEdges(1, 2, 2);
    // DA.AddEdges(1, 3, 6);
    // DA.AddEdges(2, 3, 7);
    // DA.AddEdges(2, 4, 4);
    // DA.AddEdges(3, 4, 1);
    // DA.AddEdges(4, 5, 2);

    DA.AddEdges(0,1,10);
    DA.AddEdges(0,3,5);
    DA.AddEdges(1,2,1);
    DA.AddEdges(3,4,2);
    DA.AddEdges(3,2,9);
    DA.AddEdges(4,0,2);
    DA.AddEdges(3,1,3);
    DA.AddEdges(3,2,9);

    cout<<"Shortest Distance Between : "<<endl;
    DA.dijkstraAlgorithm(0);


    return 0;
}