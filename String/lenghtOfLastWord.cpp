#include<iostream>
#include<string>
using namespace std;
int main(){
    string s = "hello world";
    int i =0;
    int count =0;
    int n = s.length();
  while(n>=0 && s[n]==' '){
      n--;
  }
     for(int i=n-1;i>=0;i--){
        if(s[i] == ' ') {
          break;
        }
        else{
            count++;
        }
    }
     cout<<count;
}
