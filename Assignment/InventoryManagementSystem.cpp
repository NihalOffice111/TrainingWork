#include<bits/stdc++.h>
using namespace std;

//Inventory Management System

class Items {
public:
    int itemId;
    string name;
    int quantity;
    double price;

public:
    Items() {
        itemId = 0;
        name = "";
        quantity = 0;
        price = 0.0;
    }


    Items(int itemId, string name, int quantity, double price) {
        this->itemId = itemId;
        this->name = name;
        this->quantity = quantity;
        this->price = price;
    }

    int getItemId() {
        return itemId;
    }

    friend ostream& operator<<(ostream& os, const Items& item);



};
class Inventory {
private:
    Items item;
    //vector<vector<Items>> items;
    vector<vector<vector<Items>>> inventory;
    int locationX;
    int locationY;
    int locationZ;



public:
    Inventory() {

    }


    Inventory(int locationX, int locationY, int locationZ) {
        
        this->locationX = locationX;
        this->locationY = locationY;
        this->locationZ = locationZ;


        for (int i = 0; i <= locationX; i++) {
            vector<vector<Items>> layer;
            for (int j = 0; j <= locationY; j++) {
                vector<Items> row;
                for (int k = 0; k <= locationZ; k++) {
                    row.push_back(Items());
                }
                layer.push_back(row);
            }
            inventory.push_back(layer);
        }
    }

    void addItem(int x, int y, int z, Items item) {
        if (item.quantity != 0) {
            inventory[x][y][z] = item;
        }
        else {
            cout << "Item quantity is zero. Not adding to inventory." << endl;
        }


    }


    void checkStocks(int id) {
        for (int i = 0; i < inventory.size(); i++) {
            for (int j = 0; j < inventory[i].size(); j++) {
                for (int k = 0; k < inventory[i][j].size(); k++) {
                    if (inventory[i][j][k].getItemId() == id) {
                        cout << "Item Name : " << inventory[i][j][k].name << " Item Stock: " << inventory[i][j][k].quantity << endl;
                        if (inventory[i][j][k].quantity <= 10) {
                            LowStockAlert();
                        }
                        else {
                            return;
                        }
                    }
                }
            }
        }
    }

    void LowStockAlert() {
        cout << "Alert! Low In Stock : This Item Quantity Soon Will be 0 " << endl;
    }

    void removeItems(int id) {
        for (int i = 0; i < inventory.size(); i++) {
            for (int j = 0; j < inventory[i].size(); j++) {
                for (int k = 0; k < inventory[i][j].size(); k++) {
                    if (inventory[i][j][k].getItemId() == id) {
                        inventory[i][j].erase(inventory[i][j].begin() + k);
                        cout << "Item Removed From Location : " << "( " << i << "," << j << "," << k << ")" << endl;
                        break;
                    }
                }
                break;
            }
            break;
        }


    }

    void transferItem(int x, int y, int z, int id) {
         Items olditem ;
        if (inventory[x][y][z].getItemId() == 0) {
            for (int i = 0; i < inventory.size(); i++) {
                for (int j = 0; j < inventory[i].size(); j++) {
                    for (int k = 0; k < inventory[i][j].size(); k++) {
                         if (inventory[i][j][k].getItemId() == id) {
                            olditem = inventory[i][j][k];
                            inventory[i][j][k] = Items();
                            break;
                         }
                    }
                }
            }
        }
        else{
            cout<<"Sorry! This Location is occupied"<<endl;
        }
        inventory[x][y][z] = olditem;
        cout<<"Item transferred successfully "<<endl;
    }


                void display() {
                    for (int i = 0; i < inventory.size(); i++) {
                        for (int j = 0; j < inventory[i].size(); j++) {
                            for (int k = 0; k < inventory[i][j].size(); k++) {
                                if (inventory[i][j][k].name != "" || inventory[i][j][k].quantity > 0) {  // Display only valid items
                                    cout << "Location : " << "(" << i << "," << j << "," << k << ")" << endl;
                                    cout << inventory[i][j][k] << endl;
                                }
                            }

                        }

                    }
                }






            };

            ostream& operator<<(ostream & os, const Items & item) {
                os << "Item ID: " << item.itemId << "\nName: " << item.name << "\nQuantity: " << item.quantity << "\nPrice: " << item.price << "\n";
                return os;
            }


            int main() {
                Inventory I(3, 3, 3);
                int x, y, z;
                int id;
                string name;
                char c;

                int q;
                int price;

                cout<<"*************************************Main Menu*************************************"<<endl;
                cout<<"1. ADD ITEM "<<endl;
                cout<<"2. REMOVE ITEM "<<endl;
                cout<<"3. CHECK STOCK "<<endl;
                cout<<"4. TRANSFER ITEM TO NEW LOCATION "<<endl;
                cout<<"5. DISPLAY ALL ITEM IN INVENTORY "<<endl;

                cout<<endl;

            do{
                int ch;
                cout<<"Enter the Choice From the Main Menu "<<endl;
                cin >> ch;

                switch(ch){
                    case 1:
                        cout<<"Enter the location for the new Item "<<endl;
                        cin>>x>>y>>z;
                        cout<<"Now Enter the Item Details: (id ,name , quantity , price) "<<endl;
                        cin>>id;
                        cin>>name;
                        cin>>q;
                        cin>>price;

                        
                        I.addItem(x,y,z,Items(id,name,q,price));
                        cout<<"New Item Added Successfully "<<endl;
                        

                        break;

                    case 2:
                        cout<<"Enter the Item Id You want to Remove "<<endl;
                        cin>>id;
                        I.removeItems(id);
                        break;
                        
                    case 3:
                        cout<<"Enter the Item Id you want to Check Stock of "<<endl;
                        cin>>id;

                        I.checkStocks(id);
                        break;

                    case 4:
                        cout<<"Enter the new Location where you want to Tranfer the Exiting Item "<<endl;
                        cin>>x>>y>>z;
                        int iid;
                        cout<<"Enter the item id : "<<endl;
                        cin>>iid;

                        I.transferItem(x,y,z,iid);
                        break;

                    case 5:
                        I.display();
                        break;
                }


                cout<<"do you want to Continue "<<endl;
                cin>>c;
                
            }while(c == 'Y' || c == 'y');


                // I.addItem(0, 0, 0, Items(101, "TV", 4, 90000));

                // I.addItem(0, 0, 2, Items(102, "AC", 100, 45000));

                // I.addItem(1, 2, 2, Items(103, "Washing Machine", 1000, 18000));

                // I.addItem(1, 2, 3, Items(104, "Laptop", 5, 120000));



                // I.display();
                // I.checkStocks(101);

                // I.removeItems(102);

                // I.display();

                // I.transferItem(1,1,1,103);

                // I.display();




                return 0;
            }
