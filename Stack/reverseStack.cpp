#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void printStack(stack<int>&s){
    stack<int>temp;
    while(!s.empty()){
        temp.push(s.top());
        s.pop();
    }
    while(!temp.empty()){
        cout << temp.top() << " ";
        s.push(temp.top());
        temp.pop();
    }
    cout << endl;
}
void insertBottom(stack<int>&s,int &target){
    //base case
    if(s.empty()){
        s.push(target);
        return;
    }
    int temp = s.top();
    s.pop();
    insertBottom(s, target);
    //backtracking step 
    s.push(temp);
}
void reverseStack(stack<int>&s){
    //base case
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverseStack(s);
    insertBottom(s, temp);
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
    cout << "Stack before reversing: ";
    printStack(s);  
    reverseStack(s);
    cout << "Stack after reversing: ";  
    printStack(s);
    return 0;
    
}