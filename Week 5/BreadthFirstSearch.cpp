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

class BreadthFirstSearch{
    public:
        Node* root;

    BreadthFirstSearch(){
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

    void BFSHelper(int search){
        cout<<"BREADTH FIRST SEARCH : "<<endl; 
        bool x = BreadthFirstSearchLevel(root , search);
        if(!x){
            cout<<endl;
            cout<<search<<" Not Found "<<endl;
        }
    }


    bool BreadthFirstSearchLevel(Node* root,int val){
        if(root == NULL){
            return false;
        }

        queue<pair<Node*,int>> q;
        q.push({root,1});


       
        while(!q.empty()){
            Node* temp = q.front().first;
            int level = q.front().second;
            q.pop();

            cout<<temp->data<<" ";
            

            if(temp->data == val){
                cout<<endl;
                cout<<val<<" found At level "<<level<<endl;
                
                return true;
            }

            if(temp->left != nullptr){
                q.push({temp->left,level+1});
            }

            if(temp->right != nullptr){
                q.push({temp->right,level+1});
            }
        }
        return false;
    }
};


int main(){
    BreadthFirstSearch BFS;
    BFS.insertNode(32);
    BFS.insertNode(34);
    BFS.insertNode(31);
    BFS.insertNode(12);
    BFS.insertNode(11);
    BFS.insertNode(2);
    BFS.insertNode(98);
    BFS.insertNode(45);
    BFS.insertNode(67);

    cout<<endl;
    BFS.BFSHelper(2);
    return 0;
}