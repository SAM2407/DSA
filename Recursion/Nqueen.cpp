#include<iostream>
#include<vector>
#include<string>
using namespace std;
void printSolution(vector<vector<char>>&board,int n){
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout << board[i][j] <<" ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
     
    
}
bool isSafe(int row,int col,vector<vector<char>>&board,int n){
    int i =row,j=col;
    while( j>=0){
       if( board[i][j] =='Q'){
        return false;
       }
       j--;
    }
    //for diagonally check 
    i = row,j=col;
    while(i>=0 && j>=0){
        if(board[i][j] =='Q'){
            return false;
        }
        i--;
        j--;
    }
     i = row,j=col;
     while(i<n && j>=0){
        if(board[i][j]=='Q'){
            return false;
        }
        i++;
        j--;
     }
    return true;

}
void solve(vector<vector<char>>&board,int col,int n,int &count){
      if(col>=n){
        printSolution(board,n);
        count++;
        return;
      }
      for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col] = 'Q';
                solve(board,col+1,n,count);
                 board[row][col]='-';
                 
            
                }
      }
}
int main(){
    int n =4,count =0;
    vector<vector<char>>board(n,vector<char>(n,'-'));
    int col = 0;
    solve(board,col,n,count);
    cout << "There exist " << count << " number of solutions." << endl;
}
