#include<iostream>
#include<string>
using namespace std;
int main(){
    string s = "hello world";
    int i =0;
    int count =0;
    int n = s.length();
  for(int i =0;i<n;i++){
        if(s[n] == ' '){
            n--;}
    else break;
  }
  
     for(int i=n-1;i>=0;i--){
        if(s[i] == ' ') {
            cout<<count;
          
        }
        else{
            count++;
        }
    }
}
