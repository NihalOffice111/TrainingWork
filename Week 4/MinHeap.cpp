#include<bits/stdc++.h>
using namespace std;

class MinHeap{
    public:
        vector<int> minheap;
        
        void heapifyUp(int in){
            while(in > 0 && minheap[in] < minheap[(in-1)/2]){
                swap(minheap[in] , minheap[(in-1)/2]);
                in = (in-1)/2;
            }
        }

        void heapifyDown(int in){
            while( in < minheap.size()){
                int mini = in;
                int left = (2*in) + 1;
                int right = (2*in) + 2;

                if(in < minheap.size() && minheap[left] < minheap[mini]){
                    mini = left;
                }
                if(in < minheap.size() && minheap[right] < minheap[mini]){
                    mini = right;
                }
            }
        }

        void push(int data){
            minheap.push_back(data);
            heapifyUp(minheap.size()-1);
        }

        void pop(){
            minheap[0] = minheap.back();
            minheap.pop_back();
            heapifyDown(0);
        }
};



int main(){
    MinHeap mh;
    mh.push(10);
    mh.push(20);
    mh.push(5);
    mh.push(15);
    mh.push(1);
    return 0;
}