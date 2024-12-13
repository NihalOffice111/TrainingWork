#include <bits/stdc++.h>
using namespace std;

class MenuItems
{
public:
    string name;
    int price;

    MenuItems() {}

    MenuItems(string name, int price)
    {
        this->name = name;
        this->price = price;
    }
};

class Node2
{
public:
    MenuItems mi;
    Node2 *next;
    Node2 *prev;

    Node2(MenuItems mi)
    {
        this->mi = mi;
        next = nullptr;
        prev = nullptr;
    }
};

class Hotels
{
public:
    string name;
    class Node2 *menuItems;

    Hotels()
    {
        menuItems = nullptr;
    }

    Hotels(string name)
    {
        this->name = name;
        menuItems = nullptr;
    }

    void addMenuItem(const string &itemName, int price)
    {
        Node2 *newNode = new Node2(MenuItems(itemName, price));

        if (!menuItems)
        {
            menuItems = newNode;
        }
        else
        {
            Node2 *lastNode = menuItems;
            while (lastNode->next)
            {
                lastNode = lastNode->next;
            }
            lastNode->next = newNode;
            newNode->prev = lastNode;
        }
    }

    friend ostream &operator<<(ostream &os, const Hotels &hotel);
};

ostream &operator<<(ostream &os, const Hotels &hotel)
{
    os << "Hotel Name: " << hotel.name << endl;
    Node2 *temp = hotel.menuItems;
    int count = 1;
    while (temp)
    {
        os << "  Menu Item " << count++ << ": " << temp->mi.name << ", Price: " << temp->mi.price << endl;
        temp = temp->next;
    }
    return os;
}

class Node1
{
public:
    Hotels hotel;
    Node1 *next;

    Node1(Hotels h)
    {
        this->hotel = h;
        next = nullptr;
    }
};

class ManagingHotelsAndItems
{
public:
    Node1 *head1;

    ManagingHotelsAndItems()
    {
        head1 = nullptr;
    }

    void addHotels(Hotels h)
    {
        Node1 *newHotel = new Node1(h);

        if (head1 == nullptr)
        {
            head1 = newHotel;
            head1->next = head1;
        }
        else
        {
            Node1 *temp = head1;
            while (temp->next != head1)
            {
                temp = temp->next;
            }
            temp->next = newHotel;
            newHotel->next = head1;
        }
    }

    void display()
    {
        if (head1 == nullptr)
        {
            cout << "No hotels available." << endl;
            return;
        }

        Node1 *temp = head1;
        do
        {
            cout << temp->hotel;
            temp = temp->next;
        } while (temp != head1);
    }

    void displayHotelOnly()
    {
        if (head1 == nullptr)
        {
            cout << "No hotels available." << endl;
            return;
        }
        Node1 *temp = head1;
        do
        {
            cout << temp->hotel.name << " -->> ";
            temp = temp->next;
        } while (temp != head1);
        cout << endl;
    }
};

class OrderedItems
{
public:
    string itemName;
    int price;
    int quantity;
    OrderedItems()
    {
    }

    OrderedItems(string itemName, int price, int quantity)
    {
        this->itemName = itemName;
        this->price = price;
        this->quantity = quantity;
    }

    bool operator<(const OrderedItems &other) const
    {
        if (itemName != other.itemName)
            return itemName < other.itemName;
        if (price != other.price)
            return price < other.price;
        return quantity < other.quantity;
    }

    friend ostream &operator<<(ostream &os, const OrderedItems &oi)
    {
        os << "Item: " << oi.itemName << ", Price: " << oi.price << ", Quantity: " << oi.quantity;
        return os;
    }
};

class CustomerOrder
{
public:
    string custname;
    long long customermob;
    string customerAddress;

    CustomerOrder(string name, long long customermob, string customerAddress)
    {
        this->custname = name;
        this->customermob = customermob;
        this->customerAddress = customerAddress;
    }

    void PlaceOrder(ManagingHotelsAndItems &managingSystem)
    {
        string hname;
        cout<<"Hotel Names: "<<endl;
        managingSystem.displayHotelOnly();
        cout<<endl;

        cout << "Enter the Hotel name From Above";
        cin >> hname;

        auto head = managingSystem.head1;
        Node1 *temp = head;
        while (temp != NULL)
        {
            if (temp->hotel.name == hname)
            {
                cout << temp->hotel << endl;
                break;
            }
            else
            {
                temp = temp->next;
            }
        }

        int qty;
        string item;

        Node2 *temp2 = temp->hotel.menuItems;
        map<string, OrderedItems> mp;
        char ch;

        do
        {
            cout << "Now Choose items From the Hotels: ";
            cin >> item;
            cout << "Enter the quantity for this item: ";
            cin >> qty;


            while (temp2 != NULL)
            {
                if (temp2->mi.name == item)
                {
                    if (mp.find(item) != mp.end())
                    {
                        mp[item].quantity += qty;
                    }
                    else
                    {
                        OrderedItems oi = OrderedItems(temp2->mi.name, temp2->mi.price, qty);
                        mp[item] = oi;
                    }
                    break;
                }
                temp2 = temp2->next;
            }

            cout << "Do you want to add anything else " << endl;
            cin >> ch;
        } while (temp2 != NULL && ch == 'y');

        int p;
        int totalprice = 0;

        cout<<"Place Order: "<<endl;
        for (auto x : mp)
        {
            cout << x.first << " " <<x.second.price<<" "<<x.second.quantity<<endl;
            cout<<endl;
        }


        for (auto x : mp)
        {
            totalprice = totalprice + x.second.price * x.second.quantity;
        }

        cout << "Total Price: " << totalprice << endl;
        
    }
};

int main()
{
    string custname, custAddress;
    long long mobile;

    cout << "Enter your name: ";
    cin >> custname;
    cout << "Enter your mobile number: ";
    cin >> mobile;
    cout << "Enter your Address: ";
    cin >> custAddress;

    ManagingHotelsAndItems managingSystem;

    Hotels haldiram("Haldiram");
    haldiram.addMenuItem("Roti", 10);
    haldiram.addMenuItem("Rice", 15);
    haldiram.addMenuItem("Panner", 120);
    haldiram.addMenuItem("Cake", 220);

    Hotels wowChinese("WowChinese");
    wowChinese.addMenuItem("Chicken Noodles", 120);
    wowChinese.addMenuItem("Chicken Rice", 120);
    wowChinese.addMenuItem("Chilli Chicken", 220);

    // Adding Hotels in Circular linked list
    managingSystem.addHotels(haldiram);
    managingSystem.addHotels(wowChinese);

    // adding customer
    CustomerOrder co(custname, mobile, custAddress);
    cout << endl;
    co.PlaceOrder(managingSystem);

    // managingSystem.display();

    return 0;
}
