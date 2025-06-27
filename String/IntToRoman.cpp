#include<iostream>
#include<string>
using namespace std;
string  convert(int num){
    string ans = "";
 string Roman[]={"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
 int values[]={1000,900,500,400,100,90,50,40,10,9,5,4,1};
 for(int i =0;i<13;i++){
    while(num>=values[i]){
        ans = ans+Roman[i];
        num = num-values[i];
    }
 }
 return ans;
}
int main(){
    int num;
    cout<<"Enter the numbr for conversion"<<endl;
    cin>>num;
   string s =  convert(num);
   cout<<s<<endl;
}