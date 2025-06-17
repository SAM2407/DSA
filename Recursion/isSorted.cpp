#include<iostream>
using namespace std;
bool isSorted(int *arr,int size){
    if(size ==0 ||size ==1) return true;
    if(arr[0]>arr[1]) return false;
    else{
     return isSorted(arr+1,size-1);
    
    }
    
}
int main(){
    int arr[6]={1,3,5,7,9,45};
    int size = 6;
     bool ans = isSorted(arr,6);
    if(ans){
        cout<<"arr is sorted"<<endl;
    }
    else{
        cout<<"arr is not  sorted"<<endl;
    }
}