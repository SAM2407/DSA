#include<iostream>
using namespace std;
bool linearSearch(int *arr,int size, int key){
    if(size ==0) return false;
    if(arr[0]==key) return true;
    else 
    return linearSearch(arr+1,size-1,key);
}
int main(){
    int arr[4]={1,2,3,4};
    int size =4;
    int key = 4;
    bool ans = linearSearch(arr,size,key);
    if(ans){
        cout<<"key is found"<<endl;
    }
    else {
        cout<<"key is not found in array"<<endl;
    }
}