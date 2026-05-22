#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }

    Node* insert_start(Node* head, int value){
        Node* newNode=new Node(value);
        newNode->next=head;
        return newNode;
    }

    Node* insert_end(Node* head, int value){
        Node* newNode=new Node(value);
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
};