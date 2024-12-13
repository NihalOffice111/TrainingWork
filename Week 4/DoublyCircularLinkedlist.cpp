#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
    }
};

class DoublyCircularLinkedList
{
public:
    Node *head;
    DoublyCircularLinkedList()
    {
        head = nullptr;
    }

    void insertAtBegin(int data)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *tail = head->prev;
            newnode->next = head;
            newnode->prev = tail;
            head->prev = newnode;
            tail->next = newnode;
            head = newnode;
        }
        cout << "Node Added At Begin" << endl;
    }

    void insertAtEnd(int data)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            head->next = head;
            head->prev = head;
        }
        else
        {
            Node *tail = head->prev;
            newnode->prev = tail;
            newnode->next = head;
            tail->next = newnode;
            head->prev = newnode;
        }
        cout << "Node inserted At End " << endl;
    }

    void insertAtPosition(int pos, int data)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            head->next = head;
            head->prev = head;
        }
        int i = 0;
        Node* temp = head;
        while (i < pos - 1)
        {
            temp = temp->next;

            i++;
        }
        
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        newnode->next->prev = newnode;
        cout << "Node Inserted At Position " << endl;
    }

    void deleteFromBegin(){
        if(head == NULL){
            cout<<"Linked List is empty "<<endl;
        }
        else{
            Node* tail = head->prev;
            Node*temp = head;
            head = head->next;
            head->prev = tail;
            tail->next = head;
            delete temp;
        }
        cout<<"Node Deleted From Front "<<endl;
    }

    void deleteFromEnd(){
        if(head == NULL){
            cout<<"Linked List is Empty "<<endl;
        }
        else{
            Node *temp = head->prev;
            Node *tail = temp->prev;
            tail->next = temp->next;
            head->prev = tail;
            
            delete temp;
        }
        cout<<"Node Deleted At End "<<endl;
    }

    void deleteAtPosition(int pos){
        if(head == NULL){
            cout<<"Linked list is Empty "<<endl;
        }
        else{
            int i = 0 ;
            Node* temp = head;
            while( i < pos){
                i++;
                temp = temp->next;
            }

            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            
        }
        cout<<"Node Deleted At Given Position "<<endl;


    }

    void display()
    {
        Node *temp = head;
        do
        {
            cout << temp->data << " <==> ";
            temp = temp->next;
        } while (temp != head);
        cout << head->data << endl;
    }
};
int main()
{
    int ch;
    int data;
    char choice;
    int pos;
    DoublyCircularLinkedList DCLL;

    cout << "********************Main Menu***************************" << endl;
    cout << "1. INSERT AT BEGIN " << endl;
    cout << "2. INSERT AT END " << endl;
    cout << "3. INSERT AT POSITION " << endl;
    cout << "4. DELETE FROM FRONT "<<endl;
    cout << "5. DELETE FROM REAR "<<endl;
    cout << "6. DELETE AT POSITION "<<endl;
    cout << "7. DISPLAY " << endl;

    do
    {
        cout << "Enter the choice from main menu " << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the data you want to Insert At begin " << endl;
            cin >> data;
            DCLL.insertAtBegin(data);
            break;

        case 2:
            cout << "Enter the data you want to insert At End " << endl;
            cin >> data;
            DCLL.insertAtEnd(data);
            break;

        case 3:
            cout << "Enter the position and data where you want to insert Node " << endl;
            cin >> pos >> data;
            DCLL.insertAtPosition(pos, data);
            break;

        case 4:
            DCLL.deleteFromBegin();
            break;

        case 5:
            DCLL.deleteFromEnd();
            break;

        case 6:
            cout<<"Enter the Position Where you want to delete "<<endl;
            cin>>pos;
            DCLL.deleteAtPosition(pos);
            break;

        case 7:
            DCLL.display();
            break;
        }
        cout << "Do you want to continue " << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}