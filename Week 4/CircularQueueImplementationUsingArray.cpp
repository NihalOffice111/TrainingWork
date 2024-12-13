#include<bits/stdc++.h>
using namespace std;
class CircularQueue{
    
    public:
        int arr[5];
        int front ;
        int rear;

        CircularQueue(){
            front = -1;
            rear  = -1;
        }

        void enqueue(int data){
            if((rear+1) % 5 == front){
                cout<<"Queue is Full "<<endl;
                return;
            }
            else if(front == -1){
                front = rear = 0;
            }
            else{
                rear = (rear+1) % 5;
            }
            arr[rear] = data;
        }

        void dequeue(){
            if(front == -1){
                cout<<"Queue is Empty "<<endl;
            }
            else if(front == rear){
                front = rear = -1;
            }
            else{
                front = (front+1) % 5;
            }
        }

        void display(){
            for(int i = front ; i != rear ; i = (i+1) % 5){
                cout<<arr[i]<<" ";
            }
            cout<<arr[rear];
        }

};

int main(){
    
    CircularQueue cq;
    cq.enqueue(32);
    cq.enqueue(45);
    cq.enqueue(11);
    cq.enqueue(88);
    cq.enqueue(1000);
    cq.enqueue(899);

    cq.display();
    cout<<endl;
    cq.dequeue();
    cq.enqueue(290);
    cq.enqueue(100);
    cq.display();
    return 0;
}