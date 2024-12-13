#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
    //     vector<int> v;

    //     int x;
    //  //   cout<<"Enter element of vector "<<endl;

    //     // for(int i = 0 ; i < 5;i++){
    //     //     cin>>x;
    //     //     v.push_back(x);
    //     // }

    //     v.push_back(21);
    //     v.push_back(45);
    //     cout<< v.capacity()<<endl;
    //     v.push_back(22);
    //     v.push_back(12);
    //     cout<<"After PUSH back "<< v.capacity()<<endl;

    //     //inserting

    //     v.insert(v.begin()+2,100);
    //     cout<<"After Insert "<< v.capacity()<<endl;


    //     v.pop_back();
    //     cout<<"After Pop back "<< v.capacity()<<endl;

    //     v.erase(v.begin() + 2);
    //     cout<<"After erasing "<< v.capacity()<<endl;


    //     v.resize(10,50);
    //     cout<<"After resizing  "<< v.capacity()<<endl;

    //     //v.capacity(); // capacity of the vector - how much space it has allocated
    //     //v.reserve(3);

    //     cout<<"After reserve(3) : "<< v.capacity()<<endl;
    //    // v.clear();
    //     v.push_back(1000);
    //     v.push_back(1000);
    //     v.push_back(1000);
    //     v.push_back(1000);

    //     cout<<"After Push_back again : "<< v.capacity()<<endl;

    //     for(int y  : v){
    //         cout<<y<<" ";
    //     }
    //     cout<<endl;




    vector<int> v;
   // v.reserve(16);
    vector<int> v1(7);


    v.push_back(10);
    cout << "After 1st element size : " << v.size() << " capacity: " << v.capacity() << endl;

    v.push_back(10);
    v.push_back(10);
    cout << "After 2nd and 3rd element size : " << v.size() << " capacity: " << v.capacity() << endl;

    v.push_back(10);
    cout << "After 4th element size : " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);

    cout << "After 5th-8th element size: " << v.size() << " capacity: " << v.capacity() << endl;

    v.push_back(10);
    v.push_back(10);
    cout << "After 9th and 10th element size: " << v.size() << " capacity: " << v.capacity() << endl;


    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    v.push_back(10);
    cout << "After 11th-16th element size: " << v.size() << " capacity: " << v.capacity() << endl;

    v.push_back(10);
    cout << "After 17th element size: " << v.size() << " capacity: " << v.capacity() << endl;
    v.push_back(10);

    v.pop_back();
    v.pop_back();
    v.pop_back();
    v.pop_back();
    cout << "After removing 4 element from end  size: " << v.size() << " capacity: " << v.capacity() << endl;

}