#include<iostream>
using namespace std;
class Queue{
    private:
    int front;
    int rear;
    static const int size=5;
    int queue[size];
    public:
    Queue(){
        front=-1;
        rear=-1;
    }
    void enqueue(int value){
        if(rear==size-1){
            cout<<"Queue Overflow\n";
        }else{
            if(front==-1){
            front=0;}
            rear++;
            queue[rear]=value;
            cout<<queue[rear]<<" inserted\n";
        }
    }
    void dequeue(){
        if(front==-1){
            cout<<"Queue underflow\n";
        }else{
            cout<<queue[front]<<" deleted\n";
            front++;
            if(front>rear){
                front=rear=-1;
            }
        }
    }
    void display(){
        if(front==-1){
            cout<<"Queue underflow\n";
        }else{
            cout<<"Queue: "<<endl;
            for(int i=front; i<=rear; i++){
                cout<<queue[i]<<" ";
            }
            cout<<endl;
            cout<<endl;
        }
    }
};
int main(){
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    q.dequeue();
    q.enqueue(30);
    q.dequeue();
    q.enqueue(40);
    q.display();
    q.dequeue();
    q.enqueue(50);
    q.display();
    return 0;
}