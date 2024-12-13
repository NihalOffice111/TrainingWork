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
class CircularQueue{
    public:
        Node* rear ;
        Node* front ;

        CircularQueue(){
            rear = nullptr;
            front = nullptr;
        }

        void enqueue(int data){
            Node* newnode = new Node(data);
            if(rear == nullptr && front == nullptr){
                rear = front = newnode;
                newnode->next = front;
            }
            else{
                rear->next = newnode;
                newnode->next = front;
                rear = newnode;
            }
        }

        void dequeue(){
            if(front == nullptr && rear == nullptr){
                cout<<"Queue is Empty "<<endl;
            }

            else{
                Node * temp = front;
                front = front->next;
                rear->next = front;
                delete temp;
            }
        }

        int peek(){
            return front->data;
        }

        void display(){
            Node* temp = front;
            do{
                cout<<temp->data<<" -- ";
                temp = temp->next;

            }while(temp != front);
            cout<<front->data<<endl;
        }

};
int main(){
    CircularQueue cq;
    cq.enqueue(190);
    cq.enqueue(1910);
    cq.enqueue(11);
    cq.enqueue(120);
    cq.enqueue(1214);
    cq.enqueue(12);

    cq.display();

    cq.dequeue();
    cq.dequeue();

    cq.display();

    cout<<cq.peek()<<endl;
    
    return 0;
}