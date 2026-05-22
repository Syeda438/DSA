#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head = NULL;
Node* create(int value){
    Node* newNode=new Node;
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void insert_at_start(int value){
    Node* newNode= create(value);
    newNode->next=head;
    head=newNode;
}
void insert_at_end(int value){
    Node* newNode=create(value);
    if(head==NULL){
        head=newNode;
        return;
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}
void insert_at_position(int value, int position){
    Node* newNode=create(value);
    Node* temp=head;
    for(int i=1; i<position-1; i++){
        if(temp==NULL){
        cout<<"Invalid Position\n";
        return;
    }
    temp=temp->next;
    }
    newNode->next=temp->next;
    temp->next=newNode;
}
void delete_from_start(){
    Node* temp=head;
    head=head->next;
    delete temp;
}
void delete_from_end(){
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}
void traverse(){
    if(head==NULL){
        cout<<"List is Empty\n";
    }
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL\n";
}
int main(){
    int choice, value, position;
    while(true){
        cout<<"\n---MAIN MENU---\n";
        cout<<"1. Insertion at the beginning\n";
        cout<<"2. Insertion at the end\n";
        cout<<"3. Insertion at position\n";
        cout<<"4. Deletion from the beginning\n";
        cout<<"5. Deletion from the end\n";
        cout<<"6. Traverse\n";
        cout<<"7. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Insert value: ";
            cin>>value;
            insert_at_start(value);
            break;
            case 2:
            cout<<"Insert value: ";
            cin>>value;
            insert_at_end(value);
            break;
            case 3:
            cout<<"Position: ";
            cin>>position;
            cout<<"Insert value: ";
            cin>>value;
            insert_at_position(value,position);
            break;
            case 4:
            delete_from_start();
            break;
            case 5:
            delete_from_end();
            break;
            case 6:
            traverse();
            break;
            case 7:
            cout<<"Exiting...\n";
            return 0;
            default:
            cout<<"Invalid Choice...\n";
        }
    }
    return 0;
}