#include<iostream>
using namespace std;
class Queue{
    private:
    static const int size=5;
    int array[size];
    int front;
    int rear;
    public:
    Queue(){
        front=-1;
        rear=-1;
    }
    void enqueue(int value){
        if(rear==size-1){
            cout<<"Queue is full... Enqueue not possible...\n";
            return;
        }
        if(front==-1){
            front=0;} 
            rear++;
            array[rear]=value;
            cout<<"Enqueue Successfull...\n";
    }
    void dequeue(){
        if(front==-1 && rear==-1){
            cout<<"Queue is Empty...Nothing to delete...\n";
        }
            cout<<"Deleted: "<<array[front];
        if(front==rear){
            front=rear=-1;
        }
        else front++;
    }
    void traverse(){
        if(front==-1 && rear==-1){
            cout<<"Queue is Empty...\n";
        }else{
            for(int i=front; i<=rear; i++){
                cout<<array[i]<<" ";
            }
        }
    }
};
int main(){
    Queue q;
    int choice, value;
    while(true){
        cout<<"\n   Main Menu: \n";
        cout<<"1. Enqueue\n";
        cout<<"2. Dequeue\n";
        cout<<"3. Traverse\n";
        cout<<"4. Exit\n";
        cout<<"Enter your choice (1,2,3, or 4)\n";
        cin>>choice;
            switch(choice){
            case 1:
            cout<<"Enter value: ";
            cin>>value;
            q.enqueue(value);
            break;
        
            case 2:
            q.dequeue();
            break;
            
            case 3:
            q.traverse();
            break;

            case 4:
            return 0;
            
            default:
            cout<<" Invalid choice \n";
        }
    }
    return 0;
}