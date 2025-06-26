#include<iostream>
#include<string>
using namespace std;
bool isInteger(string s){
    if(s.empty()) return false;
    int i =0;
    if(s[i] =='+' || s[i]=='-')
    i++;
    if(i == s.length()) return false;
    for(;i<s.length();i++){
        if(!isdigit(s[i]))
        return false;
    }
    return true;

    }
    bool isDecimal(string s){
        if(s.empty()) return false;
        int i =0;
        if(s[i] =='+' || s[i]=='-')
    i++;
    bool dotseen = false,digitseen = false;
    for(;i<s.length();i++){
        if(isdigit(s[i])) digitseen =true ;
        else if (s[i]=='.')
        {
            if(dotseen) return false;
            dotseen = true;
        }
        else {
            return false;
        }
        

    }
    return digitseen;
    
    }
    bool isNumber(string s){
        int start =0,end =s.size()-1;
        while(start<=end && s[start] == ' ') start++;
        while(end>=start && s[end]== ' ') end--;
        if(start>end) return false;
        s = s.substr(start,end-start+1);
        size_t epos = s.find_first_of("eE");
        if(epos != string::npos){
            string base = s.substr(0,epos);
            string exponent = s.substr(epos+1);
             if (base.empty() || exponent.empty()) return false;

            return (isInteger(base) || isDecimal(base)) && isInteger(exponent);
        } else {
            return isInteger(s) || isDecimal(s);
        }
    }
   
    

int main(){
    string s ;
    cout<<"Enter the string"<<endl;
    cin>>s;
    bool ans = isNumber(s)  ;
    if(ans){
        cout<<"Valid number"<<endl;
    }
    else
    cout<<"not valid"<<endl;

}
