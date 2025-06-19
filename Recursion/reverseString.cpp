#include<iostream>
using namespace std;

void reverse(string &name,int i,int j){
    if(i>j) return ;
    swap(name[i],name[j]);
    i++;
    j--;
      reverse(name,i,j);


}
int main(){
    string name ="samman"; 
    int i = 0;
    int j = name.length()-1;
     
    cout<<" Reverse is = "<<endl;
     reverse(name,i,j);
     cout<<name<<endl;
}