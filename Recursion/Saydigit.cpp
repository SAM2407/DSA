#include<iostream>
using namespace std;
void Saydigit( string *arr,int num){
if(num == 0) return ;
int digit = num%10;
 num = num/10;
  Saydigit(arr,num);  
  cout<<arr[digit]<<" ";  

}
int main(){
    string arr[10] = { "zero","one","two","three","four","five","six","seven","eight","nine"};
    int num ;
    cout<<"Enter the number"<<endl;
    cin>>num;
    Saydigit(arr,num);
}