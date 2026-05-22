#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
    };
    Node* head=NULL;
    Node* create(int value){
        Node* temp=new Node;
        temp->data=value;
        temp->next=NULL;
        return temp;
    }
    void instart(int value){
        if(head==NULL){
            Node* temp=create(value);
            head=temp;
        }
        else if(head!=NULL){
            Node* temp=create(value);
            temp->next=head;
            head=temp;
        }
    }
    void atend(int value){
        if(head==NULL){
            Node* temp=create(value);
            head=temp;
        }
        else if(head!=NULL){
            Node* temp=create(value);
            while(temp->next!=NULL){
                temp=temp->next;
                temp->next=NULL;

            }
        }
    }