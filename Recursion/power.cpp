#include<iostream>
using namespace std;
int power(int n){
    int ans;
    if( n==0) return 1;
     return 2*power(n-1);
 
}
int main(){
int n;
cout<<"Enter the n"<<":-"<<endl;
cin>>n;
cout<< power(n);
}