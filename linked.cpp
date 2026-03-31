#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
int main(){
    Node* head = new Node();
    head->data = 10;
    head->next = NULL;
    cout<< "Data in node: "<<head->data;
    return 0;
}