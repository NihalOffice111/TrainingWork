#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    string data;
    Node *next;

    Node(string data)
    {
        this->data = data;
    }
};

class CircularLinkedList
{
public:
    Node *head;

    CircularLinkedList()
    {
        head = nullptr;
    }

    void defaultStoringLights(string data)
    {
        Node *newnode = new Node(data);
        if (head == nullptr)
        {
            head = newnode;
            newnode->next = head;
        }
        else
        {
            Node *temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->next = head;
        }
    }
    void signals(int timers)
    {
        ifRedSignal(timers);
    }

    void ifRedSignal(int timers)
    {
        Node *temp = head;
        do
        {
            if (temp->data == "RED")
            {
                timers--;
            }
        } while (timers != 0);
        temp = temp->next;
        cout << temp->data << "! You can go now " << endl;
        ifGreenSignal(25,temp);
    }

    void ifGreenSignal(int timers,Node* temp)
    {
        Node* temp2 = temp;
        do{
            if(temp2->data == "GREEN"){
                timers--;
            }
        }while(timers != 0);
        temp2 = temp2->next;
        cout<<temp2->data<<" !You Need to Slow Down "<<endl;
        ifYellowSignal(3,temp2);
    }

    void ifYellowSignal(int timers , Node* temp2){
        Node* temp3 = temp2;
        do{
            if(temp3->data == "YELLOW"){
                timers--;
            }
        }while(timers!=0);
        temp3 = temp3->next;
        cout<<temp3->data<<" ! You Need to Stop "<<endl;
        
    }


    void display()
    {
        Node *temp = head;
        do
        {
            cout << temp->data << "=>";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }
};

int main()
{
    map<Node *, int> mp;

    CircularLinkedList CLL;
    CLL.defaultStoringLights("RED");
    CLL.defaultStoringLights("GREEN");
    CLL.defaultStoringLights("YELLOW");

    CLL.signals(60);
   // CLL.display();
    return 0;
}