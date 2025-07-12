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
void insertSorted(stack<int>&s, int target){
   if(s.empty()){
    s.push(target);
    return;
   }
   if(s.top()>=target){
    s.push(target);
    return ;
   }
   int topElement = s.top();
   s.pop();
   insertSorted(s,target);
   s.push(topElement);

}
void sortStack(stack<int>&s){
    if(s.empty()){
        return;
    }
    int topElement = s.top();
    s.pop();
    sortStack(s);
    insertSorted(s,topElement);
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

    cout << "Stack before reversing: "<<endl;
    printStack(s);
    cout<<"stack after sorting"<<endl;
    sortStack(s);
    printStack(s);
    return 0;
    
   
}