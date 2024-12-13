#include<bits/stdc++.h>
using namespace std;


class CompressedSparseRow{
    private:
        int rows;
        int cols;

        vector<int> rowIndex;
        vector<int> colIndex;
        vector<int> values;

    public:
        CompressedSparseRow(int row, int col){
            this->rows = row;
            this->cols = col;
           rowIndex.resize(row+1 , 0);
        }

        void addValues(int row,int col , int value){
            if(value == 0){
                return ;
            }

            values.push_back(value);
            colIndex.push_back(col);

            for(int i = row ; i < rows ; i++){
                rowIndex[i]++;
            }
        }

        int getValuesAtIndexes(int row , int col){
            int rowstart = rowIndex[row];
            int rowend = rowIndex[row+1];

            for(int i = rowstart ; i < rowend ; i++){
                if(colIndex[i] == col){
                    return values[i];
                }
                else{
                    return 0;
                }
                
            }
        }

        void display(){
            cout<<"Value Vector : ";
            for(int x : values){
                cout<<x<<" ";
            }
            cout<<endl;
            cout<<"Column vector : ";
            for(int y : colIndex){
                cout<<y<<" ";
            }
            cout<<endl;
            cout<<"Row Vector : ";
            for(int z: rowIndex){
                cout<<z<<" ";
            }
        }


};
int main(){
    CompressedSparseRow CSR(4,4);
    CSR.addValues(0,0,1);
    CSR.addValues(0,1,2);
    CSR.addValues(0,2,0);
    CSR.addValues(0,3,3);

    CSR.addValues(1,0,0);
    CSR.addValues(1,1,0);
    CSR.addValues(1,2,0);
    CSR.addValues(1,3,0);

    CSR.addValues(2,0,4);
    CSR.addValues(2,1,0);
    CSR.addValues(2,2,5);
    CSR.addValues(2,3,0);

    CSR.addValues(3,0,6);
    CSR.addValues(3,1,7);
    CSR.addValues(3,2,8);
    CSR.addValues(3,3,0);

    CSR.display();
    cout<<endl;
    cout<<CSR.getValuesAtIndexes(2,2);


    return 0;
}