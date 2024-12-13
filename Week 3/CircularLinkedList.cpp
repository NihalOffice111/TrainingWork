#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
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

    void insertAtBegin(int data)
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
            newnode->next = head;
            temp->next = newnode;
            head = newnode;
        }
    }

    void insertAtEnd(int data)
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

    void insertAtPosition(int pos, int data)
    {
        // int n = sizeOfLinkedList(head);
        Node *newnode = new Node(data);
        // if(pos > n){
        //     return;
        // }

        Node *temp = head;
        int i = 0;
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    int sizeOfLinkedList(Node *head)
    {
        Node *temp = head;
        int count = 0;
        while (temp != head)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void deleteAtBegin()
    {
        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
            return;
        }

        Node *temp = head;
        Node *temp2 = head;
        while (temp2->next != head)
        {
            temp2 = temp2->next;
        }

        head = head->next;
        temp2->next = head;
        delete temp;
    }

    void deleteAtEnd()
    {

        if (head == nullptr)
        {
            cout << "Linked List is Empty" << endl;
            return;
        }
        Node *temp;
        Node *temp2 = head;
        while (temp2->next != head && temp2->next->next != head)
        {
            temp2 = temp2->next;
        }

        temp = temp2->next;
        temp2->next = head;
        delete temp;
    }

    void deleteByData(int data)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp->next != head)
        {
            if (temp->data == data)
            {
                if (prev != nullptr)
                {
                    prev->next = temp->next;
                }
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
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
    int ch;
    int data;
    char choice;
    CircularLinkedList CLL;
    cout << "****Main Menu***" << endl;
    cout << "1. Insert At Begin " << endl;
    cout << "2. Insert At End " << endl;
    cout << "3. Insert At Position " << endl;
    cout << "4. Delete At Begin " << endl;
    cout << "5. Delete At End " << endl;
    cout << "6. Delete By Data " << endl;
    cout << "7. Display " << endl;

    do
    {
        cout << "Enter the choice from the Main menu" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the data you want to insert At bEgin " << endl;
            cin >> data;
            CLL.insertAtBegin(data);
            break;

        case 2:
            cout << "Enter the data you want to insert At End " << endl;
            cin >> data;
            CLL.insertAtEnd(data);
            break;

        case 3:
            int pos;
            cout << "Enter the position and data in linkedlist to insert at position " << endl;
            cin >> pos >> data;
            CLL.insertAtPosition(pos, data);
            break;

        case 4:
            CLL.deleteAtBegin();
            break;

        case 5:
            CLL.deleteAtEnd();
            break;

        case 6:
            cout << "Enter the data you want to delete " << endl;
            cin >> data;
            CLL.deleteByData(data);
            break;

        case 7:
            CLL.display();
            break;
        }

        cout << "Do you want to continue " << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    return 0;
}