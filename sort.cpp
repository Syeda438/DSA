//Selection Sort ...🤦🏼‍♀️🤦🏼‍♀️🤦🏼‍♀️
#include<iostream>
using namespace std;
void selection(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int min=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(arr[i],arr[min]);
        }
    }
}
void display(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size;
    cout<<"Enter the number of elements: ";
    cin>>size;
    int array[100];
    for(int i=0; i<size; i++){
        cin>>array[i];
    }
    cout<<endl;
    cout<<"Before Sorting: ";
    display(array, size);
    selection(array, size);
    cout<<" After Sorting: ";
    display(array, size);
    return 0;
}
