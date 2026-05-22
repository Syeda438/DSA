#include <iostream>
using namespace std;
void merge(int array[], int left, int mid, int right){
    int n1=mid-left+1;
    int n2=right-mid;
    int L[n1],R[n2];
    for(int i=0; i<n1; i++){
        L[i]=array[left+i];
    }
    for(int j=0; j<n2; j++){
        R[j]=array[mid+j+1];
    }
    int i=0, j=0, k=left;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            array[k]=L[i];
            i++;
        }else{
            array[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        array[k++]=L[i++];
    }
    while(j<n2){
        array[k++]=R[j++];
    }
}
void mergesort(int array[], int left, int right){
    if(left<right){
        int mid=(left+right)/2;
        mergesort(array,left,mid);
        mergesort(array,mid+1,right);
        merge(array,left,mid,right);
    }
}
int main(){
    int size;
    cout<<"enter the size of array: ";
    cin>>size;
    cout<<"enter the elements: ";
    int* array=new int[size];
    for(int i=0; i<size; i++){
        cin>>array[i];
    }
    cout<<endl;
    mergesort(array,0,size-1);
    cout<<"Sorted array: ";
    for(int i=0; i<size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    delete[] array;
    return 0;
}