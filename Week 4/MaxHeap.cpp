#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
        vector<int> maxheap;


        void heapifyUp(int in){
            while(in > 0 && maxheap[in] > maxheap[(in-1)/2]){
                swap(maxheap[in] , maxheap[(in-1)/2]);
                in = (in-1)/2;
            }
        }

        void heapifyDown(int in){
            while(in < maxheap.size()){
                int maxi = in;
                int left = (2*in) +1;
                int right = (2*in) +2;

                if(left < maxheap.size() && maxheap[left] > maxheap[maxi]){
                    maxi = left;
                }
                if(right < maxheap.size() && maxheap[right] > maxheap[maxi]){
                    maxi = right;
                }

                if(maxi != in){
                    swap(maxheap[in] , maxheap[maxi]);
                    in = maxi;
                }
                else{
                    break;
                }
            }
        }

        void insert(int data){
            maxheap.push_back(data);
            heapifyUp(maxheap.size()-1);
        }

        void pop(){
            maxheap[0] = maxheap.back();

            maxheap.pop_back();
            heapifyDown(0);
        }

        void display(){
            for(int x : maxheap){
                cout<<x<<" ";
            }
            cout<<endl;
        }
};
int main(){
    MaxHeap mh;
    mh.insert(10);
    mh.insert(20);
    mh.insert(5);
    mh.insert(15);
    mh.insert(30);
    mh.insert(100);

    mh.display();
    mh.pop();

    mh.display();
    return 0;
}