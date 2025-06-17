#include<iostream>
using namespace std;
int fact(int n){
    if (n==0) return 1;
    int a = fact(n-1);
    int ans = n*a;
    return ans;
}
int main(){
    int n;
    cout<<"Enter the number for finding factorial"<<endl;
    cin>>n;
    int ans = fact(n);
    cout<<ans <<endl;
    return 0;
}