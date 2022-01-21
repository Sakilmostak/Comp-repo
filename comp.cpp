#include<cstring>
#include <iostream>
#include <vector>
using namespace std;
bool valid(int x,int y,int n,int m){
    return (x>=0&&x<n&&y>=0&&y<m); 
}
bool helper(vector<vector<char>> &board,vector<vector<bool>> &used,string &s,int x,int y,int index, int n,int m) {
    if(index==11) return true;
    used[x][y]=true;
    bool found=false;
    int a[8][2]={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{+1,-0},{1,1}};
             for(int i=0;i<8;i++){
                 int newx=x+a[i][0];
                int newy=y+a[i][1];
                 if(valid(newx,newy,n,m)&&board[newx][newy]==s[index]&&!used[newx][newy]){
                    found=found|helper(board,used,s,newx,newy,index+1,n,m);
                 }}
    used[x][y]=false;
    return found;
}
bool hasPath(vector<vector<char>> &board, int n, int m) {
    bool found=false;
    string s="CODINGNINJA";
    vector<vector<bool>> used(n,vector<bool>(m,false));
    int i,j;
    for(i=0;i<n;i++){
     for(j=0;j<m;j++){
         if(board[i][j]==s[0]){
             found=helper(board,used,s,i,j,1,n,m);
             if(found) break;
         }
     } if(found) break;
    } return found;
}


int main() {
    int t;cin>>t;
    while(t--){
    int n, m;
    cin >> n >> m;

    vector<vector<char>> board(n, vector<char>(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> board[i][j];
        }
    }

    cout << (hasPath(board, n, m) ? 1 : 0)<<endl;}
}