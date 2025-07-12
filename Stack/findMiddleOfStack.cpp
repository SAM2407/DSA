#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void middleStack(stack<int>&s,int n){
    int middle = n/2+1;
    //base condition 
    if(s.size() == middle){
        cout<<"the middle of stack is - "<<s.top()<<endl;
        return;
    }
    int temp = s.top();
    s.pop();
    middleStack(s, n);
    s.push(temp);
}
int main(){
    stack<int>s;
    int n, x;
    cout << "Enter the number of elements in the stack: ";
    cin >> n;   
    cout << "Enter the elements of the stack: ";
    for(int i = 0; i < n; i++){
        cin >> x;
        s.push(x);
    }
    middleStack(s, n);
    return 0;

}