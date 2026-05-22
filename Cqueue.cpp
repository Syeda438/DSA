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
        if((front==0&&rear==size-1)||((rear+1)%size==front)){
            cout<<"Queue Overflow...\n";
            return;
        }
        if(front==-1){
            front=0;
            rear=0;
        }else{
            rear= (rear+1) % size;
        }
            array[rear]=value;
            cout<<"Successfull Enqueue...\n";
    }
    void dequeue(){
        if(front==-1){
            cout<<"Queue is Empty (Underflow)...\n";
        }
        if(front == rear){
            front=-1;
            rear=-1;
        }else{
            front = (front+1)%size;
        }
    }
    void traverse(){
        if(front==-1){
            cout<<"Queue is Empty...\n";
            return;
        }
        int i=front;
        while(i!=(rear+1) % size){
            cout<<array[i]<<" ";
            if(i==rear){
                break;
            }
            i=(i+1)% size;
        }
        cout<<endl;
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