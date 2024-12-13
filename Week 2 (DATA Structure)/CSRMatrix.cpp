#include<bits/stdc++.h>
using namespace std;


class CSRMatrix{
    private:
        vector<double> values;
        vector<int> rowIndex;
        vector<int> colIndex;

        int numRows;
        int numCols;

    public:
        CSRMatrix(int row , int col){
            this->numCols = col;
            this->numRows = row;
            rowIndex.resize(row + 1 , 0);
        }


        void addValue(int row , int col ,double value){
            if(value != 0){
                values.push_back(value);
                colIndex.push_back(col);

                for(int i = row ; i < numRows ; i++){
                    rowIndex[i]++;
                }
            }
        }

        double getValue(int row , int col){

            for(int i = rowIndex[row] ; i < rowIndex[row+1]; i++){
                if(colIndex[i] == col){
                    return values[i];
                }

                return 0.0;
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
    CSRMatrix csr(4,4);
    csr.addValue(0,2,3);
    csr.addValue(1,0,4);
    csr.addValue(1,3,5);
    csr.addValue(2,3,6);
    csr.addValue(3,0,7);
    csr.addValue(3,2,8);

    

    csr.display();
    cout<<endl;

    //cout<<csr.getValue(3,0);
}