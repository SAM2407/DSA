//stack using array
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class MyStack{
    int *arr;
    int top;
    int size;
public:
    MyStack(int size)
    {
        this->size = size;
        this->top = -1;
        arr = new int [size];
    }
    void push(int data){
        if(top == size-1){
            cout<<"stack is full "<<endl;
            return;
        }
        arr[++top]= data;
    }
    void pop(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return ;
        }
        top--;
     
    }
    void peek(){
        if(top ==-1){
            cout<<"Stack is empty"<<endl;
            return ;
        }
        cout<<arr[top]<<endl;
    }   
    void display(){
        if(top == -1){
            cout<<"Stack is empty"<<endl;
            return ;
        }
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    MyStack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    s.peek();
    s.pop();
    s.display();
    s.peek();
    return 0;
}
