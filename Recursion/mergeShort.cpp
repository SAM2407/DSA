#include<iostream>
using namespace std;
void merge(int *arr,int s,int e){
    int mid = (s+e)/2;
    int len1 = mid-s+1;
    int len2 =e-mid;
    int *first = new int[len1];//dynamic memory allocation
    int *second = new int[len2];
    //copy values in new array
    int mainArrIndex = s;
    for(int i =0;i<len1;i++){
        first[i]= arr[mainArrIndex++];
    }
    mainArrIndex = mid+1;
    for(int i =0;i<len2;i++){
        second[i]= arr[mainArrIndex++];
    }
//merge two sorted array concept is used 
 int idx1 = 0;
 int idx2 = 0;
 mainArrIndex=s;
 while(idx1<len1 && idx2 <len2){
    if(first[idx1]<second[idx2]){
        arr[mainArrIndex++] = first[idx1++];
    }
    else{
        arr[mainArrIndex++] = second[idx2++];
    }

 }
 while (idx1<len1)
 {
   arr[mainArrIndex++] = first[idx1++];
 }
 while(idx2<len2){
    arr[mainArrIndex++] = second[idx2++];
 }
  delete [] first;
  delete [] second;

}
void mergeShort(int *arr,int s,int e){
    if(s>=e) return ;
    int mid = (s+e)/2;
    //for lefr part merging 
    mergeShort(arr,mid+1,e);
    //for right part merging and shorting 
    mergeShort(arr,s,mid);
    merge(arr,s,e);
}
int main(){
    int arr[6]={22,2,45,33,78,1};
    int size = 6;
    mergeShort(arr,0,5);
    for(int i =0;i<size;i++){
        cout<<arr[i]<<endl;
    }
}