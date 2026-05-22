#include<iostream>
using namespace std;
int partition(int array[],int start, int end){
    int pivot=array[end];
    int i=start-1;
    for(int j=start; j<end; j++){
        if(array[j]<=pivot){
            i++;
            swap(array[j],array[i]);
        }
    }
    i++;
    swap(array[i],array[end]);
    return i;
}
void quick(int array[], int start, int end){
    if(start<end){
        int pivot=partition(array, start, end);
        quick(array,start,pivot-1);
        quick(array,pivot+1,end);
    }
}
void display(int array[], int size){
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int size=15;
    int array[size]={7,8,6,5,0,6,4,3,1,6,2,6,8,1,4};
    cout<<"Before quick sort: ";
    display(array, size);
    quick(array,0,size-1);
    cout<<"After quick sort: ";
    display(array, size);
}