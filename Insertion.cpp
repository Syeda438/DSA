#include<iostream>
using namespace std;
void display(int num, int array[]){
    cout<<"Displaying: ";
    for(int i=0;i<num;i++){
        cout<<array[i]<<"  ";
    }
    cout<<endl;
}
void insertion_sort(int num, int array[]){
    for(int i=1;i<num;i++){
        int key=array[i];
        int j=i-1;
        while(j>=0 && array[j]>key){
            array[j+1]=array[j];
            j=j-1;
        }
        array[j+1]=key;
    }
}
int main(){
    int arr[100];
    int n;
    cout<<"Enter the Number of Elemnets: ";
    cin>>n;
    cout<<"Enter the Elements: \n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before Insertion Sort:  \n";
    display(n,arr);
    insertion_sort(n,arr);
    cout<<"After Insertion Sort:  \n";
    display(n,arr);
    cout<<endl;
    return 0;
}