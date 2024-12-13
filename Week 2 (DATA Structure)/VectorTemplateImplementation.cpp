#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class VVector {
private:
    T* VContainer;
    size_t capacity;
    size_t size;

    void resize(size_t newcapacity) {
        T* Container = new T(newcapacity);
        for (size_t i = 0; i < size; i++) {
            Container[i] = VContainer[i];
        }

        delete[] VContainer;
        VContainer = Container;
        capacity = newcapacity;
    }

public:
    VVector() {
        VContainer = nullptr;
        capacity = 0;
        size = 0;
    }
    void push_back(const T& data) {
        if (size == capacity) {
            if (capacity == 0) {
                resize(1);
            }
            else {
                resize(capacity * 2);
            }
        }

        VContainer[size] = data;
        size++;
    }

    void pop_back() {
        if (size == 0) {
            cout << "UnderFlow " << endl;
        }
        size--;
    }

    size_t getSize() {
        return size;
    }

    size_t getCapacity() {
        return capacity;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            cout << "UnderFlow" << endl;
        }
        return VContainer[index];
    }

    const T& operator[](size_t index)const {
        if (index >= size) {
            cout << "UnderFlow" << endl;
        }
        return VContainer[index];
    }

    T& at(size_t index){
        if(index >= size){
            cout<<"UnderFlow "<<endl;
        }
        return VContainer[index];
    }

    void clear() {
        size = 0;
    }

    void displayVector() const {
        for(size_t  i = 0 ; i < size ; i++){
            cout<<VContainer[i]<<" ";
        }
        cout<<endl;
    }

    void erase(size_t index){

    }

    ~VVector() {
        

    }

};

int main() {

    VVector<int> v;
    cout << "Vector Implementation" << endl;
    v.push_back(45);
    cout<<v[0]<<endl;
    cout << "After 1st push_back Size:  " << v.getSize() << " Capacity: " << v.getCapacity() << endl;
    v.push_back(12);
    cout << "After 2nd push_back Size:  " << v.getSize() << " Capacity: " << v.getCapacity() << endl;


    v.push_back(67);
    cout << "After 3rd push_back Size:  " << v.getSize() << " Capacity: " << v.getCapacity() << endl;

    v.push_back(56);
    v.push_back(122);

    cout << "After 4th and 5th push_back Size:  " << v.getSize() << " Capacity: " << v.getCapacity() << endl;


    v.displayVector();



    return 0;
}