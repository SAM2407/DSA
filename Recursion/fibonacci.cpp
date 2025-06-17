#include<iostream>
using namespace std;
int fiboo(int n){
    if(n==0) return 0;
    if(n==1) return 1; 
    int ans = fiboo(n-1)+fiboo(n-2);
    // cout<<ans<<endl;
    return ans ;
}
int main(){
    int n;
    cout<<"Enter the n"<<endl;
    cin>>n;
    cout<< " 0 1 "<<fiboo(n)<<endl;
}
