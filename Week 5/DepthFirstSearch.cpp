#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

    Node(int data){
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

class DepthFirstSearch{
    public:
        Node* root;

    DepthFirstSearch(){
        root = nullptr;
    }

    Node* insertNode(int data){
        Node* newnode = new Node(data);
        if(root == nullptr){
            root = newnode;
        }
        else{
            Node* trav = root;
            while(true){
                if(newnode->data < trav->data){
                    if(trav->left != NULL){
                        trav = trav->left;
                    }
                    else{
                        trav->left = newnode;
                        break;
                    }
                }
                else if(newnode->data > trav->data){
                    if(trav->right != NULL){
                        trav = trav->right;
                    }
                    else{
                        trav->right = newnode;
                        break;
                    }
                }
            }
        }
    }

    void DFSHelper(int val){
        bool x = DepthFirstSearchDepth(root,val);
        if(!x){
            cout<<endl;
            cout<<val<<" Not Found "<<endl;
        }
    }

    bool DepthFirstSearchDepth(Node* root , int val){
        if(root == nullptr){
            return false;
        }
        stack<pair<Node*,int>> st;
        st.push({root,0});
        while(!st.empty()){
            Node* temp = st.top().first; 
            int depth = st.top().second;

            st.pop();
            cout<<temp->data<<" ";

            if(temp->data == val){
                cout<<endl;
                cout<<val<<" Found At Depth Level ";
                return true;
            }

            if(temp->right != NULL){
                st.push({temp->right,depth+1});
            }

            if(temp->left != NULL){
                st.push({temp->left,depth+1});
            }

        }
        return false;
    }



};

int main(){

    DepthFirstSearch DFS;
    DFS.insertNode(31);
    DFS.insertNode(21);
    DFS.insertNode(44);
    DFS.insertNode(34);
    DFS.insertNode(12);
    DFS.insertNode(1);
    DFS.insertNode(11);
    DFS.insertNode(67);
    DFS.insertNode(2);

    DFS.DFSHelper(344);


    return 0;
}