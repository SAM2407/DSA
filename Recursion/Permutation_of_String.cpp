#include<iostream>
#include<string>
using namespace std;
void printPermutation(string &s,int i){
    if(i>=s.length()) //base case 
    {
        cout<< s <<" ";
        return;
    }
    for(int j =i;j<s.length();j++){
        swap(s[i],s[j]);
        printPermutation(s,i+1);
        swap(s[i],s[j]);
    }
}
int main(){
    string s ;
    cout<<"Enter the string for permutation"<<endl;
    cin>>s;
    int i =0;
    printPermutation(s,i);
    return 0;

}
