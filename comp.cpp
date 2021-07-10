#include<bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> &board, int row, int column, int key){
    for(int i=0;i<9;i++){
        if(board[row][i]==key){
            return false;
        }

        if(board[i][column]==key){
            return false;
        }

        if(board[3*(row/3)+(i/3)][3*(column/3)+(i%3)]==key){
            return false;
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>> &board){
    for (int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                for(int k=1;k<=9;k++){
                    if(isValid(board,i,j,k)){
                        board[i][j]=k;

                        if(solveSudoku(board)){
                            return true;
                        }
                        else{
                            board[i][j]=0;
                            return false;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}


int main(){

    vector<vector<int>> board 
       { { 3, 1, 6, 5, 7, 8, 4, 9, 2 },
         { 5, 2, 9, 1, 3, 4, 7, 6, 8 },
         { 4, 8, 7, 6, 2, 9, 5, 3, 1 },
         { 2, 6, 3, 0, 1, 5, 9, 8, 7 },
         { 9, 7, 4, 8, 6, 0, 1, 2, 5 },
         { 8, 5, 1, 7, 9, 2, 6, 4, 3 },
         { 1, 3, 8, 0, 4, 7, 2, 0, 6 },
         { 6, 9, 2, 3, 5, 1, 8, 7, 4 },
         { 7, 4, 5, 0, 8, 6, 3, 1, 0 } };

    if(solveSudoku(board)){

        for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
        }
    }
    

    return 0;
    
}