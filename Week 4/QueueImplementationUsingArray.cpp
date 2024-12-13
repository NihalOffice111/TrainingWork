#include<bits/stdc++.h>
using namespace std;
class Queue{
    public:
        
        int rear;
        int arr[5];
        
        int front;

        Queue(){
            rear = -1;
            front = -1;
        }

        void enqueue(int data){
            rear++;
            arr[front] = data;
        }

        void dequeue(){
            if(isEmpty()){
                cout<<"queue is Empty "<<endl;
            }

            front++;
            
        }

        void display(){
            for(int i = front ; i <= rear ; i++){
                cout<<arr[front]<<" ";
            }
            cout<<endl;
        }


        bool isEmpty(){
            if(front == -1 || front > rear){
                return true;
            }
            return false;
        }



};
int main(){
    Queue q;
    q.enqueue(12);
    q.enqueue(32);
    q.enqueue(44);
    q.enqueue(5);
    q.enqueue(112);
    q.display();
    q.dequeue();
    q.display();
    return 0;
}