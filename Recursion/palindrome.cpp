#include<iostream>
using namespace std;
bool isPalindrome(string& name,int s,int e){
    if(s>e) return true;
    if(name[s]!=name[e]) return false;
    isPalindrome(name,s+1,e-1);
}
int main(){
    string name = "acbbca";
    bool ans = isPalindrome(name,0,name.length()-1);
    if(ans){
        cout<<"true"<<endl;

    }
    else{
        cout<<"False";
    }

}