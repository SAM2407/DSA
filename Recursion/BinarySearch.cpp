#include<iostream>
using namespace std;
bool binarySearch(int *arr,int s,int e,int key){
    if(s>e) return false;
    int mid = s+(e-s)/2;
    if(arr[mid]== key) return true;
    if(arr[mid]<key){
        return binarySearch(arr,mid+1,e,key);
    }
    else{
        return binarySearch(arr,s,mid-1,key);
    }
}
int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    int s = arr[0];
    int e = arr[size-1];
    int key = 10;
    bool ans = binarySearch(arr,s,e,key);
    if(ans){
        cout<<key <<" " <<"is found in array"<<endl;
    }
    else{
        cout<<key<<" " <<"is not found in array"<<endl;
    }
}