#include<iostream>
#include<queue>
using namespace std;
class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int value)
        {
            data = value;
            left = nullptr;
            right = nullptr;
        }
};
class BTree
{
    private:
        Node* root;
    public:
        BTree()
        {
            root = nullptr;
        }
        void inOrderTraversal(Node* root)
        {
            if(root == nullptr)
            {
                return;
            }
            inOrderTraversal(root->left);
            cout<<root->data<<"\t";
            inOrderTraversal(root->right);
        }
        void preOrderTraversal(Node* root)
        {
            if(root == nullptr)
            {
                return;
            }
            cout<<root->data<<"\t";
            preOrderTraversal(root->left);
            preOrderTraversal(root->right);
        }
        void postOrderTraversal(Node* root)
        {
            if(root == nullptr)
            {
                return;
            }
            postOrderTraversal(root->left);
            postOrderTraversal(root->right);
            cout<<root->data<<"\t";
        }
        // Insert using queue
        void insert(int val)
        {
            Node* newnode = new Node(val);
            if(root == nullptr)
            {
                root = newnode;
                cout << "Inserted root: " << val << endl;
                return;
            }
            queue<Node*> q;
            q.push(root);
            while(!q.empty())
            {
                Node* temp = q.front();
                q.pop();
                if(temp->left == nullptr)
                {
                    temp->left = newnode;
                    return;
                }
                else
                {
                    q.push(temp->left);
                }
                if(temp->right == nullptr)
                {
                    temp->right = newnode;
                    return;
                }
                else
                {
                    q.push(temp->right);
                }
            }
        }
        Node* getRoot()
        {
            return root;
        }

        bool  search(Node* trav , int val){
            if(trav != NULL){
                return false;
            }
            if(trav->data == val){
                return true;
            }

            return search(trav->left,val) || search(trav->right,val);
        }

        bool searchNode(int val){
            return search(root,val);
        }


};
int main()
{
    BTree b1;
    b1.insert(1);
    b1.insert(2);
    b1.insert(3);
    b1.insert(4);
    b1.insert(5);
    cout<<"Inorder traversal "<<endl;
    b1.inOrderTraversal(b1.getRoot());
    cout<<endl;
    cout<<"Preorder traversal "<<endl;
    b1.preOrderTraversal(b1.getRoot());
    cout<<endl;
    cout<<"Postorder traversal "<<endl;
    b1.postOrderTraversal(b1.getRoot());


    cout<<b1.searchNode(4);
    return 0;
}