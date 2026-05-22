#include<iostream>
using namespace std;
class Stack{
    private:
    static const int size=5;
    int stack[size];
    int top;
    public:
    Stack(){
        top=-1;
    }
    void push(int value){
        if(top==size-1){
            cout<<"Stack overflow\n";
        }else{
            cout<<value<<" added to stack\n";
            top++;
            stack[top]=value;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack underflow\n";
        }else{
            cout<<stack[top]<<" deleted\n";
            top--;
        }
    }

    void display(){
        if(top==-1){
            cout<<"Stack underflow\n";
        }else{ 
            cout<<endl; 
            cout<<"Satck: "<<endl;  
            for(int i=0; i<top; i++){
                cout<<stack[i]<<endl;
            }
            cout<<endl; 
        }
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.display();
    s.push(40);
    s.push(50);
    s.display();
    s.pop();
    s.display();
    return 0;
}