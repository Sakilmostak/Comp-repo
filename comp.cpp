#include<bits/stdc++.h>

using namespace std;

int puzzle[18][18]={0};
int path[18][18]={0};

void ratRoute(int n, int x, int y){
    if(x==-1 || x==n || y==-1 || y==n){
        return;
    }
    if(x== n-1 && y==n-1){
        path[x][y]=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<path[i][j]<<" ";
            }
        }
        cout<<endl;
        path[x][y]=0;
        return;
    }

    if(puzzle[x][y]==0){
        return;
    }
    else{
        if(path[x][y]==0){
            path[x][y]=1;

            ratRoute(n, x-1,y);
            ratRoute(n,x+1,y);
            ratRoute(n,x,y-1);
            ratRoute(n,x,y+1);
            path[x][y]=0;
        }
        
    }

    return;
}

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int x;
            cin>>x;
            puzzle[i][j]=x;
        }
    }

    ratRoute(n,0,0);

    
}