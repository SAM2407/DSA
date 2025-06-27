#include<iostream>
#include<string>
using namespace std;
int getValue(char ch){
      int ans = 0;
 char Roman[]={'I','V','X','L','C','D','M'};
 int values[]={1,5,10,50,100,500,1000};
 for(int i =0;i<7;i++){
    if(Roman[i] == ch)
    return values[i];
 }
 return 0;
}
int   convert(string s){
    int ans =0;
    for(int i =0;i<s.length();i++){
        int curr = getValue(s[i]);
        int next =0;
        if(i+1<s.length()){
            next = getValue(s[i+1]);
        }
        if(curr<next){
            ans = ans-curr;
        }
        else{
            ans = ans+curr;
        }
    }
    return ans;
}
int main(){
    string s;
    cout<<"Enter the Roman numbr for conversion"<<endl;
    cin>>s;
   int   ans =  convert(s);
   cout<<ans<<endl;
}