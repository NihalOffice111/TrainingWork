#include <iostream>
using namespace std;
class PointerClass {
public:
//     void addOne(int *number) {
//         (*number)++;
//     }

//     void printValue(int num) {
//         std::cout << "Value: " << num<<" "<< std::endl;
//         }
 };

int main() {
//     int *num = new int[10];
//     cout << "Initial value: " << *num << endl;
//     PointerClass *pc = new PointerClass();
//     //PointerClass pc;
//     pc->addOne(num);
//    cout << "Updated value: " << *num << endl;
    
//     void (PointerClass::*funPtr)(int) = &PointerClass::printValue;
    
    
//    (pc->*funPtr)(*num);

//     delete[] num;
//     delete pc;

    int *ptr = new int[10];
    for(int i  =  1 ; i <= 10 ; i++){
        ptr[i] = i * 10;
    }

    for(int i = 0 ; i <= 10 ; i++){
        cout<<ptr[i]<<" Address : "<<" "<<&ptr[i];
    }

        cout<<*(&ptr[2]);
    cout<<endl;
    cout<<endl;

    


    


    // int *ptr1  = new int[5];
    // for(int i = 1 ; i <= 10 ; i++){
    //     ptr1[i] = i * 100;
    // }

    // for(int i = 0 ; i <= 10 ;i++){
    //     cout<<&ptr1[i]<<" ";
    // }
    // cout<<endl;

    // for(int i = 1 ;i <= 10 ; i++){
    //     cout<<ptr1[i]<<" ";
    // }

    return 0;
}
