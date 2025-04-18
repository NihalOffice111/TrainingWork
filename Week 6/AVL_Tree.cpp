#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        height = 1;
    }
};

class AVLTree
{
public:
    Node *root;

    AVLTree()
    {
        root = nullptr;
    }

    int heightOfTree(Node *trav)
    {
        if (trav == NULL)
        {
            return 0;
        }
        return trav->height;
    }

    int getBalanceFactor(Node *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        return heightOfTree(root->left) - heightOfTree(root->right);
    }

    Node *rightRotation(Node *y)
    {
        Node *x = y->left;
        Node *temp = x->right;

        x->right = y;
        y->left = temp;

        y->height = max(heightOfTree(y->left), heightOfTree(y->right));
        x->height = max(heightOfTree(x->left), heightOfTree(x->right));

        return x;
    }

    Node *leftRotation(Node *x)
    {
        Node *y = x->right;
        Node *temp = y->left;

        y->left = x;
        x->right = temp;

        x->height = max(heightOfTree(x->left), heightOfTree(x->right));
        y->height = max(heightOfTree(y->left), heightOfTree(x->right));

        return y;
    }

    Node *InsertNode(Node *root, int data)
    {

        if (root == nullptr)
        {
            return new Node(data);
        }

        if (data < root->data)
        {
            root->left = InsertNode(root->left, data);
        }
        else if (data > root->data)
        {
            root->right = InsertNode(root->right, data);
        }
        else
        {
            return root;
        }

        root->height = 1 + max(heightOfTree(root->left), heightOfTree(root->right));
        int balanceFactor = getBalanceFactor(root);

        // LL
        if (balanceFactor > 1 && data < root->left->data)
        {
            return rightRotation(root);
        }
        // RR
        else if (balanceFactor < -1 && data > root->right->data)
        {
            return leftRotation(root);
        }

        // LR
        else if (balanceFactor > 1 && data > root->left->data)
        {
            root->left = leftRotation(root->left);
            return rightRotation(root);
        }

        // RL
        else if (balanceFactor < -1 && data < root->right->data)
        {
            root->right = rightRotation(root->right);
            return leftRotation(root);
        }
        return root;
    }

   Node* minValueNode(Node* node) {
    Node* current = node;
    while (current && current->left)
        current = current->left;
    return current;
}

Node* deleteNode(Node* root, int key) {
    if (!root) return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    root->height = 1 + max(heightOfTree(root->left), heightOfTree(root->right));

    int balance = getBalanceFactor(root);

    //LL
    if (balance > 1 && getBalanceFactor(root->left) >= 0)
        return rightRotation(root);

    // RR
    if (balance < -1 && getBalanceFactor(root->right) <= 0)
        return leftRotation(root);
    //LR
    if (balance > 1 && getBalanceFactor(root->left) < 0) {
        root->left = leftRotation(root->left);
        return rightRotation(root);
    }

    //RL
    if (balance < -1 && getBalanceFactor(root->right) > 0) {
        root->right = rightRotation(root->right); 
        return leftRotation(root);
    }

    return root;
}

    void remove(int val)
    {
        root = deleteNode(root, val);
    }

    void insert(int val)
    {
        root = InsertNode(root, val);
    }

    void inorder(Node *root)
    {
        if (root == NULL)
        {
            return;
        }

        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void inorderTraversal()
    {
        cout << "Inorder Traversal : ";
        inorder(root);
        cout << endl;
    }
};

int main()
{
    AVLTree avl;

    avl.insert(30);
    avl.insert(20);
    avl.insert(10);
    avl.insert(5);
    avl.insert(25);
    avl.insert(40);
    avl.insert(35);
    avl.insert(50);

    avl.inorderTraversal();

    avl.remove(35);
    avl.remove(20);
    avl.inorderTraversal();


    return 0;
}
