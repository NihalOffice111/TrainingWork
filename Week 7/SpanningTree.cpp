#include<bits/stdc++.h>
using namespace std;
class SpanningTree{
    public:
        int vertex;
        vector<vector<int>> graph;

    SpanningTree(int vertex){
        this->vertex = vertex;
        graph.resize(vertex);
    }

    void addEdges(int u , int v){
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void DepthFirstSearch(int start,set<int>& visited){
        stack<int> st;

        st.push(start);
        
        while(!st.empty()){
            int x = st.top();
            st.pop();

            if(visited.find(x) == visited.end()){
                visited.insert(x);
                cout<<x<<" ";
            }

            for(auto y : graph[x]){
                if(visited.find(y) == visited.end()){
                    st.push(y);
                }
            }

        }
    }

    void printMultipleSpanningTree(){
        set<int> visited;
        int count = 0;

        for(int i = 0; i< vertex ; i++){
            if(visited.find(i) == visited.end()){
                cout<<"Spanning Tree: "<<++count<<endl;
                DepthFirstSearch(i,visited);
                cout<<endl;
            }
        }
    }
};
int main(){
    SpanningTree sp(9);  

    sp.addEdges(0,1);
    sp.addEdges(1,2);
    sp.addEdges(0,2);
    sp.addEdges(0,3);
    sp.addEdges(2,4);
    sp.addEdges(2,5);
    sp.addEdges(3,5);
    sp.addEdges(5,6);
    sp.addEdges(4,6);
    sp.addEdges(6,7);
    sp.addEdges(7,8);

    sp.printMultipleSpanningTree();
    return 0;
}