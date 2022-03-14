#include<bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define mod 1000000007
#define endl "\n"
using namespace std;

int** makeAMove(int** board, int x, int y, int player, int isCheck);



// found out all the possible moves from that position and save it
vector<pair<int, int>*>* possibleMoves(int** board, int player){
    vector<pair<int,int>*>* output = new vector<pair<int,int>*>();
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(board[i][j]==0){
                if(makeAMove(board,i,j,player,true)){
                    pair<int,int>* p= new pair<int,int>(i,j);
                    output->push_back(p);
                }
            }
        }
    }
    return output;
}

int evaluateBoard(int** board, bool& completed){
    // if there is still move left
    if(possibleMoves(board, 1)->size()!=0 || possibleMoves(board, 2)->size()!=0){
        completed=false;
        return 0;
    }

    // if all moves are exhausted
    completed=true;
    int count[3]={};
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            count[board[i][j]]++;
        }
    }

    return count[1]-count[2];
}

// either makes a move and returns the board or just check if move at that position is possible
int** makeAMove(int** board, int x, int y, int player, int isCheck){
    int ** newBoard;

    // if isCheck is true then set a new board
    // if isCheck is false then replicate the given board
    if(isCheck){
        newBoard=board;
    }
    else{
        newBoard=new int*[4];
        for(int i=0;i<4;i++){
            newBoard[i]=new int[4];
            for(int j=0;j<4;j++){
                newBoard[i][j]=board[i][j];
            }
        }
    }

    //making all possible direction array ie containing 8 directions
    int xDir[]= {-1,-1,0,1,1,1,0,-1};
    int yDir[]= {0,1,1,1,0,-1,-1,-1};
    //if x or y coordinate is invalid
    if(x<0 || x>=4 || y<0 || y>=4 || board[x][y]!=0){
        return NULL;
    }

    bool movePossible=false;
    for(int i=0;i<8;i++){
        int xStep=xDir[i];
        int yStep=yDir[i];
        int currentX= x+ xStep;
        int currentY= y+ yStep;
        int count=0;
        while(currentX>=0 && currentX<4 && currentY>=0 && currentY<4){
            if(newBoard[currentX][currentY]==0){
                break;
            }
            else if(newBoard[currentX][currentY]!=player){
                currentX+=xStep;
                currentY+=yStep;
                count++;
            }
            else{
                if(count>0){
                    movePossible=true;
                    if(isCheck){
                        // only return if it is possible
                        return newBoard;
                    }
                    int convertX= currentX- xStep;
                    int convertY= currentY- yStep;
                    while(convertX!=x || convertY!=y){
                        newBoard[convertX][convertY]=player;
                        convertX= convertX- xStep;
                        convertY= convertY- yStep;
                    }
                    newBoard[x][y]=player;

                }
                break;
            }
        }
    }
    if(movePossible){
        return newBoard;
    }
    else{
        return NULL;
    }


}

void printBoard(int** board){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

int findNextStep(int** board, bool maximizerTurn, int& x, int& y){
    //check if done play, if yes return score of evaluate function
    bool completed;
    int score= evaluateBoard(board, completed);
    printBoard(board);
    if(completed){
        return score;
    }

    // find all possible moves
    int player= maximizerTurn? 1: 2;  // find out the turn
    vector<pair<int,int>*>* options = possibleMoves(board, player);
    if(options->size()==0){
        x=-1;
        y=-1;
        int dummyX, dummyY;
        return findNextStep(board,!maximizerTurn, dummyX, dummyY);
    }

    // this variable contain the best possible result 
    int best;
    if(maximizerTurn){
        best=INT_MIN;
    }
    else{
        best=INT_MAX;
    }

    // for each move in the given options
    for(int i=0;i<options->size();i++){
        int currentMoveX= options->at(i)->first;
        int currentMoveY= options->at(i)->second;
        // here false in makeAMove means we are putting the effect of this move on the board
        int ** newBoard= makeAMove(board, currentMoveX, currentMoveY, player, false);

        //making recursive call to this func
        int dummyX,dummyY;
        int score = findNextStep(newBoard, !maximizerTurn, dummyX, dummyY);
        
        // update best based on who's turn it is
        if(maximizerTurn){
            best=max(best,score);
        }
        else{
            best=min(best,score);
        }

        if(best==score){
            x=currentMoveX;
            y=currentMoveY;
        }

        //Undo the move
        for(int i=0;i<4;i++){
            delete[] newBoard[i];
        }
        delete[] newBoard;

    }

    return best;
}

int main(){
    //othello board of size 4x4
    int **a= new int*[4];
    for(int i=0;i<4;i++){
        a[i]=new int[4];
        for(int j=0;j<4;j++){
            a[i][j]=0;
        }
    }

    // here 1 is maximizer player and 2 is minimizer player

    //initial condition
    a[1][1]=1;
    a[2][2]=1;
    a[1][2]=2;
    a[2][1]=2;
    int x,y;
    cout<<findNextStep(a, true, x,y)<<endl;
    cout<<x<<" "<<y<<endl;
}