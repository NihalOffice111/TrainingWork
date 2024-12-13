#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
    bool isrightThreaded;
    bool isleftThreaded;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        isrightThreaded = false;
        isrightThreaded = false;
    }
};

class DoubleThreadedBinarySearchTree
{
public:
    Node *root;

    DoubleThreadedBinarySearchTree()
    {
        root = nullptr;
    }

    void insertNode(int val)
    {
        Node *newnode = new Node(val);
        if (!root)
        {
            root = newnode;
            return;
        }

        Node* curr = root;
        Node* temparent = NULL;

        while(curr != NULL){
            temparent = curr;
            if(curr->data > val || curr->isleftThreaded){
                if(curr->left == NULL){
                    break;
                }
                else{
                    curr = curr->left;
                }
            }
            else{
                if(curr->right == NULL || curr->isrightThreaded){
                    break;
                }
                else{
                    curr = curr->right;
                }
            }
        }

        if(temparent->data > val){
            if(temparent->isleftThreaded){
                newnode->left = temparent->left;
                temparent->isleftThreaded = false;
            }
            temparent->left = newnode;
            newnode->right = temparent;
            newnode->isrightThreaded = true;
        }
        else{
            if(temparent->isrightThreaded){
                newnode->right = temparent->right;
                temparent->isrightThreaded = false;
              
            }
            temparent->right = newnode;
            newnode->left = temparent;
            newnode->isleftThreaded = true;
        }
    }

    void inorderTraversal(){
        Node* trav = root;
        while(trav->left != nullptr && !trav->isleftThreaded){
            
                trav = trav->left;
            
        }

        while(trav != nullptr){
            cout<<trav->data<<" ";
            if(trav->isrightThreaded){
                trav = trav->right;
            }
            else{
                trav = trav->right;
                while(trav != nullptr && trav->left != nullptr && !trav->isleftThreaded){
                    trav = trav->left;
                }
            }
        }

        cout<<endl;
    }
};

int main()
{
    DoubleThreadedBinarySearchTree dtbst;
    dtbst.insertNode(50);
    dtbst.insertNode(30);
    dtbst.insertNode(70);
    dtbst.insertNode(20);
    dtbst.insertNode(40);
    dtbst.insertNode(60);
    dtbst.insertNode(80);

    dtbst.inorderTraversal();

    return 0;
}

