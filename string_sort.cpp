#include<iostream>
#include<limits>
using namespace std;
int main(){
    string array[10]={"Karachi","Lahore","Multan","Karachi","Islamabad","Quetta","Peshawar","Khanewal","Quetta","Sargodha"};
    for(int i=0;i<10;i++){
        cout<<array[i]<<"  ";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<i;j++){
            if((size<string>(array[i]))<(size<string>(array[j]))){
                swap(array[i],array[j]);
            }
        }
        
}
    for(int i=0;i<10;i++){
        cout<<array[i]<<"  ";
    }
return 0;
}