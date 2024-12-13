#include<bits/stdc++.h>
using namespace std;
class Stack{
    public:
        int top ;
        int capacity;
        int *stack ;
        int size = 5;

    Stack(){
        top = -1;
        capacity = size;
        stack = new int[size];
    }

    void push(int data){
        if(isFull()){
            int *temp = new int[capacity*2];
            for(int i = 0 ; i < capacity ; i++){
                temp[i] = stack[i];
            }

            stack  = temp;
        }
        top++;
        stack[top] = data;
    }

    int pop(){
        if(isEmpty()){
            cout<<"Stack is Empty Cannot Delete "<<endl;
        }

        int x = stack[top];
        top--;
        return x;
    }

    int peek(){
        return stack[top];
    }

    void display(){
        for(int i = 0 ; i <= top ; i++){
            cout<<stack[i]<<endl;
        }
        cout<<endl;
    }

    bool isFull(){
        if(top == size-1){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        return false;
    }
};
int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);

    s.display();
    s.pop();
    int x = s.peek();
    cout<<x<<endl;
    s.pop();
    s.display();
    return 0;
}