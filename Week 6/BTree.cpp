
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        vector<int> keys;
        vector<Node*> children;
        bool isleaf;
        int numkeys;

        Node(bool leaf){
            isleaf = leaf;
            numkeys = 0;
        }
};

class BTree{
    Node* root;
    int order;

    BTree(int order){
        this->order = order;
        root = nullptr;
    }

    void insert(int data){

    }   


};


int main(){
    BTree.insert(12);
    BTree.insert(32);
    BTree.insert(32);
    //https://github.com/NihalOffice111/TrainingWork.git


    return 0;
}