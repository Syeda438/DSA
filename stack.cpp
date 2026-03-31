//Write a program that implement stack (its operations) using Arrays.
#include<iostream>
#include<limits>
using namespace std;
class Stack{
    private:
    static const int size=5;
    int array[size];
    int top;
    public:
    Stack(){top=-1;}
    
    void push(int value){
        if(top==size-1){
            cout<<"Can't insert. Stack is full. Stack Overflow.\n";
    }else{
        top++;
        array[top]=value;
        cout<<value<<" is successfully inserted into Stack.\n";
    }
}

void pop(){
    if(top==-1){
        cout<<"Can't delete. Stack is empty. Stack Underflow.\n";
    }else{
        cout<<array[top]<<" is successfully deleted from the Stack.\n";
        top--;
    }
}

void peek(){
    if(top==-1){
        cout<<"Nothing to see here. Stack is empty.\n";
    }else{
        cout<<array[top]<<" is the top element of the stack.\n";
    }
}

void traverse(){
    if(top==-1){
        cout<<"Nothing to see here. Stack is empty.\n";
    }else{
        for(int i=top; i>=0; i--){
            cout<<"  "<<array[i]<<endl;
        }
    }
}
};

int main(){
    Stack s;
    int choice, value;
    while(true){
        cout<<"   Main Menu: \n";
        cout<<"1. Insertion\n";
        cout<<"2. Deletion\n";
        cout<<"3. Peek\n";
        cout<<"4. Traverse\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice (1,2,3,4,5)\n";
        cin>>choice;
            if(cin.fail()){
                cin.clear();  // reset error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard bad input
                cout<<"Invalid input. Please enter a number between 1 and 5.\n";
               continue;
            }
            if(choice < 1 || choice > 5){
                cout<<"Invalid choice. Enter number between 1 and 5.\n";
                continue;
            }

            switch(choice){
            case 1:
            cout<<"Enter value: ";
            cin>>value;
            s.push(value);
            break;
        
            case 2:
            s.pop();
            break;
            
            case 3:
            s.peek();
            break;
            
            case 4:
            s.traverse();
            break;

            case 5:
            return 0;
            
            default:
            cout<<" Invalid choice \n";
        }
    }
    return 0;
}

