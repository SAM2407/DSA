#include<iostream>
#include<vector>
using namespace std;
bool isSafe(int x,int y,int row,int col,int maze[][3],vector<vector<bool>>&visited){

    if(((x>=0 && x<row)&& (y>=0 && y<col)) && (maze[x][y]==1) && (visited[x][y] == false)){
        return true;
    }
    else{
        return false;
    }
}
void solvemaze(int maze[3][3],int row,int col,int x,int y, vector<vector<bool>>&visited,vector<string>&path,string output){
    //base case
    if(x == row-1 && y == col-1){
        //answer
        path.push_back(output);
        return;
    }
    //for going downwards in maze
        if(isSafe(x+1,y,row,col,maze,visited)){
            visited[x+1][y] = true;
            solvemaze(maze,row,col,x+1,y,visited,path,output+'D');
            visited[x+1][y] = false;
        }
    //for going Right side  in maze
        if(isSafe(x,y+1,row,col,maze,visited)){
            visited[x][y+1] = true;
            solvemaze(maze,row,col,x,y+1,visited,path,output+'R');
            visited[x][y+1] = false;
        }
    //for going left side  in maze
        if(isSafe(x,y-1,row,col,maze,visited)){
            visited[x][y-1] = true;
            solvemaze(maze,row,col,x+1,y,visited,path,output+'L');
            visited[x][y-1] = false;
        }
    //for going upward in maze
        if(isSafe(x-1,y,row,col,maze,visited)){
            visited[x-1][y] = true;
            solvemaze(maze,row,col,x+1,y,visited,path,output+'U');
            visited[x-1][y] = false;
        }
}
int main(){
    int maze[][3] = { {0,0,0},{ 1,1,0},{1,1,1}};
    int row =3,col = 3;
    if(maze[0][0]==0){
        cout<<"No Path exists"<<endl;
        return 0;
    }
    vector<vector<bool>>visited(row,vector<bool>(col,false));
     visited[0][0] = true;
     vector<string>path;
     string output = "";
     solvemaze(maze,row,col,0,0,visited,path,output);
     cout<<"printing the results"<<endl;
     for(auto i :path){
        cout<<i<<" ";
     }
     cout<<endl;
     if(path.size()==0){
        cout<<"No Path Exists"<<endl;
     }
    return  0;
}