#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this->data =data;
            next = nullptr;
        }
};

class Queue{
    public: 
        Node* rear;
        Node* front;

        Queue(){
            rear = NULL;
            front = NULL;
        }

        void enqueue(int data){
            Node* newnode = new Node(data);
            if(front == nullptr || rear == nullptr){
                front = rear = newnode;
            }

            rear->next = newnode;
            rear= rear->next;

        }

        void dequeue(){
            if(isEmpty()){
                cout<<"Queue is Empty "<<endl;
            }

            Node* temp = front;
            front = front->next;
            delete temp;

        }

        int peek(){
            return front->data;
        }

        void display(){
            Node* temp = front;
            while(temp != NULL){
                cout<<temp->data<<" -- ";
                temp = temp->next;
            }

            cout<<endl;
        }

        bool isEmpty(){
            if(front == nullptr){
                return true;
            }
            return false;
        }


};

int main(){
    Queue q;
    q.enqueue(12);
    q.enqueue(43);
    q.enqueue(11);
    q.enqueue(155);
    q.enqueue(121);

    q.display();
    cout<<q.peek()<<endl;
    q.dequeue();
    q.display();

    return 0;
}