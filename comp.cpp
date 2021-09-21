#include<bits/stdc++.h>

using namespace std;

bool checkPoint(int** sudoku, int x, int y){
    int para= sudoku[x][y];
    for(int i=0;i<9;i++){
        if(sudoku[i][y]==para && i!=x){
            return false;
        }
    }
    for(int i=0;i<9;i++){
        if(sudoku[x][i]==para && i!=y){
            return false;
        }
    }
    int br= (x/3)*3;
    int bc= (y/3)*3;
    for(int i=br;i<(br+3);i++){
        for(int j=bc;j<(bc+3);j++){
            if(i!=x || j!=y){
                if(sudoku[i][j]==para){
                    return false;
                }
            }
        }
    }

    return true;
}

bool sudokuSolver(int** sudoku);

bool feasiblity(int** sudoku, int x, int y){
    bool ans;
    for(int i=1;i<=9;i++){
        sudoku[x][y]=i;
        bool feasible= checkPoint(sudoku,x,y);

        if(feasible){
            ans=sudokuSolver(sudoku);
            if(ans){
                return ans;
            }
        }
    }

    sudoku[x][y]=0;
    return false;
}

bool sudokuSolver(int** sudoku){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(sudoku[i][j]==0){
                bool ans= feasiblity(sudoku,i,j);
                return ans;
            }
        }
    }

    return true;
}

int main(){
    int **sudoku = new int* [9];
    for(int i=0;i<9;i++){
        sudoku[i] = new int[9];
    }

    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>sudoku[i][j];
        }
    }
    bool final= sudokuSolver(sudoku);
    if(final){
        cout<<"true"<<endl;
    }
    else{
        cout<<"false"<<endl;
    }

}