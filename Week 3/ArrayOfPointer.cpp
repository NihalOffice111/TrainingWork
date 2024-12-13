#include<bits/stdc++.h>
using namespace std;

int main() {
    int rows;
    cout << "Enter the Rows in the Theator " << endl;
    cin >> rows;

    int** theater = new int* [rows];

    int* seatsInRow = new int[rows];

    for (int i = 0; i < rows;i++) {
        cout << "Enter the number of seats in row " << i + 1 << ": ";
        cin >> seatsInRow[i];
        theater[i] = new int[seatsInRow[i]];


    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0;j < seatsInRow[i]; j++) {
            theater[i][j] = 0;
        }
    }

    for (int i = 0; i < rows; i++) {
        cout << "Enter the no of seats in rows : " << i << ": ";
        for (int j = 0; j < seatsInRow[i]; j++) {
            cin >> theater[i][j];
        }
    }



    cout << "**************************MAIN MENU****************************" << endl;
    cout << "1. Book a Seat" << endl;
    cout << "2. Cancel a Seat" << endl;
    cout << "3. View seating arrangment: " << endl;
    cout << "4. Exit: " << endl;
    int ch;
    char choice;
    int seat;
    int row;


    do {
        cout << "Enter the Choice From the mAin menu " << endl;
        cin >> ch;


        switch (ch) {
        case 1:

            cout << "Enter the row number: ";
            cin >> row;
            cout << "Enter the seat number: ";
            cin >> seat;

            if (row < 1 || row > rows || seat < 1 || seat > seatsInRow[row - 1]) {
                cout << "Invalid row or seat number " << endl;
            }
            else if (theater[row - 1][seat - 1] == 1) {
                cout << "Seat already Booked " << endl;
            }
            else {
                theater[row - 1][seat - 1] = 1;
                cout << "Seat Booked Successfully " << endl;
            }
            break;

        case 2:
            cout << "Enter the row number: ";
            cin >> row;
            cout << "Enter the seat number: ";
            cin >> seat;

            if (row < 1 || row > rows || seat < 1 || seat > seatsInRow[row - 1]) {
                cout << "Invalid row or seat number " << endl;
            }
            else if (theater[row - 1][seat - 1] == 0) {
                cout << "Seat already Cancelled " << endl;
            }
            else {
                theater[row - 1][seat - 1] = 0;
                cout << "Seat Cancelled Successfully " << endl;
            }
            break;

        case 3:
            cout << endl;
            for (int i = 0; i < rows; i++) {
                cout << "Rows " << i + 1 << ": ";
                for (int j = 0; j < seatsInRow[i]; j++) {
                    cout << theater[i][j] << " ";
                }
                cout << endl;
            }

            break;

        case 4:
            cout << "Exiting .... " << endl;
            break;
        }
        cout << "Do you want to Continue " << endl;
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');



    // for(int i = 0 ;i < 3 ; i++){
    //     cout<<seatsInRow[i]<<" ";
    // }











    for (int i = 0; i < rows; i++) {
        delete[] theater[i];
    }

    delete[] seatsInRow;
}
