#include<iostream>
using namespace std;
void insertion(int arr[], int size){
    for(int i=1; i<size; i++){
        int key=arr[i];
        int j=i-1;
        while(j>=0 && arr[j]>=key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
    }
    void display(int arr[], int size){
        for(int i=0; i<size; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
int main(){
    int n=10;
    int array[n]={5,8,3,9,5,0,1,3,5,6};
    cout<<"Before insertion sort: ";
    display(array,n);
    insertion(array,n);
    cout<<"After insertion sort:  ";
    display(array,n);
    return 0;
}