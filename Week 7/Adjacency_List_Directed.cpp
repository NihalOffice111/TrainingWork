#include <bits/stdc++.h>
using namespace std;
class AdjacencyListDirected
{
public:
    int vertex;
    vector<vector<int>> list;

    AdjacencyListDirected(int vertex)
    {
        this->vertex = vertex;
        list.resize(vertex);
    }

    void InsertVertex(int u, int v)
    {
        list[u].push_back(v);
    }

    void deleteEdge(int u,int v){
        if((u >= 0 && u < vertex) && (v >= 0 && v < vertex)){
            auto x  = find(list[u].begin(),list[u].end(),v);
            if(x != list[u].end()){
                list[u].erase(x);
                cout<<"Edge deleted "<<endl;
            }
            else{
                cout<<"Edge Not Found "<<endl;
            }
        }
        else{
            cout<<"Invalid Coordinates"<<endl;
        }
    }
    void display()
    {
        for (int i = 0; i < vertex; i++)
        {
            cout << "vertex: " << i << ": ";
            for (int j : list[i])
            {
                cout << j << " ";
            }
            cout << endl;
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
            for(auto y : list[x]){
                if(!visited[y]){
                    visited[y] = true;
                    q.push(y);
                }
            }
        }
    }

    void DepthFirstSearch(int start){
        stack<int> st;
        vector<bool> visited(vertex , false);
        st.push(start);
        visited[start] = true;

        while(!st.empty()){
            int x = st.top();
            st.pop();

            cout<<x<<" ";
            for(int y : list[x]){
                if(!visited[y]){
                    st.push(y);
                    visited[y] = true;
                }
            }
        }
    }
};
int main()
{
    AdjacencyListDirected al(5);
    // al.InsertVertex(0, 1);
    // al.InsertVertex(1, 2);
    // al.InsertVertex(2, 3);
    // al.InsertVertex(3, 4);
    // al.InsertVertex(0, 4);

    // al.InsertVertex(1,0);
    // al.InsertVertex(0,2);
    // al.InsertVertex(3,0);
    // al.InsertVertex(2,1);
    // al.InsertVertex(2,4);

    al.InsertVertex(1,2);
    al.InsertVertex(1,0);
    al.InsertVertex(2,0);
    al.InsertVertex(2,3);
    al.InsertVertex(4,2);

   



    

    cout<<endl;
    al.display();

    al.deleteEdge(0,4);
    
    cout<<endl;
    al.display();

    cout<<"Breadth First Search : ";
    al.BreadthFirstSearch(0);

    cout<<endl;
    cout<<"Depth First Search : ";
    al.DepthFirstSearch(1);



    return 0;
}