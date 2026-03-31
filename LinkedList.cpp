//Write a program that uses functions to perform the following operations on Singly Linked List
//(i)	Creation (ii) Insertion (iii) Deletion (iv) Traversal.

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

// ---------- CREATE NODE ----------
Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    return newNode;
}

// ---------- CREATION (MULTIPLE NODES) ----------
void createList(int n)
{
    Node* temp = NULL;

    for(int i = 0; i < n; i++)
    {
        int value;
        cout << "Enter value: ";
        cin >> value;

        Node* newNode = createNode(value);

        if(head == NULL)
        {
            head = newNode;
            temp = newNode;
        }
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
    }
}

// ---------- INSERT AT BEGINNING ----------
void insertAtBeginning(int value)
{
    Node* newNode = createNode(value);

    newNode->next = head;
    head = newNode;
}

// ---------- INSERT AT END ----------
void insertAtEnd(int value)
{
    Node* newNode = createNode(value);

    if(head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

// ---------- INSERT AT POSITION ----------
void insertAtPosition(int value, int pos)
{
    Node* newNode = createNode(value);

    if(pos == 1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos - 1; i++)
    {
        if(temp == NULL)
        {
            cout << "Invalid position\n";
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// ---------- DELETE FROM BEGINNING ----------
void deleteFromBeginning()
{
    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
}

// ---------- DELETE FROM END ----------
void deleteFromEnd()
{
    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if(head->next == NULL)
    {
        delete head;
        head = NULL;
        return;
    }

    Node* temp = head;

    while(temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;
}

// ---------- DELETE FROM POSITION ----------
void deleteFromPosition(int pos)
{
    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    if(pos == 1)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos - 1; i++)
    {
        if(temp->next == NULL)
        {
            cout << "Invalid position\n";
            return;
        }
        temp = temp->next;
    }

    Node* delNode = temp->next;

    if(delNode == NULL)
    {
        cout << "Invalid position\n";
        return;
    }

    temp->next = delNode->next;
    delete delNode;
}

// ---------- TRAVERSAL ----------
void traverse()
{
    if(head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// ---------- MAIN ----------
int main()
{
    int choice, value, pos, n;

    while(true)
    {
        cout << "\n1 Create List";
        cout << "\n2 Insert at Beginning";
        cout << "\n3 Insert at End";
        cout << "\n4 Insert at Position";
        cout << "\n5 Delete from Beginning";
        cout << "\n6 Delete from End";
        cout << "\n7 Delete from Position";
        cout << "\n8 Traverse";
        cout << "\n9 Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "How many nodes? ";
                cin >> n;
                createList(n);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;

            case 3:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;

            case 4:
                cout << "Enter value and position: ";
                cin >> value >> pos;
                insertAtPosition(value, pos);
                break;

            case 5:
                deleteFromBeginning();
                break;

            case 6:
                deleteFromEnd();
                break;

            case 7:
                cout << "Enter position: ";
                cin >> pos;
                deleteFromPosition(pos);
                break;

            case 8:
                traverse();
                break;

            case 9:
                return 0;

            default:
                cout << "Invalid choice\n";
        }
    }
}