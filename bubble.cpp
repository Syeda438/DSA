#include<iostream>
using namespace std;
void bubble(int array[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
}
void display(int array[], int n){
    for(int i=0; i<n; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size=10;
    int arr[size]={6,0,2,9,1,5,8,4,3,7};
    cout<<"Before Bubble Sort: ";
    display(arr, size);
    bubble(arr, size);
    cout<<"After Bubble Sort: ";
    display(arr, size);
    return 0;
}