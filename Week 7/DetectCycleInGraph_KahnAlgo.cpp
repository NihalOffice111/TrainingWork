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


};

int main(){

    DetectCycle DC(6);
    DC.AddEdge(2, 3);
    DC.AddEdge(5, 2);
    DC.AddEdge(3, 1);
    DC.AddEdge(4, 1);
    DC.AddEdge(3, 0);
    DC.AddEdge(4, 0);
    
    return 0;
}


#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool detectCycleInDirectedGraph(int V, vector<vector<int>>& adj) {
    // Step 1: Calculate in-degree of each vertex
    vector<int> inDegree(V, 0);
    for (int u = 0; u < V; u++) {
        for (int v : adj[u]) {
            inDegree[v]++;
        }
    }

    // Step 2: Initialize a queue for BFS
    queue<int> q;
    // Enqueue all vertices with in-degree 0
    for (int i = 0; i < V; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Step 3: Process each vertex
    int count = 0;  // To count the number of vertices processed
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        count++;

        // Process all neighbors of u
        for (int v : adj[u]) {
            // Decrease the in-degree of the neighbors
            inDegree[v]--;
            // If in-degree of a neighbor becomes 0, enqueue it
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If the count of processed nodes is not equal to the number of vertices, there is a cycle
    return count != V;
}

int main() {
    int V = 4;  // Number of vertices
    vector<vector<int>> adj(V);

    // Example directed graph with a cycle
    adj[0].push_back(1);
    adj[1].push_back(2);
    adj[2].push_back(3);
    adj[3].push_back(1); // This edge creates a cycle: 1 -> 2 -> 3 -> 1

    if (detectCycleInDirectedGraph(V, adj)) {
        cout << "Cycle detected in the graph!" << endl;
    } else {
        cout << "No cycle in the graph." << endl;
    }

    return 0;
}
