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

class BinarySearchTree{
    public:
        Node* root;

        BinarySearchTree(){
            root = nullptr;
        }

        
        Node* InsertNode(int data){
            Node* newnode = new Node(data);
            if(root == nullptr){
                root = newnode;
            }
            else{
                Node* temp = root;
                while(true){
                    if(newnode->data < temp->data){
                        if(temp->left != nullptr){
                            temp = temp->left;
                        }
                        else{
                            temp->left = newnode;
                            break;
                        }
                    }
                    else if(newnode->data > temp->data){
                        if(temp->right != nullptr){
                            temp = temp->right;
                        }
                        else{
                            temp->right = newnode;
                            break;
                        }
                    }
                }
            }
        }

        void preorderTraversal(Node* trav){
            if(trav == NULL){
                return;
            }
            cout<<trav->data<<" ";
            preorderTraversal(trav->left);
            preorderTraversal(trav->right);
        }

        void preorder(){
            cout<<"Preorder Traversal: "<<endl;
            preorderTraversal(root);
            cout<<endl;
        }

        
        void inorderTraversal(Node* trav){
            if(trav == NULL){
                return;
            }
            inorderTraversal(trav->left);
            cout<<trav->data<<" ";
            inorderTraversal(trav->right);
        }

        void inorder(){
            cout<<"Inorder Traversal: "<<endl;
            inorderTraversal(root);
            cout<<endl;
        }

        void reverseTraversal(Node* trav){
            if(trav == NULL){
                return;
            
            }
            reverseTraversal(trav->right);
            cout<<trav->data<<" ";
            reverseTraversal(trav->left);
        }

        void reverseInorder(){
            cout<<"Reverse Inorder Traversal: "<<endl;
            reverseTraversal(root);
            cout<<endl;
        }

        void nonRecursiveInorderTraversal(){
            Node* trav = root;
            stack<Node*> st;
            cout<<"Non Recursive Inorder Traversal : ";
            while(trav != NULL || !st.empty()){
                if(trav != NULL){
                    st.push(trav);
                    trav = trav->left;
                }
                else{
                    trav = st.top();
                    cout<<trav->data<<" ";
                    st.pop();
                    trav = trav->right;
                }
            }

        }

        void NonRecursiveReverseInorderTraversal(){
            Node* trav = root;
            stack<Node*> st;
            cout<<"Non Recursive Reverse Inorder Traversal: ";
            while(trav != NULL || !st.empty()){
                if(trav != NULL){
                    st.push(trav);
                    trav = trav->right;
                }
                else{
                    trav = st.top();
                    cout<<trav->data<<" ";
                    st.pop();
                    trav = trav->left;
                }
            }
        }


        void postorderTraversal(Node* trav){
            if(trav == NULL){
                return;
            }
            postorderTraversal(trav->left);
            postorderTraversal(trav->right);
            cout<<trav->data<<" ";
        }

        void postorder(){
            cout<<"Postorder Traversal: "<<endl;
            postorderTraversal(root);
            cout<<endl;
        }

        
        bool searchNodes(int data){
            Node* temp = root;
            while(temp != NULL){
                if(temp->data == data){
                    return true;
                }
                else if(temp->data > data){
                    temp = temp->left;
                }
                else if(temp->data < data){
                    temp = temp->right;
                }
            }
            return false;
        }

        int heightOfTree(Node* trav){
            if(trav == NULL){
                return -1;
            }

            int hl = heightOfTree(trav->left);
            int hr = heightOfTree(trav->right);
        
            return max(hl+1,hr+1);
        }

        int heightOfTreeHelper(){
            return heightOfTree(root);
        }

        int maxNode(Node* trav){
            if(trav == NULL){
                return -1;
            }            
            
            while(trav->right != NULL){
                trav = trav->right;
            }
            
            return trav->data;
        }

        int maximumNode(){
            return maxNode(root);
        }

        int minNode(Node* trav){
            if(trav == NULL){
                return -1;
            }

            while(trav->left != NULL){
                trav = trav->left;
            }
            return trav->data;
        }

        int minimumNode(){
            return minNode(root);
        }

        Node* deleteNode(Node* root , int del){
            if(root == NULL){
                return root;
            }

            if(root->data > del){
                root->left = deleteNode(root->left,del);
            }
            
            else if(root->data < del){
                root->right = deleteNode(root->right,del);
            }

            else{
                if(root->left == NULL && root->right == NULL){
                    delete root;
                    root = NULL;
                }
                else if(root->left == NULL){
                    Node* temp = root;
                    root = root->right;
                    delete temp;
                }
                else if(root->right == NULL){
                    Node* temp = root;
                    root = root->left;
                    delete temp;
                }
                else{
                    Node* temp2 = findMin(root); //inorder successor
                    root->data = temp2->data;
                    root->right = deleteNode(root->right,temp2->data);

                }
            }

            return root;


        }

        Node* deleteNodeHelper(int val){
            return deleteNode(root,val);
        }

        Node* findMin(Node* root){
            Node* temp = root;
            while(temp->left != NULL){
                temp = temp->left;
            }
            return temp;
        }

};

int main(){
    BinarySearchTree bst;
    bst.InsertNode(40);
    bst.InsertNode(1);
    bst.InsertNode(67);
    bst.InsertNode(50);
    bst.InsertNode(23);
    bst.InsertNode(12);
    bst.InsertNode(111);

    bst.preorder();
    cout<<endl;
    bst.inorder();
    cout<<endl;
    bst.postorder();
    cout<<endl;
    bst.reverseInorder();
    cout<<endl;
    bst.nonRecursiveInorderTraversal();
    cout<<endl;
    bst.NonRecursiveReverseInorderTraversal();
    cout<<endl;

    cout<<bst.searchNodes(50)<<endl;

    cout<<"Height of Tree: "<<bst.heightOfTreeHelper()<<endl;

    cout<<"Max Node Value: "<<bst.maximumNode()<<endl;
    cout<<"Max Node Value: "<<bst.minimumNode()<<endl;



    bst.deleteNodeHelper(40);
    bst.inorder();
    
}