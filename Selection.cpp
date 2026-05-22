#include<iostream>
using namespace std;
void selection(int arr[], int size){
    for(int i=0; i<size-1; i++){
        int min=i;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[min]){
                min=j;
            }
        }
        if(min!=i){
            swap(arr[i],arr[min]);
        }
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
    int array[n]={7,0,5,4,9,2,1,8,6,3};
    cout<<"Before selection sort: ";
    display(array,n);
    cout<<"After selection sort:  ";
    selection(array,n);
    display(array,n);
    return 0;
}