#include<iostream>
using namespace std;
void binary_search(int arr[],int n,int key){
    int start=0;
    int end = n-1;
    int mid;
    while(start<=end){
        mid = start+(end-start)/2;
        if(arr[mid] == key){
            printf("%d is found in the array",key);
            return;
        }
        else if (arr[mid]>key){
            end  = mid-1;
        }
        else if(arr[mid]<key){
            start  = mid+1;
        }
        
    }
   
        printf("%d is not found",key);
   
}
int main(){
int arr[]={1,2,3,4,5};
int key,n=5;
printf("Enter the key for searching = ");
scanf("%d",&key);
binary_search(arr,n,key);
return 0;
}
