#include<iostream>
#include<vector>
#include<string>
using namespace std;
 void solve( vector<string>&ans,int n ,int open,int close,string &output){
        //base case 
        if(open ==0 && close == 0){
            ans.push_back(output);
            return;
        }
        //for inlcuding the opening bracket
        if(open>0){
            output.push_back('(');
            solve(ans,n,open-1,close,output);
            output.pop_back();
        }
        //for including the closing bracket
        if(close>open){
            output.push_back(')');
            solve(ans,n,open,close-1,output);
            //bracktrack
            output.pop_back();
        }
    }
int main(){
    int n ;
    cout<<"Enter the number of parenthesis"<<endl;
    cin>>n;
    vector<string>ans;
    int open =n,close =n;
    string output = "";
    solve(ans,n,open,close,output);
     for (const string& s : ans) {
        cout << s << endl;
    }
     

}
// class Solution {
   
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string>ans;
//         string output ="";
//         int close =n,open =n;
       
//         return ans;
//     }
// };
